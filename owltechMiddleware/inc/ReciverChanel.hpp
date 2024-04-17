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
    TIM_HandleTypeDef *htim_;
    uint32_t channel_;
public:
    ReciverChanel(TIM_HandleTypeDef *htim, uint32_t channel);
    uint16_t read();
    ~ReciverChanel();
};

#endif /* ReciverChanel */