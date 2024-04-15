#include "ControllerPWM.hpp"

<<<<<<< HEAD
ControllerPWM::ControllerPWM(TIM_HandleTypeDef* _timer, uint16_t _channel, uint16_t _prescaler) {
    timer = _timer;
    channel = _channel;

    _timer->Init.Prescaler = _prescaler - 1;

    prescaler = _timer->Init.Prescaler;
    clock_frequency = 1 / (_timer->Init.Period * _timer->Init.Prescaler);
=======
ControllerPWM::ControllerPWM(TIM_HandleTypeDef* _timer, int minPulse, int maxPulse, int desFreq) {
    timer = _timer;
    _timer->Init.Prescaler = (HAL_RCC_GetSysClockFreq()/desFreq) - 1;
    minimum_pulse = minPulse;
    maximum_pulse = maxPulse;
>>>>>>> b62a478f4f1c401e35a28734d6043b50c3c1b6a9
}

ControllerPWM::~ControllerPWM() {}

<<<<<<< HEAD
uint16_t ControllerPWM::get_frequency() { return clock_frequency / timer->Init.AutoReloadPreload; }
uint16_t ControllerPWM::get_duty_cycle() { return (arr / ccr) * 100; }
uint16_t ControllerPWM::get_prescaler() { return timer->Init.Prescaler; }

void ControllerPWM::set_frequency(uint16_t pwm_frequency) {
    timer->Init.AutoReloadPreload = clock_frequency / pwm_frequency;
    arr = timer->Init.AutoReloadPreload;
}
void ControllerPWM::set_duty_cycle(uint16_t _duty_cycle) {
    ccr = (_duty_cycle * arr) / 100;
    // timer->Instance->CCR1 = ccr;
}
void ControllerPWM::set_arr(uint32_t _arr) {
    arr = _arr;
    timer->Init.AutoReloadPreload = _arr;
}

void ControllerPWM::set_clock_frequency(uint32_t _prescaler) {
    timer->Init.Prescaler = _prescaler - 1;
    prescaler = _timer->Init.Prescaler;
    clock_frequency = 1 / (_timer->Init.Period * _timer->Init.Prescaler);
}

=======
void ControllerPWM::set_duty_cycle(uint16_t _duty_cycle) { 
    duty_cycle = _duty_cycle;
    
}
void ControllerPWM::set_prescaler() { prescaler = clock_frequency / (pwm_frequency + 1); }
>>>>>>> b62a478f4f1c401e35a28734d6043b50c3c1b6a9
void ControllerPWM::calibrateSignal() {}
