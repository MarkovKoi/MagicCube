#pragma once
#include "../defs/cube_state.hpp"
#include "move.hpp"
#include <vector>
#include <cstdint>
#include <algorithm>

inline bool sameFace1(uint8_t last,uint8_t cmd){
    if (last/3==cmd/3)
        return true;
    return false;
}
inline bool sameFace2(uint8_t last,uint8_t cmd){
    if (last==cmd)
        return true;
    if (last>=4 && last<=6 && cmd>=4 && cmd<=6 )
        return true;
    if (last>=7 && last<=9 && cmd>=7 && cmd<=9 )
        return true;
    return false;
}

inline uint8_t heur1(const State1& s,uint8_t sliceDist[495],
                    uint8_t eoDist[2048],uint8_t coDist[2187]){
    uint8_t h1=sliceDist[s.slice];
    uint8_t h2=eoDist[s.eo];
    uint8_t h3=coDist[s.co];
    return std::max({h1,h2,h3});
}

inline uint8_t heur2(const State2& s,
                    const std::vector<uint8_t>&cpEp4Dist,
                    const std::vector<uint8_t>&ep8Ep4Dist){
    uint8_t h1=cpEp4Dist[s.cp*24+s.ep4];
    uint8_t h2=ep8Ep4Dist[s.ep8*24+s.ep4];
    return std::max(h1,h2);
}

inline bool search1(State1&cur, uint8_t bound, std::vector<uint8_t>&solutionPath,
                uint8_t sliceDist[495],uint8_t eoDist[2048],uint8_t coDist[2187],
                uint16_t sliceMove[495][18],
                uint16_t edgesFaceMove[2048][18],
                uint16_t corsFaceMove[2187][18]){
    uint8_t h=heur1(cur,sliceDist,eoDist,coDist);
    //先写结束条件(第一阶段完成,达到G1)
    if (h==0)  return true;
    //这是启发式剪枝的关键
    if (cur.depth+h > bound)
        return false;
    //向18种操作搜索
    for (uint8_t cmd=0;cmd<18;cmd++){
        //如果是同层次操作,跳过
        if (!solutionPath.empty()){
            uint8_t last=solutionPath.back();
            if (sameFace1(last,cmd))
                continue;
        }
        //开始dfs
        State1 next=move1(cur,cmd,sliceMove,edgesFaceMove,corsFaceMove);
        solutionPath.push_back(cmd);
        if (search1(next,bound,solutionPath,sliceDist,eoDist,coDist,
                    sliceMove,edgesFaceMove,corsFaceMove))
            return true;
        solutionPath.pop_back();    //回溯
    }
    return false;
}

inline std::vector<uint8_t> solvePhase1(State1&start,
                uint8_t sliceDist[495],uint8_t eoDist[2048],uint8_t coDist[2187],
                uint16_t sliceMove[495][18],
                uint16_t edgesFaceMove[2048][18],
                uint16_t corsFaceMove[2187][18]){
    std::vector<uint8_t> solutionPath;
    uint8_t bound=heur1(start,sliceDist,eoDist,coDist);
    while (true){
        if (search1(start,bound,solutionPath,sliceDist,eoDist,coDist,
                    sliceMove,edgesFaceMove,corsFaceMove))
            return solutionPath;
        ++bound;        //增加迭代的深度界限
    }   
}

inline bool search2(State2&cur,uint8_t bound,std::vector<uint8_t>&solutionPath,
                    const std::vector<uint8_t>&cpEp4Dist,
                    const std::vector<uint8_t>&ep8Ep4Dist,
                    uint16_t cpMove[40320][10],
                    uint16_t epMove8[40320][10],
                    uint16_t epMove4[24][10]){
    uint8_t h=heur2(cur,cpEp4Dist,ep8Ep4Dist);
    //先写结束条件(G2)
    if (h==0)   return true;
    if (cur.depth+h > bound)
        return false;
    //向10种操作搜索
    for (uint8_t cmd=0; cmd<10; cmd++){
        //如果是同层次操作,跳过
        if (!solutionPath.empty()){
            uint8_t last=solutionPath.back();
            if (sameFace2(last,cmd))    continue;
        }
        //开始dfs
        State2 next = move2(cur,cmd,cpMove,epMove8,epMove4);
        solutionPath.push_back(cmd);
        if (search2(next,bound,solutionPath,cpEp4Dist,ep8Ep4Dist,
                    cpMove,epMove8,epMove4))
            return true;
        solutionPath.pop_back();    //回溯
    }
    return false;
}

inline std::vector<uint8_t> solvePhase2(State2&start,
                const std::vector<uint8_t>&cpEp4Dist,
                const std::vector<uint8_t>&ep8Ep4Dist,
                uint16_t cpMove[40320][10],
                uint16_t epMove8[40320][10],
                uint16_t epMove4[24][10]){
    std::vector<uint8_t> solutionPath;
    uint8_t bound=heur2(start,cpEp4Dist,ep8Ep4Dist);
    while (true){
        if (search2(start,bound,solutionPath,cpEp4Dist,ep8Ep4Dist,
                    cpMove,epMove8,epMove4))
            return solutionPath;
        ++bound;            //增加迭代的深度界限
    } 
}

