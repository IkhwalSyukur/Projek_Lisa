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
    xTaskCreate(task_gyro,"task for gyro",4096,NULL,1,NULL);
    xTaskCreate(task_rtc,"task for rtc",4096,NULL,1,NULL);
}

void loop()
{
  vTaskDelete(NULL);
}

void task_gyro(void  *pvParameter){
    while (1)
    {
        gyro.data();
    }
}

void task_rtc(void  *pvParameter){
    while (1)
    {
        waktu.data();
    }
}