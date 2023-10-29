#pragma once

#include "mygyro.h"
#include "myrtc.h"
#include "myINA.h"

GyroHandler gyro;
RTCHandler waktu;
InaHandler ina;

void task_gyro(void *pvParameter);
void task_rtc(void *pvParameter);
void task_ina(void *pvParameter);

void setup()
{
    Serial.begin(115200);
    gyro.begin();
    waktu.begin();
    ina.init();
    xTaskCreatePinnedToCore(task_gyro, "Handle gyro task", 1024 * 2 , NULL, 15, NULL, 1);
    // xTaskCreatePinnedToCore(task_ina, "Handle INA task", 1024 * 2 , NULL, 5, NULL, 1);
    // xTaskCreatePinnedToCore(task_rtc, "Handle rtc task", 1024 *  2, NULL, 5, NULL, 1);
}

void loop()
{
  vTaskDelete(NULL);
}

void task_gyro(void  *pvParameter){
    while (1)
    {
        gyro.calc();
    }
}

void task_rtc(void  *pvParameter){
    while (1)
    {
        waktu.hasilsudut();
    }
}

void task_ina(void *pvParameter){
    while (1)
    {
        ina.data();
    }
    
}