#pragma once
#include "../defs/cube_trans.hpp"
#include <vector>

//棱位变换
inline void epTrans(std::vector<uint8_t>&edgesPlace,uint8_t cmd){
    if ((cmd-1)%3==0){
        uint8_t startPlace=edgesPlace[epDir_ph1[cmd][0]];
        edgesPlace[epDir_ph1[cmd][0]]=edgesPlace[epDir_ph1[cmd][1]];
        edgesPlace[epDir_ph1[cmd][1]]=startPlace;
        startPlace=edgesPlace[epDir_ph1[cmd][2]];
        edgesPlace[epDir_ph1[cmd][2]]=edgesPlace[epDir_ph1[cmd][3]];
        edgesPlace[epDir_ph1[cmd][3]]=startPlace;
    }else{
        uint8_t startPlace=edgesPlace[epDir_ph1[cmd][0]];
        edgesPlace[epDir_ph1[cmd][0]]=edgesPlace[epDir_ph1[cmd][1]];
        edgesPlace[epDir_ph1[cmd][1]]=edgesPlace[epDir_ph1[cmd][2]];
        edgesPlace[epDir_ph1[cmd][2]]=edgesPlace[epDir_ph1[cmd][3]];
        edgesPlace[epDir_ph1[cmd][3]]=startPlace;
    }
}

//角位变换
inline void cpTrans(std::vector<uint8_t>&corsPlace,uint8_t cmd){
    if ((cmd-1)%3==0){
        uint8_t startPlace=corsPlace[cpDir_ph1[cmd][0]];
        corsPlace[cpDir_ph1[cmd][0]]=corsPlace[cpDir_ph1[cmd][1]];
        corsPlace[cpDir_ph1[cmd][1]]=startPlace;
        startPlace=corsPlace[cpDir_ph1[cmd][2]];
        corsPlace[cpDir_ph1[cmd][2]]=corsPlace[cpDir_ph1[cmd][3]];
        corsPlace[cpDir_ph1[cmd][3]]=startPlace;
    }else{
        uint8_t startPlace=corsPlace[cpDir_ph1[cmd][0]];
        corsPlace[cpDir_ph1[cmd][0]]=corsPlace[cpDir_ph1[cmd][1]];
        corsPlace[cpDir_ph1[cmd][1]]=corsPlace[cpDir_ph1[cmd][2]];
        corsPlace[cpDir_ph1[cmd][2]]=corsPlace[cpDir_ph1[cmd][3]];
        corsPlace[cpDir_ph1[cmd][3]]=startPlace;
    }
}

inline void placePhase1(const std::vector<uint8_t>&path,
                        std::vector<uint8_t>&corsPlace,
                        std::vector<uint8_t>&edgesPlace){
    for (auto cmd:path){
        epTrans(edgesPlace,cmd);
        cpTrans(corsPlace,cmd);
    }
}