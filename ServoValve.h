#ifndef SERVOVALVE_H
#define SERVOVALVE_H

#include <Servo.h>

class ServoValve
{
    public:
        ServoValve(int pin);
        void Attach();
        void Open();
        void Close();
        void Set(int degrees);
        int Get();

        void Update();
    private:
        int m_pin;
        int m_targetDegrees;
        Servo m_servo;
};

#endif
