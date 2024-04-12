/*
 * ControllerCAN.hpp
 *
 *  Created on: April 12, 2024
 *      Author: @JorgePerC
 */

#ifndef ControllerCAN_HPP
#define ControllerCAN_HPP

// ===== Includes =====
#include "stm32f4xx_hal.h"

// ===== Constants =====
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
// Data Length Code 8 BYTES
#define RM_DLC              0x8

// ===== Structs for message =====

typedef struct {
    // CAN ID for the receiver node
    uint16_t id;
    // Sets the action to be perfomed by the CAN node
    uint16_t function_code; 
    // Actual data content
    uint8_t TxData[RM_DLC];
} CAN_MSG_STR;

class ControllerCAN {
private:

    CAN_HandleTypeDef   timer;
    int id;

    void sendMessage ();
    void readMessage ();

public:
    ControllerCAN(CAN_HandleTypeDef handler, int ID);

    void setTorque(int desTorque);
    void setPosition(int desPostion);
    void setVelocity(int desVelocity);

    void getMotorStatus();

    ~ControllerCAN();
};

#endif /* ControllerCAN */

// ==================
/*
file:///Users/jperezch/Downloads/um2217-description-of-stm32h7-hal-and-lowlayer-drivers-stmicroelectronics.pdf


  ==============================================================================
                      ##### Control functions #####
  ==============================================================================
    [..]  This section provides functions allowing to:
      (+) HAL_CAN_Start                    : Start the CAN module
      (+) HAL_CAN_Stop                     : Stop the CAN module
      (+) HAL_CAN_RequestSleep             : Request sleep mode entry.
      (+) HAL_CAN_WakeUp                   : Wake up from sleep mode.
      (+) HAL_CAN_IsSleepActive            : Check is sleep mode is active.
      (+) HAL_CAN_AddTxMessage             : Add a message to the Tx mailboxes
                                             and activate the corresponding
                                             transmission request
      (+) HAL_CAN_AbortTxRequest           : Abort transmission request
      (+) HAL_CAN_GetTxMailboxesFreeLevel  : Return Tx mailboxes free level
      (+) HAL_CAN_IsTxMessagePending       : Check if a transmission request is
                                             pending on the selected Tx mailbox
      (+) HAL_CAN_GetRxMessage             : Get a CAN frame from the Rx FIFO
      (+) HAL_CAN_GetRxFifoFillLevel       : Return Rx FIFO fill level

*/