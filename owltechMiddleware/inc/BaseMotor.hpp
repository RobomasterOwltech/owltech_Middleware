/*
 * BaseMotor.h
 *
 *  Created on: Apr 10, 2024
 *      Author: @JorgePerC
 */
#ifndef BaseMotor_HPP
#define BaseMotor_HPP

#include "ControllerCAN.hpp"
#include "ControllerPWM.hpp"

class BaseMotor
{
private:
    // TODO: Should we use Typedef?
    struct operationalRanges {
        float maxVelocity;
        float minVelocity;
        float maxTorque;
        float minTorque;
        float maxPosition;
        float minPosition;
    } ;

    union controller
    {
        ControllerCAN canController;
        ControllerPWM pwmController;
    };

    bool direction;
    
public:
    BaseMotor(/* args */) {}
    ~BaseMotor() {}
};





#endif /* BaseMotor */

