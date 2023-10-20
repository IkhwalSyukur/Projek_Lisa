#pragma once

#include <Arduino.h>
#include "MPU6050_tockn.h"

class GyroHandler
{
    public :
        bool begin();
        void data();
    
    private :
        // int tanggalset = 20;
};