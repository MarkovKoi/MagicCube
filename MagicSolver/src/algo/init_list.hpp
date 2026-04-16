#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdint>

const std::string filename[11]={
    "../data/slicemove.dat","../data/edgefacemove.dat","../data/corfacemove.dat",
    "../data/slicedist.dat","../data/eodist.dat","../data/codist.dat",
    "../data/cpmove.dat","../data/epmove8.dat","../data/epmove4.dat",
    "../data/cpep4dist.dat","../data/ep8ep4dist.dat",
};


inline void init_list(
    uint16_t (&sliceMove)[495][18],
    uint16_t (&edgesFaceMove)[2048][18],
    uint16_t (&corsFaceMove)[2187][18],
    uint8_t (&sliceDist)[495],
    uint8_t (&eoDist)[2048],
    uint8_t (&coDist)[2187],
    uint16_t (&cpMove)[40320][10],
    uint16_t (&epMove8)[40320][10],
    uint16_t (&epMove4)[24][10],
    std::vector<uint8_t>& cpEp4Dist,
    std::vector<uint8_t>& ep8Ep4Dist
){
    for (uint8_t k=0;k<11;k++){
        std::string fp=filename[k];
        std::ifstream fin;
        fin.open(fp,std::ios::in|std::ios::binary);
        if (!fin.is_open()){
            std::cout << "失败" << std::endl;
            return;
        }
        switch (k){
            case 0:fin.read(reinterpret_cast<char*>(sliceMove),sizeof(sliceMove));break;
            case 1:fin.read(reinterpret_cast<char*>(edgesFaceMove),sizeof(edgesFaceMove));break;
            case 2:fin.read(reinterpret_cast<char*>(corsFaceMove),sizeof(corsFaceMove));break;
            case 3:fin.read(reinterpret_cast<char*>(sliceDist),sizeof(sliceDist));break;
            case 4:fin.read(reinterpret_cast<char*>(eoDist),sizeof(eoDist));break;
            case 5:fin.read(reinterpret_cast<char*>(coDist),sizeof(coDist));break;
            case 6:fin.read(reinterpret_cast<char*>(cpMove),sizeof(cpMove));break;
            case 7:fin.read(reinterpret_cast<char*>(epMove8),sizeof(epMove8));break;
            case 8:fin.read(reinterpret_cast<char*>(epMove4),sizeof(epMove4));break;
            case 9:fin.read(reinterpret_cast<char*>(cpEp4Dist.data()),
                        cpEp4Dist.size() * sizeof(uint8_t));break;
            case 10:fin.read(reinterpret_cast<char*>(ep8Ep4Dist.data()),
                        ep8Ep4Dist.size() * sizeof(uint8_t));break;
        }
        if (!fin){
            std::cout << "读取失败或文件大小不足" << std::endl;
            return;
        }
        fin.close();
    }
}
