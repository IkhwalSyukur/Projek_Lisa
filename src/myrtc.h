#pragma once

#include <Arduino.h>
#include "RTClib.h"
#include "myArray.h"
#include "math.h"

class RTCHandler
{
    private:
        char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

    public:
        bool begin();
        void data();
        int tanggal();
        int bulan();
        int jam();
        void calc(int tanggalset);
        float hasilsudut();
        int sudutupdate();
        int lastsecond();
};