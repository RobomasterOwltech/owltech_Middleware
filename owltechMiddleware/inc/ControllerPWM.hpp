#include "stm32f4xx_hal.h"

class ControllerPWM {
   private:
    typedef struct {
        uint16_t frequency;
        uint16_t duty_cycle;
        uint16_t prescaler;
        TIM_HandleTypeDef* timer;
        uint32_t channel;
    } PWM_MSG_STR;

    // Signal variables
    int maximum_frequency;
    int minimum_frequency;
    int run_frequency;

   public:
    ControllerPWM(TIM_HandleTypeDef* _timer, int minFreq, int maxFreq);
    ~ControllerPWM();

    uint16_t get_frequency();
    uint16_t get_duty_cycle();
    uint16_t get_prescaler();
    uint16_t get_pin_id();

    void set_frequency(uint16_t _frequency);
    void set_duty_cycle(uint16_t _duty_cycle);
    void set_prescaler(uint16_t _prescaler);

    virtual void set_positon(int desiredPosition);
    virtual void set_velocity(int desiredVelocity);

    void calibrateSignal();
};