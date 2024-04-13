#include "stm32f4xx_hal.h"

class ControllerPWM {
   private:
    uint16_t clock_frequency;
    uint16_t pwm_frequency;
    uint16_t duty_cycle;
    uint16_t prescaler;
    TIM_HandleTypeDef* timer;
    uint32_t channel;

    // Signal variables
    int maximum_pulse;
    int minimum_pulse;

    void set_frequency(uint16_t _frequency);
    void set_prescaler();

   public:
    ControllerPWM(TIM_HandleTypeDef* _timer, int minFreq, int maxFreq);
    ~ControllerPWM();

    uint16_t get_frequency();
    uint16_t get_duty_cycle();
    uint16_t get_prescaler();

    void set_duty_cycle(uint16_t _duty_cycle);

    virtual void set_positon(int desiredPosition);
    virtual void set_velocity(int desiredVelocity);

    void calibrateSignal();
};