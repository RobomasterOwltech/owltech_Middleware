#include "ControllerPWM.hpp"

ControllerPWM::ControllerPWM(TIM_HandleTypeDef* _timer, int minFreq, int maxFreq) {
    PWM_MSG_STR.timer = _timer;
    PWM_MSG_STR.duty_cycle = 0;
    PWM_MSG_STR.frequency = 1;
    PWM_MSG_STR.prescaler = 0;
    run_frequency = 1;
    minimum_frequency = minFreq;
    maximum_frequency = maxFreq;
}

ControllerPWM::~ControllerPWM() {}
uint16_t ControllerPWM::get_frequency() { return PWM_MSG_STR.frequency; }
uint16_t ControllerPWM::get_duty_cycle() { return PWM_MSG_STR.duty_cycle; }
uint16_t ControllerPWM::get_prescaler() { return PWM_MSG_STR.prescaler; }

void ControllerPWM::set_frequency(uint16_t _frequency) { PWM_MSG_STR.frequency = _frequency; }
void ControllerPWM::set_duty_cycle(uint16_t _duty_cycle) { PWM_MSG_STR.duty_cycle = _duty_cycle; }
void ControllerPWM::set_prescaler(uint16_t _prescaler) { PWM_MSG_STR.prescaler = _prescaler; }

void ControllerPWM::calibrateSignal() {}
