#pragma once
#include "../defs/cube_state.hpp"

inline State1 move1(const State1&s,uint8_t cmd,
            uint16_t sliceMove[495][18],
            uint16_t edgesFaceMove[2048][18],
            uint16_t corsFaceMove[2187][18]){
    return State1{
        sliceMove[s.slice][cmd],
        edgesFaceMove[s.eo][cmd],
        corsFaceMove[s.co][cmd],
        (uint8_t)(s.depth+1)
    };
}


inline State2 move2(const State2& s, uint8_t cmd,
            uint16_t cpMove[40320][10],
            uint16_t epMove8[40320][10],
            uint16_t epMove4[24][10]){
    return State2{
        cpMove[s.cp][cmd],
        epMove8[s.ep8][cmd],
        static_cast<uint8_t>(epMove4[s.ep4][cmd]),
        static_cast<uint8_t>(s.depth + 1)
    };
}