#pragma once
#define BLYNK_TEMPLATE_ID "TMPL6N0JwVsOW"
#define BLYNK_TEMPLATE_NAME "Solar Tracker"
#define BLYNK_AUTH_TOKEN "72f6ZRtX_A6A_PgYWlPSJI9ND__YTh2n"
#include "WiFi.h"
#include "WiFiClient.h"
#include "BlynkSimpleEsp32.h"

#define BLYNK_PRINT Serial 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Variasi Aluminium 1";
char pass[] = "hapisahsyukur2";

BlynkTimer timer;

void SendSenser() {
  Blynk.virtualWrite(V6, 100);
}

BLYNK_WRITE(V8)
{ 
  if (param.asInt() == 1) {
    Serial.printf("Mode = %d\n", 1);
  }
  else {
    Serial.printf("Mode = %d\n", 0);
  } 
}

BLYNK_WRITE(V0){
  if (param.asInt()==1){
    Serial.printf("Kiri = %d\n", 1);
  }
  else{
    Serial.printf("Kiri = %d\n", 0);
  }
}

BLYNK_WRITE(V1){
  if (param.asInt()==1){
    Serial.printf("Kanan = %d\n", 1);
  }
  else{
    Serial.printf("Kanan = %d\n", 0);
  }
}

BLYNK_WRITE(V2){
  if (param.asInt()==1){
    Serial.printf("Depan = %d\n", 1);
  }
  else{
    Serial.printf("Depan = %d\n", 0);
  }
}

BLYNK_WRITE(V3){
  if (param.asInt()==1){
    Serial.printf("Belakang = %d\n", 1);
  }
  else{
    Serial.printf("Belakang = %d\n", 0);
  }
}

void setup() {
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
timer.setInterval(2000L, SendSenser);

}

void loop() {
  Blynk.run();
  timer.run();
}
