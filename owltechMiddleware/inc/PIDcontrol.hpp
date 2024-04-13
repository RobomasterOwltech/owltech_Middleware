/*
 * PIDControl.hpp
 *
 *  Created on: Apr 13, 2024
 *      Author: @carloseag1234
 */

#ifndef PIDcontrol
#define PIDcontrol


class PIDcontrol
{
private:
    float Setpoint;
    float Kp;
    float ki;
    float Kd;
    float Error1;
    float Integral;

public:
    PIDcontrol(float ,float , float , float ,auto );
    float output(float);
    void setSetpoint(float);
    ~PIDcontrol();
};

#endif /* PIDcontrol */