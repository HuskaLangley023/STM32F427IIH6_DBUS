//
// Created by zhu_y on 2024/10/12.
//
#include "mapping.h"


float RCChannel_mapping(uint16_t rc_ch) {
    float k = (RCChannel_AF_Max - RCChannel_AF_Min)/(RCChannel_BF_Max - RCChannel_BF_Min);
    return rc_ch*k+RCChannel_AF_Max-k*RCChannel_BF_Max;
}



float RCMouse_mapping(uint16_t rc_ch) {
    float k = (RCMouse_AF_Max - RCMouse_AF_Min)/(RCMouse_BF_Max - RCMouse_BF_Min);
    return rc_ch*k+RCMouse_AF_Max-k*RCMouse_BF_Max;
}

