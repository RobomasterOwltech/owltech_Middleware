/*
 * ReciverChanel.cpp
 *
 *  Created on: Apr 13, 2024
 *      Author: @carloseag1234
 */

 #include "ReciverChanel.hpp"

 ReciverChanel::ReciverChanel(TIM_HandleTypeDef *htim, uint32_t channel) : htim_(htim), channel_(channel) {}

 uint16_t ReciverChanel::read() {
    return HAL_TIM_ReadCapturedValue(htim_, channel_);
}