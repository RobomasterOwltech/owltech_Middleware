/*
 * PIDControl.cpp
 *
 *  Created on: Apr 13, 2024
 *      Author: @carloseag1234
 */
 #include "PIDController.hpp"

PIDController::PIDController(float kp_, float ki_, float kd_, float setpoint_, auto (*pl)()) :
    Kp(kp_), Ki(ki_), Kd(kd_), Setpoint(setpoint_), auto planta(pl), Error1(0), Integral(0) {}

float PIDController::output(float feedback) {
    float error = Setpoint - feedback;
    Integral += error;
    float derivative = error - Error1;
    float output = Kp * error + Ki * integral + Kd * derivative;
    Error1 = error;
    return output;
}

void PIDcontrol::setSetpoint(float setpoint_){
    this->Setpoint=setpoint_
}