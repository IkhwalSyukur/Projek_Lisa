#pragma once

#define BLYNK_TEMPLATE_ID "TMPL6N0JwVsOW"
#define BLYNK_TEMPLATE_NAME "Solar Tracker"
#define BLYNK_AUTH_TOKEN "72f6ZRtX_A6A_PgYWlPSJI9ND__YTh2n"
#include "WiFi.h"
#include "WiFiClient.h"
#include "BlynkSimpleEsp32.h"

#define BLYNK_PRINT Serial 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "hotspotAP";
char pass[] = "hotspotAP123";

// char ssid[] = "Variasi Aluminium 1";
// char pass[] = "hapisahsyukur2";

#include "mygyro.h"
#include "myrtc.h"
#include "myINA.h"
#include "myLDR.h"
#include "myMotor.h"


GyroHandler gyro;
RTCHandler waktu;
InaHandler ina;
LDRHandler ldr;
BlynkTimer timer;
myMotor mymotor;

int kontrol=0;

void task_gyro(void *pvParameter);
void task_rtc(void *pvParameter);
void task_ina(void *pvParameter);
void task_ldr(void *pvParameter);
void task_Azimuth(void *pvParameter);

void SendSensor() {
  // Blynk.virtualWrite(V4, ina.BusVoltage());
  // Blynk.virtualWrite(V5, ina.Current());
  Blynk.virtualWrite(V6, gyro.target());
  Blynk.virtualWrite(V7, gyro.now());
}

BLYNK_WRITE(V8)
{ 
  if (param.asInt() == 1) {
    Serial.printf("Mode = %d\n", 1);
    kontrol=1;
  }
  else {
    Serial.printf("Mode = %d\n", 0);
    kontrol=0;
  } 
}

BLYNK_WRITE(V0){
  if (param.asInt()==1){
    Serial.printf("Depan = %d\n", 1);
    mymotor.kiri(70);
  }
  else{
    Serial.printf("Depan = %d\n", 0);
    mymotor.stop();
  }
}

BLYNK_WRITE(V1){
  if (param.asInt()==1){
    Serial.printf("Belakang = %d\n", 1);
    mymotor.kanan(90);
  }
  else{
    Serial.printf("Belakang = %d\n", 0);
    mymotor.stop();
  }
}

BLYNK_WRITE(V2){
  if (param.asInt()==1){
    Serial.printf("Kiri = %d\n", 1);
    mymotor.motor2kiri(90);
  }
  else{
    Serial.printf("Kanan = %d\n", 0);
    mymotor.stop();
  }
}

BLYNK_WRITE(V3){
  if (param.asInt()==1){
    Serial.printf("Kanan = %d\n", 1);
    mymotor.motor2kanan(90);
  }
  else{
    Serial.printf("Belakang = %d\n", 0);
    mymotor.stop();
  }
}

void setup()
{
    Serial.begin(115200);
    gyro.begin();
    waktu.begin();
    // ina.init();
    ldr.begin();
    Blynk.begin(auth, ssid, pass);
    timer.setInterval(1000L, SendSensor);
    xTaskCreatePinnedToCore(task_gyro, "Handle gyro task", 1024 * 4 , NULL, 15, NULL, 1);
    // xTaskCreatePinnedToCore(task_ina, "Handle INA task", 1024 * 4 , NULL, 5, NULL, 1);
    // xTaskCreatePinnedToCore(task_ldr,"Handle LDR and bottom motor", 1024*2, NULL, 1, NULL, 1);    
    xTaskCreatePinnedToCore(task_Azimuth, "Handle Azimuth task", 1024 * 4 , NULL, 5, NULL, 1);
    
}

void loop()
{
  vTaskDelete(NULL);
}

void task_gyro(void  *pvParameter){
    while (1)
    { 
      Blynk.run();
      timer.run();
      if(kontrol == 0){
        Serial.printf ("Kontrol = %d\n", kontrol);
        gyro.calc();
      }
      else if (kontrol == 1)
      {
        Serial.printf ("Kontrol = %d\n", kontrol);
        gyro.data();
      }
      
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
        // Blynk.run();
        // timer.run();
    }
    
}

void task_ldr(void *pvParameter){
    while (1)
    {
      if(kontrol == 0){
        ldr.read();
      }
      else if (kontrol == 1)
      {
        ldr.readM();
      }
      
    }
}

void task_Azimuth(void *pvParameter){
  while (1)
  {
    gyro.ajimuth();
    // vTaskDelay(1000);
  }
  
}