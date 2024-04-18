/*
 * ReciverChanel.hpp
 *
 *  Created on: Apr 13, 2024
 *      Author: @carloseag1234
 */


#ifndef ReciverChanel
#define ReciverChanel

class ReciverChanel
{
private:
    TIM_HandleTypeDef* htim_;
    uint32_t channel_;
    uint32_t pulse_width_;

    static void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
public:
    ReciverChanel(TIM_HandleTypeDef* htim, uint32_t channel);
    void begin();
    uint32_t getPWM();
    ~ReciverChanel();


};

#endif /* ReciverChanel */