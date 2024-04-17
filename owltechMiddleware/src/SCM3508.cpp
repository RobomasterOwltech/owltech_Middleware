#include "SPM3508.hpp"

SpeedControllerPWM::SpeedControllerPWM(TIM_HandleTypeDef timer, OperationModes mode, uint8_t motorId) {
    // Setting the properties
    this->attr->maxVelocity = 400;   // rpm
    this->attr->minVelocity = -400;  // rpm

    this->attr->maxVelocity = NaN;
    this->attr->minVelocity = NaN;

    this->attr->minTemp = minTemp;
    this->attr->maxTemp = maxTemp;

    this->attr->maxTorque = Nan;
    this->attr->minTorque = NaN;

    this->contr.pwm = new ControllerPWM(hpwm, uint8_t motorId);
}

void SpeedControllerPWM::setSpeed(float _Speed) { Speed = _Speed; }

float SpeedControllerPWM::calculateSpeed(uint16_t duty_Cycle, float maxVel) { return (duty_Cycle * maxVel); }