//
// Created by zhu_y on 2024/10/12.
//

#ifndef MAPPING_H
#define

#ifndef MAPPING_H
#define MAPPING_H
#include "main.h"
#endif //MAPPING_H

#define RCChannel_BF_Max 1684
#define RCChannel_BF_Min 364
#define RCChannel_AF_Max 1
#define RCChannel_AF_Min -1

#define RCBotton_Max 3
#define RCBotton_Min 1

#define RCMouse_BF_Max 32767
#define RCMouse_BF_Min -32768
#define RCMouse_AF_Max 1
#define RCMouse_AF_Min -1

#define RCSwitch_Max 1
#define RCSwitch_Min 0

#define KEY_PRESSED_OFFSET_W               ((uint16_t)0x01<<0)
#define KEY_PRESSED_OFFSET_S               ((uint16_t)0x01<<1)
#define KEY_PRESSED_OFFSET_A               ((uint16_t)0x01<<2)
#define KEY_PRESSED_OFFSET_D               ((uint16_t)0x01<<3)
#define KEY_PRESSED_OFFSET_Q               ((uint16_t)0x01<<4)
#define KEY_PRESSED_OFFSET_E               ((uint16_t)0x01<<5)
#define KEY_PRESSED_OFFSET_SHIFT           ((uint16_t)0x01<<6)
#define KEY_PRESSED_OFFSET_CTRL            ((uint16_t)0x01<<7)

float RCChannel_mapping(uint16_t);

typedef enum {
    Botton_On = RCBotton_Max,
    Botton_Off = RCBotton_Min,
}RCBottonTypeDef;

float RCMouse_mapping(uint16_t);

typedef enum {
    Switch_On = RCSwitch_Max,
    Switch_Off = RCSwitch_Min,
}RCSwitchTypeDef;

# endif