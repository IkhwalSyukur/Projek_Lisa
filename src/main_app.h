#pragma once

#include "mygyro.h"
#include "myrtc.h"

GyroHandler gyro;
RTCHandler waktu;

void task_gyro(void *pvParameter);
void task_rtc(void *pvParameter);

void setup()
{
    Serial.begin(115200);
    gyro.begin();
    waktu.begin();
    xTaskCreatePinnedToCore(task_gyro, "Handle gyro task", 1024 * 2 , NULL, 1, NULL, 1);
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