#pragma once
#include <vector>
#include <map>
#include <tuple>
#include <cstdint>

//创建棱块颜色键值表
const std::map<std::pair<uint8_t,uint8_t>,uint8_t>edgePlaceMap={
    {std::make_pair<uint8_t,uint8_t>(0,1),0},
    {std::make_pair<uint8_t,uint8_t>(1,4),1},
    {std::make_pair<uint8_t,uint8_t>(1,5),2},
    {std::make_pair<uint8_t,uint8_t>(1,2),3},
    {std::make_pair<uint8_t,uint8_t>(0,3),4},
    {std::make_pair<uint8_t,uint8_t>(3,4),5},
    {std::make_pair<uint8_t,uint8_t>(3,5),6},
    {std::make_pair<uint8_t,uint8_t>(2,3),7},
    {std::make_pair<uint8_t,uint8_t>(0,2),8},
    {std::make_pair<uint8_t,uint8_t>(0,4),9},
    {std::make_pair<uint8_t,uint8_t>(4,5),10},
    {std::make_pair<uint8_t,uint8_t>(2,5),11},
};

//创建棱块颜色指引表
const uint8_t eColorDir[12][4]={
    {1,6,0,1},{1,3,4,1},{1,1,5,1},{1,4,2,1},
    {3,1,0,6},{3,3,4,6},{3,6,5,6},{3,4,2,6},
    {0,4,2,3},{0,3,4,4},{5,4,4,3},{5,3,2,4},
};

//创建棱向对照表
const std::map<std::pair<uint8_t,uint8_t>,uint8_t>edgeFaceMap={
    {std::make_pair<uint8_t,uint8_t>(1,0),0},
    {std::make_pair<uint8_t,uint8_t>(0,1),1},
    {std::make_pair<uint8_t,uint8_t>(1,4),0},
    {std::make_pair<uint8_t,uint8_t>(4,1),1},
    {std::make_pair<uint8_t,uint8_t>(1,5),0},
    {std::make_pair<uint8_t,uint8_t>(5,1),1},
    {std::make_pair<uint8_t,uint8_t>(1,2),0},
    {std::make_pair<uint8_t,uint8_t>(2,1),1},
    {std::make_pair<uint8_t,uint8_t>(3,0),0},
    {std::make_pair<uint8_t,uint8_t>(0,3),1},
    {std::make_pair<uint8_t,uint8_t>(3,4),0},
    {std::make_pair<uint8_t,uint8_t>(4,3),1},
    {std::make_pair<uint8_t,uint8_t>(3,5),0},
    {std::make_pair<uint8_t,uint8_t>(5,3),1},
    {std::make_pair<uint8_t,uint8_t>(3,2),0},
    {std::make_pair<uint8_t,uint8_t>(2,3),1},
    {std::make_pair<uint8_t,uint8_t>(0,2),0},
    {std::make_pair<uint8_t,uint8_t>(2,0),1},
    {std::make_pair<uint8_t,uint8_t>(0,4),0},
    {std::make_pair<uint8_t,uint8_t>(4,0),1},
    {std::make_pair<uint8_t,uint8_t>(5,4),0},
    {std::make_pair<uint8_t,uint8_t>(4,5),1},
    {std::make_pair<uint8_t,uint8_t>(5,2),0},
    {std::make_pair<uint8_t,uint8_t>(2,5),1},
};

//创建角块颜色键值表
const std::map<std::tuple<uint8_t,uint8_t,uint8_t>,uint8_t>corPlaceMap={
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,1,4),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(1,4,5),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(1,2,5),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,1,2),3},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,3,4),4},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(3,4,5),5},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(2,3,5),6},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,2,3),7}
};

//创建角块颜色指引表
const uint8_t cColorDir[8][6]={
    {1,5,0,0,4,2},{1,0,4,0,5,2},
    {1,2,5,0,2,2},{1,7,2,0,0,2},
    {3,0,4,7,0,5},{3,5,5,7,4,5},
    {3,7,2,7,5,5},{3,2,0,7,2,5},
};

//创建角向对照表
const std::map<std::tuple<uint8_t,uint8_t,uint8_t>,uint8_t>corFaceMap={
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(1,0,4),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(4,1,0),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,4,1),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(1,4,5),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(5,1,4),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(4,5,1),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(1,5,2),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(2,1,5),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(5,2,1),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(1,2,0),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,1,2),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(2,0,1),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(3,4,0),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,3,4),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(4,0,3),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(3,5,4),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(4,3,5),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(5,4,3),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(3,2,5),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(5,3,2),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(2,5,3),2},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(3,0,2),0},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(2,3,0),1},
    {std::make_tuple<uint8_t,uint8_t,uint8_t>(0,2,3),2},
};