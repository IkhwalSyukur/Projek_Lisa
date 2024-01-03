#pragma once
#include <Arduino.h>
const int relay1 = 5;

void setup(){
    Serial.begin(115200);
    pinMode (relay1, OUTPUT);
}

void loop(){
    digitalWrite(relay1,HIGH);
    Serial.println("Relay High");
    delay(2000);
    digitalWrite(relay1, LOW);
    Serial.println("Relay LOW");
    delay(2000);
}