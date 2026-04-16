#pragma once
#include <cstdint>

//定义状态结构
struct State1{
    uint16_t slice;
    uint16_t eo;    //棱向
    uint16_t co;    //角向
    uint8_t depth;  //当前深度(已走步数)
};

//定义阶段二结构状态
struct State2{
    uint16_t cp;
    uint16_t ep8;
    uint8_t ep4;
    uint8_t depth;
};