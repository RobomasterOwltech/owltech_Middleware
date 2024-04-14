#include "ControllerPWM.hpp"

ControllerPWM::ControllerPWM(TIM_HandleTypeDef* _timer, int minPulse, int maxPulse, int desFreq) {
    timer = _timer;
    _timer->Init.Prescaler = (HAL_RCC_GetSysClockFreq()/desFreq) - 1;
    minimum_pulse = minPulse;
    maximum_pulse = maxPulse;
}

ControllerPWM::~ControllerPWM() {}
uint16_t ControllerPWM::get_frequency() { return pwm_frequency; }
uint16_t ControllerPWM::get_duty_cycle() { return duty_cycle; }
uint16_t ControllerPWM::get_prescaler() { return prescaler; }

void ControllerPWM::set_duty_cycle(uint16_t _duty_cycle) { 
    duty_cycle = _duty_cycle;
    
}
void ControllerPWM::set_prescaler() { prescaler = clock_frequency / (pwm_frequency + 1); }
void ControllerPWM::calibrateSignal() {}
