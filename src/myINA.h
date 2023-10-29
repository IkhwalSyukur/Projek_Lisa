#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

class InaHandler
{
public:
    void init();
    void data();
    float BusVoltage();
    float ShuntVoltage();
    float Current();
    float Power();
};