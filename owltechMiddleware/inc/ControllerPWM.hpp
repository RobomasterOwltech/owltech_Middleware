/*
 * BaseMotor.h
 *
 *  Created on: Apr 12, 2024
 *      Author: @JorgePerC
 */
#ifndef ControllerPWM_HPP
#define ControllerPWM_HPP

// ===== Includes =====
#include "stm32f4xx_hal.h"

// ===== Constants =====

// ===== Structs for message =====

class ControllerPWM {
   private:
    TIM_HandleTypeDef timer;
    uint32_t channel;

    uint16_t frequency;
    uint16_t duty_Cycle;
    uint16_t prescaler;
    uint16_t pin_id;

    void sendSignalTimer();

   public:
    ControllerPWM(TIM_HandleTypeDef handler, int ID);

    void setPosition(int desPostion);
    void setVelocity(int desVelocity);

    void getMotorStatus();

    // TODO: make a method for calibration
    void calibrateSignal();

    ~ControllerPWM();
};

#endif