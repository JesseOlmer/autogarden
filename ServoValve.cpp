#include "ServoValve.h"

#include <Arduino.h>

#include "Logger.h"

const int k_openDegrees = 180;
const int k_closeDegrees = 0;

ServoValve::ServoValve(int pin)
{
    m_pin = pin;
    m_targetDegrees = m_servo.read();
}

void ServoValve::Attach()
{
    m_servo.attach(m_pin);
}

void ServoValve::Open()
{
    Set(k_openDegrees);
}

void ServoValve::Close()
{
    Set(k_closeDegrees);
}

void ServoValve::Set(int degrees)
{
    Logf("Servo %d set to %d degrees.", m_pin, degrees);

    m_targetDegrees = degrees;
}

int ServoValve::Get()
{
    // Servo::read() is not const :(
    return m_servo.read();
}

void ServoValve::Update()
{
    if (!m_servo.attached())
    {
        Logf("Servo %d not attached!", m_pin);
    }
    m_servo.write(m_targetDegrees);
}