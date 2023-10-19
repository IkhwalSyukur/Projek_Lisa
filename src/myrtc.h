#pragma once

#include <Arduino.h>
#include "RTClib.h"

class RTCHandler
{
    private:
        char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

    public:
        bool begin();
        void data();
};