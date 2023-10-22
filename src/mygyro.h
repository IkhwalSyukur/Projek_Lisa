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
    
    private :
        // int tanggalset = 20;
};