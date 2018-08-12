#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

class MoistureSensorCallback
{
  public:
    virtual void MoistureCallback(int pin, bool isWet) = 0;
};

class MoistureSensor
{
  public:
    MoistureSensor(int pin);
    MoistureSensor(int pin, int analogWetThreshold);

    bool IsWet();
    void SetCallback(MoistureSensorCallback* callback);

    void Update();

  private:
    const int m_pin;
    const bool m_isDigital;
    const int m_analogWetThreshold;
    MoistureSensorCallback* m_callback;

    int m_lastAnalogReading;
    bool m_lastDigitalReading;

    void updateDigital();
    void updateAnalog();
};

#endif // MOISTURESENSOR_H
