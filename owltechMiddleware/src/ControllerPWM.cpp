#include "ControllerPWM.hpp"

ControllerPWM::ControllerPWM(TIM_HandleTypeDef* _timer, int minFreq, int maxFreq) {
    timer = _timer;
    clock_frequency = 1/(_timer->Init.Period*_timer->Init.Prescaler);
    minimum_frequency = minFreq;
    maximum_frequency = maxFreq;
}

ControllerPWM::~ControllerPWM() {}
uint16_t ControllerPWM::get_frequency() { return pwm_frequency; }
uint16_t ControllerPWM::get_duty_cycle() { return duty_cycle; }
uint16_t ControllerPWM::get_prescaler() { return prescaler; }

void ControllerPWM::set_frequency(uint16_t _frequency) { 
    // TODO: Operacion
    pwm_frequency = _frequency; }
void ControllerPWM::set_duty_cycle(uint16_t _duty_cycle) { duty_cycle = _duty_cycle; }
void ControllerPWM::set_prescaler(uint16_t _prescaler) { 
    // Todo: operación
    prescaler = _prescaler; }

void ControllerPWM::calibrateSignal() {}
