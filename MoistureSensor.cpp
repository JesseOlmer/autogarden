#include "MoistureSensor.h"

#include <Arduino.h>

MoistureSensor::MoistureSensor(int pin)
: m_pin(pin), m_isDigital(true), m_analogWetThreshold(0), m_callback(nullptr)
{
}

MoistureSensor::MoistureSensor(int pin, int analogWetThreshold)
: m_pin(pin), m_isDigital(false), m_analogWetThreshold(analogWetThreshold), m_callback(nullptr)
{
}

bool MoistureSensor::IsWet()
{
    if (m_isDigital)
    {
        return m_lastDigitalReading == LOW;
    }
    else
    {
        return m_lastAnalogReading >= m_analogWetThreshold;
    }
}

void MoistureSensor::SetCallback(MoistureSensorCallback* callback)
{
    m_callback = callback;
}

void MoistureSensor::Update()
{
    if (m_isDigital)
    {
        updateDigital();
    }
    else
    {
        updateAnalog();
    }
}

void MoistureSensor::updateDigital()
{
    int prev = m_lastDigitalReading;
    m_lastDigitalReading = digitalRead(m_pin);

    if (m_lastDigitalReading != prev && m_callback != nullptr)
    {
        m_callback->MoistureCallback(m_pin, IsWet());
    }
}

void MoistureSensor::updateAnalog()
{
    int prev = m_lastAnalogReading;
    m_lastAnalogReading = analogRead(m_pin);

    if (m_lastAnalogReading >= prev && m_callback != nullptr)
    {
        m_callback->MoistureCallback(m_pin, IsWet());
    }
}
