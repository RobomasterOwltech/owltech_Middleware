#include <iostream>
#ifndef SCM3508_H
#define SCM3508_H
using namespace std;

#include "BaseMotor.hpp";

enum ControlMode {
    PWM_MODE,
    CAN_MODE
};

class SCM3508 : public BaseMotor{
    public:
        // Constructor
        SpeedController(TIM_HandleTypeDef* _timer, int minFreq, int maxFreq) : BaseMotor(_timer, minFreq, maxFreq) {
            isRunning = false; // Inicializa el motor como no girando
        }

        // Destructor
        ~SpeedController() {}

        // Método para arrancar el motor
        void start() {
            go_to_reference(); // Lleva el motor a su referencia inicial si es necesario
            isRunning = true; // Marca el motor como girando
        }

        // Método para detener el motor
        void stop() {
            BaseMotor::stop(); // Detiene el motor llamando al método de la clase BaseMotor
            isRunning = false; // Marca el motor como no girando
        }

        void setControlMode(ControlMode newMode) {
        mode = newMode;
        }

        // Método para verificar si el motor está girando
        bool isMotorRunning() const {
            return isRunning;
        }
    private:
        bool isRunning; // Estado del motor (girando o no)

}; 
#endif