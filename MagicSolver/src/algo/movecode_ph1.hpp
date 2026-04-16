#pragma once
#include <vector>
#include <cstdint>

//生成组合数
inline uint16_t cnm(uint8_t n,uint8_t m){
    uint16_t ans=1;
    for (uint8_t k=0;k<m;k++){
        ans*=n--;
    }
    for (uint8_t k=2;k<=m;k++){
        ans/=k;
    }
    return ans;
}



//UDSlice->Num
inline uint16_t sliceToNum(const std::vector<uint8_t>&slicePlace){
    uint8_t cnt=0;              //统计已遇到的中层棱块数
    uint16_t rank=0;    
    for (uint8_t k=0; k<12; k++){
        if (slicePlace[k]==1){
            cnt++;              //若遇到中层棱块,计数
        }
        else if (cnt>0){        //非中层棱块,且cnt不为0
            rank+=cnm(k,cnt-1); //依据算法累加
        }
    }
    return rank;
}

//棱向->数字
inline uint16_t eoToNum(const std::vector<uint8_t>&edgesFace){
    uint16_t s=0;
    uint16_t pow=1;
    for (uint8_t k=0;k<11;k++){
        s+=edgesFace[k]*pow;
        pow*=2;
    }
    return s;
}

//角向->数字
inline uint16_t coToNum(const std::vector<uint8_t>&nextState){
    uint16_t s=0;
    uint16_t pow=1;
    for (uint8_t k=0;k<7;k++){
        s+=nextState[k]*pow;
        pow*=3;
    }
    return s;
}