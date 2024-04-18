/*
 * ReciverChanel.cpp
 *
 *  Created on: Apr 13, 2024
 *      Author: @carloseag1234
 */

 #include "ReciverChanel.hpp"

ReciverChanel::ReciverChanel(TIM_HandleTypeDef* htim, uint32_t channel) :
    htim_(htim), channel_(channel), pulse_width_(0) {}

void ReciverChanel::begin() {
    HAL_TIM_IC_Start_IT(htim_, channel_);
}

uint32_t ReciverChanel::getPulseWidth() {
    return pulse_width_;
}

void ReciverChanel::HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
        pulse_width_ = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
    }
}