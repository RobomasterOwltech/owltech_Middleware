/*
 * MotorPI.cpp
 */

#include "BaseMotor.hpp"

BaseMotor::BaseMotor(TIM_HandleTypeDef* _timer, int minFreq, int maxFreq)
{

    BaseMotor_PWM.timer = *_timer;
    BaseMotor_PWM.duty_Cycle = 0;
    BaseMotor_PWM.frequency = 1;
    BaseMotor_PWM.pin_id = 0;
    BaseMotor_PWM.prescaler = 0;

    runFrequency = 1;

    set_MaxVel(32.0f);
    set_MinVel(-32.0f);

    minFreqPWM = minFreq;
    maxFreqPWM = maxFreq;

    stop();
}

BaseMotor::~BaseMotor() { }
void BaseMotor::set_MaxVel(float nMax) { maxVel = nMax; }
void BaseMotor::set_MinVel(float nMin) { minVel = nMin; }
void BaseMotor::set_runFrequency(int f) { runFrequency = f; }

void BaseMotor::invert() { direction *= -1; }

void BaseMotor::go_to_reference() { BaseMotor_PWM.timer->Instance->CCR1 = 0; }

void BaseMotor::stop() { go_to_reference(); }
