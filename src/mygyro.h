#pragma once

#include <Arduino.h>
#include "MPU6050_tockn.h"
#include "myrtc.h"

class GyroHandler
{
    public :
        bool begin();
        void data();
        void calc();
        float target();
        float now();
    
    private :
        // int tanggalset = 20;
};