//
// Created by zhu_y on 2024/10/12.
//
#include "main.h"
#include "usart.h"
extern RC_Ctl_t RC_CtrlData;
extern RC RC_showcase;
extern uint8_t rx_buffer[18];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if(huart->Instance == huart1.Instance) {
        //数据解析
        RC_CtrlData.rc.ch0 = ((int16_t)rx_buffer[0] | ((int16_t)rx_buffer[1] << 8)) & 0x07FF;
        RC_CtrlData.rc.ch1 = (((int16_t)rx_buffer[1] >> 3) | ((int16_t)rx_buffer[2] << 5)) & 0x07FF;
        RC_CtrlData.rc.ch2 = (((int16_t)rx_buffer[2] >> 6) | ((int16_t)rx_buffer[3] << 2) | ((int16_t)rx_buffer[4] << 10)) & 0x07FF;
        RC_CtrlData.rc.ch3 = (((int16_t)rx_buffer[4] >> 1) | ((int16_t)rx_buffer[5]<<7)) & 0x07FF;

        RC_CtrlData.rc.s1 = ((rx_buffer[5] >> 4) & 0x000C) >> 2;
        RC_CtrlData.rc.s2 = ((rx_buffer[5] >> 4) & 0x0003);

        RC_CtrlData.mouse.x = ((int16_t)rx_buffer[6]) | ((int16_t)rx_buffer[7] << 8);
        RC_CtrlData.mouse.y = ((int16_t)rx_buffer[8]) | ((int16_t)rx_buffer[9] << 8);
        RC_CtrlData.mouse.z = ((int16_t)rx_buffer[10]) | ((int16_t)rx_buffer[11] << 8);

        RC_CtrlData.mouse.press_l = rx_buffer[12];
        RC_CtrlData.mouse.press_r = rx_buffer[13];

        RC_CtrlData.key.v = ((int16_t)rx_buffer[14]) | ((int16_t)rx_buffer[15] << 8);
    }
    RC_showcase.l_row = RCChannel_mapping(RC_CtrlData.rc.ch2);
    RC_showcase.l_col = RCChannel_mapping(RC_CtrlData.rc.ch3);
    RC_showcase.r_row = RCChannel_mapping(RC_CtrlData.rc.ch0);
    RC_showcase.l_col = RCChannel_mapping(RC_CtrlData.rc.ch1);
    RC_showcase.s1 = RC_CtrlData.rc.s1;
    RC_showcase.s2 = RC_CtrlData.rc.s2;
    RC_showcase.mouse_x = RC_CtrlData.mouse.x;
    RC_showcase.mouse_y = RC_CtrlData.mouse.y;
    RC_showcase.mouse_z = RC_CtrlData.mouse.z;//映射




    HAL_UART_Receive_DMA(&huart1,rx_buffer,18);
}
