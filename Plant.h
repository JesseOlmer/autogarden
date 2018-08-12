
#if !defined(PLANT_H)
#define PLANT_H

#include "ServoValve.h"
#include "MoistureSensor.h"

class Plant : MoistureSensorCallback
{
    public:
        Plant(int servoPin, int sensorPin);
        void Attach();
        void Update();

        virtual void MoistureCallback(int pin, bool isWet);

    private:
        ServoValve m_Servo;
        MoistureSensor m_Sensor;

        void MoistureSensorCallback(int pin, bool isWet);
};

#endif // PLANT_H
