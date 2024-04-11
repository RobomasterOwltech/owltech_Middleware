/*
 * BaseMotor.h
 *
 *  Created on: Apr 10, 2024
 *      Author: @JorgePerC
 */
#ifndef BaseMotor
#define BaseMotor

typedef union {
    float maxVelocity;
    float minVelocity;
    float maxTorque;
    float minTorque;
    float maxPosition;
    float minPosition;
} operationRanges;

#ifdef __cplusplus
 extern "C" {
#endif


#ifdef __cplusplus
 }
#endif 

#endif /* BaseMotor */

