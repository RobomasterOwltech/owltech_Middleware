
#ifndef BasicStructs
#define BasicStructs

#ifdef __cplusplus
 extern "C" {
#endif

// ===== Includes =====
#include "stm32f4xx_hal.h"

#define CAN_ID_1        1
#define CAN_ID_2        2
#define CAN_ID_3        3
#define CAN_ID_4        4
#define CAN_ID_5        5
#define CAN_ID_6        6
#define CAN_ID_7        7
#define CAN_ID_8        8

// Read information from a given motor
    // The MSG is defined by
    // FEEDBACK_ID + MotorID
#define FEEDBACK_ID         0x204

// Sent control output to motors
#define CONTROL_ID_1_TO_4   0x1FF
#define CONTROL_ID_5_TO_7   0x2FF

#define CONTROL_ANGLE_BEND  0x0
#define CONTROL_ANGLE_LEND  0x1

#define CONTROL_SPEED_BEND  0x2
#define CONTROL_SPEED_LEND  0x3

//TODO: SET AS TORQUE?
#define READ_CURRENT_BEND   0x4
#define READ_CURRENT_LEND   0x5

#define READ_TEMP           0x6



typedef struct {


    // CAN ID for the receiver node
    uint16_t id;
    // Sets the action to be perfomed by the CAN node
    uint16_t function_code; 
    // Actual data content
    char data_2_send;
} CAN_MSG_STR;



#ifdef __cplusplus
}
#endif

#endif 