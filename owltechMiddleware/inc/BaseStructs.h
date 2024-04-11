/*
 * BasicStructs.h
 *
 *  Created on: May 24, 2023
 *      Author: JorgePerC
 * 
 * This file contains the basic structs necessary to build the generic
 * components of the middleware
 */

#ifndef BasicStructs
#define BasicStructs



#ifdef __cplusplus
 extern "C" {
#endif

// ===== Includes =====
#include "stm32f4xx_hal.h"

// ===== Unions =====
typedef union {
    float velocity;
    float torque;
    float position;
} maxState;

typedef union {
    float velocity;
    float torque;
    float position;
} minState;

// ===== Structs =====


typedef struct {
    // Frequency of ...
    uint16_t frequency;
    uint16_t duty_Cycle; 
    uint16_t prescaler;
    uint16_t pin_id;
    TIM_HandleTypeDef timer;
} PWM_MSG_STR;

typedef struct {
    CAN_MSG_STR msg; 
    bool direction;
    uint16_t actual_status_sign;
} MOTOR_STR;



typedef struct {
    uint8_t resolution; 
    TIM_HandleTypeDef timer;
    // Do we really need these?
    GPIO_InitTypeDef pin1;
    GPIO_InitTypeDef pin2;

    uint16_t velocity;
    uint16_t last_tick;
    uint16_t curr_tick; 
} Encoder_Feedback;

#ifdef __cplusplus
}
#endif

#endif /* BasicStructs */