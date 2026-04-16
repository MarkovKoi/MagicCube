#pragma once
#include "../defs/cube_trans.hpp"
#include <iostream>
#include <vector>
#include <cstdint>

inline std::vector<std::vector<uint8_t>> input(){
    std::string x;
    std::getline(std::cin,x);
    std::vector<std::vector<uint8_t>> sixColors
        =std::vector<std::vector<uint8_t>> (6,std::vector<uint8_t>(8,0));
    for (uint8_t i=0;i<6;i++){
        for (uint8_t j=0;j<8;j++){
            sixColors[i][j] = x[i*8 + j] - '0';
        }
    }
    return sixColors;
}


inline void print_path(const std::vector<uint8_t>&path1,const std::vector<uint8_t>&path2){
    uint8_t size=path1.size()+path2.size();
    if (size==0)    return;
    printf("%d steps:",size);
    for (uint8_t i=0;i<path1.size();i++){
        std::string cmd=command1[path1[i]];
        printf("%s ",cmd.c_str());
    }
    for (uint8_t i=0;i<path2.size();i++){
        std::string cmd=command2[path2[i]];
        printf("%s ",cmd.c_str());
    }
}