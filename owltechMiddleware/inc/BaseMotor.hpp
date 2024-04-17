/*
 * BaseMotor.hpp
 *
 *  Created on: Apr 10, 2024
 *      Author: @JorgePerC
 */
#ifndef BaseMotor_HPP
#define BaseMotor_HPP

#include "ControllerCAN.hpp"
#include "ControllerPWM.hpp"

typedef enum { POS, VEL, TOR } OperationModes;

typedef struct {
    float maxVelocity;
    float minVelocity;
    float maxTorque;
    float minTorque;
    float maxPosition;
    float minPosition;
    float maxTemp;
    float minTemp;
} OperationalRanges;

typedef union {
    ControllerCAN* can;
    ControllerPWM* pwm;
} Controller;

class BaseMotor {
   protected:
    Controller contr;
    OperationalRanges* attr;

    uint8_t mode;
    uint8_t dir;
    uint16_t runFreq;

    virtual void actuateVelocity();
    virtual void actuatePosition();
    virtual void actuateTorque();

   public:
    BaseMotor();
    BaseMotor(ControllerCAN* controller, OperationalRanges* attr, OperationModes mode, uint8_t direction);
    BaseMotor(ControllerPWM* controller, OperationalRanges* attr, OperationModes mode, uint8_t direction);
    virtual float getFeedback();
    void actuate();
    // The input value is an angular velocity
    virtual void setReference(float w){};
    virtual void setControlType(OperationModes mode){};
    void invert();
    void stop();

    ~BaseMotor();
};

#endif /* BaseMotor */
