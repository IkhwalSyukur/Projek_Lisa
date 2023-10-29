#pragma once
#include <Arduino.h>

const int ldr1 = 34;
const int ldr2 = 35;
const int ldr3 = 32;
const int ldr4 = 33;


void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.printf("LDR1 = %d\n", analogRead(ldr1));
    vTaskDelay(500);
}