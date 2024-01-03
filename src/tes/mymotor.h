#pragma once
#include <Arduino.h>

const int motorPWMR = 25;     // Connect to the PWM pin of the BTS7960
const int motorPWML = 26;
const int motorDIRR = 19;    // Connect to the input 1 of the BTS7960
const int motorDIRL = 18;    // Connect to the input 2 of the BTS7960

// const int motorPWMR = 12;     // Connect to the PWM pin of the BTS7960
// const int motorPWML = 13;
// const int motorDIRR = 27;    // Connect to the input 1 of the BTS7960
// const int motorDIRL = 14;

int pwmR = 70;

void setup() {
    Serial.begin(115200);
  pinMode(motorPWMR, OUTPUT);
  pinMode(motorPWML, OUTPUT);
  pinMode(motorDIRR, OUTPUT);
  pinMode(motorDIRL, OUTPUT);

  digitalWrite(motorDIRL,HIGH);
  digitalWrite(motorDIRR,HIGH);
}

void loop() {
  // Motor control
  analogWrite(motorPWMR, pwmR);  // Adjust the value (0-255) to control motor speed
  analogWrite(motorPWML, 0);
  Serial.println("Kanan");
  
  delay(1000);  // Run the motor in one direction for 2 seconds
  
  analogWrite(motorPWMR, 0);  // Adjust the value (0-255) to control motor speed
  analogWrite(motorPWML, pwmR);
  Serial.println("Kiri");
  delay(1000);  // Run the motor in the other direction for 2 seconds
}
