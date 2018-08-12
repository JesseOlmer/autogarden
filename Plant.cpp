#include "Plant.h"

#include <Arduino.h>

#include "Logger.h"

Plant::Plant(int servoPin, int sensorPin)
: m_Servo(servoPin), m_Sensor(sensorPin)
{
    m_Sensor.SetCallback(this);
}

void Plant::Attach()
{
    m_Servo.Attach();
}

void Plant::Update()
{
    m_Sensor.Update();
    m_Servo.Update();
}

void Plant::MoistureCallback(int pin, bool isWet)
{
    Logf("MoistureCallback. Pin %d, %s.", pin, isWet ? "Wet" : "Dry");

    isWet ? m_Servo.Close() : m_Servo.Open();
}
