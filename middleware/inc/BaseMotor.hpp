/*
 * BaseMotor.h
 */
#include "stm32f4xx_hal.h"

class BaseMotor {
private:
    typedef struct {
        // Frequency of ...
        uint16_t frequency;
        uint16_t duty_Cycle;
        uint16_t prescaler;
        uint16_t pin_id;
        TIM_HandleTypeDef* timer;
    } PWM_MSG_STR;
    PWM_MSG_STR BaseMotor_PWM;

    // Should be defined as radians
    float maxVel;
    float minVel;
    // To easily invert readings
    int direction = 1;
    // Signal variables
    int maxFreqPWM;
    int minFreqPWM;
    int runFrequency;

public:
    BaseMotor(TIM_HandleTypeDef* _timer, int minFreq, int maxFreq);
    ~BaseMotor();

    void set_MaxVel(float nMax);
    void set_MinVel(float nMin);
    void set_runFrequency(int f);
    void go_to_reference();
    void invert();
    void stop();
};
