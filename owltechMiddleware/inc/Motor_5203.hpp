#include "BaseMotor.hpp"
#include "stm32f4xx_hal.h"

class Motor_5203 : public BaseMotor {
   private:
    typedef struct {
        CAN_MSG_STR msg;
        bool direction;
        uint16_t actual_status_sign;
    } MOTOR_STR;
    int ranges;
    int frequency;
    int temperature

        public:
};
