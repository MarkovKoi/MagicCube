#pragma once
#include <vector>
#include <cstdint>

//生成排列数
inline uint16_t fac(uint8_t n){
    if (n==0)
        return 1;
    uint16_t ans=1;
    for (uint8_t k=1;k<=n;k++){
        ans*=k;
    }
    return ans;
}

//康托展开:start和end都表示索引
inline uint16_t cantor(const std::vector<uint8_t>&place,uint8_t start,uint8_t end){
    uint16_t ans=0;         //存储结果
    uint16_t a=1;           //记录阶乘
    uint8_t n=end-start+1;
    //这里注意无符号整数不要越界溢出
    for (uint8_t i=n;i>0;i--){
        uint8_t x=place[start+i-1]; //记录当前元素
        uint8_t cnt=0;              //统计当前元素后面更小的元素的个数
        for (uint8_t j=i;j<n;j++){
            if (place[start+j]<x)
                cnt++;
        }
        ans+=cnt*a;
        a*=(n-i+1);
    }
    return ans;
}

//逆康托展开:start和end都表示索引
inline void invCantor(std::vector<uint8_t>&place,uint16_t X,uint8_t base,
                        uint8_t start,uint8_t end){
    const uint8_t n=end-start+1;
    uint8_t A[n]={0};       //先存储系数
    for (uint8_t k=0;k<n;k++){
        uint16_t a=fac(n-k-1);
        A[k]=X/a;
        X=X%a;
    }
    //定义一个自然数组
    std::vector<uint8_t> nature=std::vector<uint8_t>(n,0);
    for (uint8_t k=0;k<n;k++){
        nature[k]=k;
    }
    //逐步移除,确定排列
    for (uint8_t k=0;k<n;k++){
        place[start+k]=base+nature[A[k]];
        nature.erase(nature.begin()+A[k]);
    }
}