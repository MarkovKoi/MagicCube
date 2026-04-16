#pragma once
#include "../defs/cube_defs.hpp"
#include <vector>
#include <map>
#include <tuple>
#include <cstdint>
#include <iostream>
#include <algorithm>

//初始化棱块信息
inline void init_edge(const std::vector<std::vector<uint8_t>>&sixColors,
                    std::vector<uint8_t>&edgesFace,
                    std::vector<uint8_t>&edgesPlace){
    //重整颜色信息,存储棱位,定义棱向
    uint8_t c[2]={0};       //创建临时数组
    for (uint8_t k=0;k<12;k++){
        c[0]=sixColors[eColorDir[k][0]][eColorDir[k][1]];
        c[1]=sixColors[eColorDir[k][2]][eColorDir[k][3]];
        edgesFace[k]=edgeFaceMap.at(std::make_pair(c[0],c[1]));
        edgesPlace[k]=edgePlaceMap.at(std::minmax(c[0],c[1]));
    }          
}
//初始化角块信息
inline void init_cor(const std::vector<std::vector<uint8_t>>&sixColors,
                    std::vector<uint8_t>&corsFace,
                    std::vector<uint8_t>&corsPlace){
    //重整颜色信息,存储角位,定义角向
    uint8_t c[3]={0};       //创建临时数组
    for (uint8_t k=0;k<8;k++){
        c[0]=sixColors[cColorDir[k][0]][cColorDir[k][1]];
        c[1]=sixColors[cColorDir[k][2]][cColorDir[k][3]];
        c[2]=sixColors[cColorDir[k][4]][cColorDir[k][5]];
        corsFace[k]=corFaceMap.at(std::make_tuple(c[0],c[1],c[2]));
        //先生成三元tuple的升序版
        uint8_t c0=c[0],c1=c[1],c2=c[2],t=0;
        if (c0 > c1) { t = c0; c0 = c1; c1 = t; }
        if (c0 > c2) { t = c0; c0 = c2; c2 = t; }
        if (c1 > c2) { t = c1; c1 = c2; c2 = t; }
        corsPlace[k]=corPlaceMap.at(std::make_tuple(c0,c1,c2));
    }
}
//初始化模型
inline void init_model(const std::vector<std::vector<uint8_t>>&sixColors,
                    std::vector<uint8_t>&corsFace,std::vector<uint8_t>&corsPlace,
                    std::vector<uint8_t>&edgesFace,std::vector<uint8_t>&edgesPlace){
    init_cor(sixColors,corsFace,corsPlace);
    init_edge(sixColors,edgesFace,edgesPlace);
}