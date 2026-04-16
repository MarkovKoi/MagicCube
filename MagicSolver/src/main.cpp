#include "algo/cantor.hpp"
#include "algo/init_coord.hpp"
#include "algo/init_list.hpp"
#include "algo/init_model.hpp"
#include "algo/io.hpp"
#include "algo/move.hpp"
#include "algo/movecode_ph1.hpp"
#include "algo/place_trans.hpp"
#include "algo/solve.hpp"

//数据表
uint16_t sliceMove[495][18];
uint16_t edgesFaceMove[2048][18];
uint16_t corsFaceMove[2187][18];
uint8_t sliceDist[495];
uint8_t eoDist[2048];
uint8_t coDist[2187];
uint16_t cpMove[40320][10];
uint16_t epMove8[40320][10];
uint16_t epMove4[24][10];
std::vector<uint8_t> cpEp4Dist(40320*24,255);
std::vector<uint8_t> ep8Ep4Dist(40320*24,255);
//状态表
std::vector<uint8_t> corsFace=std::vector<uint8_t>(8,0);
std::vector<uint8_t> corsPlace=std::vector<uint8_t>(8,0);
std::vector<uint8_t> edgesFace=std::vector<uint8_t>(12,0);
std::vector<uint8_t> edgesPlace=std::vector<uint8_t>(12,0);

int main(){
    //输入
    std::vector<std::vector<uint8_t>> sixColors=input();
    //导入
    init_list(sliceMove,edgesFaceMove,corsFaceMove,sliceDist,eoDist,coDist,
            cpMove,epMove8,epMove4,cpEp4Dist,ep8Ep4Dist);
    //初始化模型
    init_model(sixColors,corsFace,corsPlace,edgesFace,edgesPlace);
    //初始化坐标
    State1 start1=init_coord1(corsFace,edgesFace,edgesPlace);
    //迭代
    std::vector<uint8_t> path1=solvePhase1(start1,sliceDist,eoDist,coDist,
                                    sliceMove,edgesFaceMove,corsFaceMove);
    //维护位置
    placePhase1(path1,corsPlace,edgesPlace);
    //初始化坐标
    State2 start2=init_coord2(corsPlace,edgesPlace);
    //迭代
    std::vector<uint8_t> path2=solvePhase2(start2,cpEp4Dist,
                                ep8Ep4Dist,cpMove,epMove8,epMove4);
    //打印
    print_path(path1,path2);
    return 0;
}