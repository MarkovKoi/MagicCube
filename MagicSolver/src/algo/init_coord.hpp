#pragma once
#include "../defs/cube_state.hpp"
#include "movecode_ph1.hpp"
#include "cantor.hpp"
#include <vector>

inline State1 init_coord1(const std::vector<uint8_t>&corsFace,const std::vector<uint8_t>&edgesFace,
                const std::vector<uint8_t>&edgesPlace){
    //先转换slicePlace表
    std::vector<uint8_t> slicePlace=std::vector<uint8_t>(12,0);
    for (uint8_t k=0;k<12;k++){
        if (edgesPlace[k]>=8 && edgesPlace[k]<=11)
            slicePlace[k]=1;
    }
    uint16_t slice=sliceToNum(slicePlace);
    uint16_t eo=eoToNum(edgesFace);
    uint16_t co=coToNum(corsFace);
    return State1{slice,eo,co,0};
}

inline State2 init_coord2(const std::vector<uint8_t>&corsPlace,const std::vector<uint8_t>&edgesPlace){
    uint16_t cp=cantor(corsPlace,0,7);
    uint16_t ep8=cantor(edgesPlace,0,7);
    uint8_t ep4=(uint8_t)cantor(edgesPlace,8,11);
    return State2{cp,ep8,ep4,0};
}