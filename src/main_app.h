#pragma once

#include "mygyro.h"

GyroHandler gyro;

void task_gyro(void *pvParameter);

void setup()
{
    Serial.begin(115200);
    gyro.begin();

      xTaskCreate(
      task_gyro,
      "task for gyro",
      4096,
      NULL,
      1,
      NULL);
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