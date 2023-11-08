#include <Arduino.h>
#include "myMotor.h"

void myMotor::init()
{
    pinMode(motorPWMR, OUTPUT);
    pinMode(motorPWML, OUTPUT);
    pinMode(motorDIRR, OUTPUT);
    pinMode(motorDIRL, OUTPUT);

    pinMode(motor2PWMR, OUTPUT);
    pinMode(motor2PWML, OUTPUT);
    pinMode(motor2DIRR, OUTPUT);
    pinMode(motor2DIRL, OUTPUT);
    
    digitalWrite(motorDIRL,HIGH);
    digitalWrite(motorDIRR,HIGH);
    digitalWrite(motor2DIRL,HIGH);
    digitalWrite(motor2DIRR,HIGH);
    }

void myMotor::kanan(int pwm)
{
    analogWrite(motorPWMR, 0);  // Adjust the value (0-255) to control motor speed
    analogWrite(motorPWML, pwm);
    Serial.println("Kanan");
}

void myMotor::kiri(int pwm)
{
    analogWrite(motorPWMR, pwm);  // Adjust the value (0-255) to control motor speed
    analogWrite(motorPWML, 0);
    Serial.println("Kiri");
}

void myMotor::stop()
{
    analogWrite(motorPWMR, 0);  // Adjust the value (0-255) to control motor speed
    analogWrite(motorPWML, 0);
    analogWrite(motor2PWMR,0);
    analogWrite(motor2PWML,0);
    Serial.println("Stop");
}

void myMotor::motor2kanan(int pwm)
{
    analogWrite(motor2PWMR, pwm);  // Adjust the value (0-255) to control motor speed
    analogWrite(motor2PWML, 0);
    Serial.println("Motor 2 Kanan");
}

void myMotor::motor2kiri(int pwm)
{
    analogWrite(motor2PWMR, 0);  // Adjust the value (0-255) to control motor speed
    analogWrite(motor2PWML, pwm);
    Serial.println("Motor 2 Kiri");
}

void myMotor::motor2stop()
{
    analogWrite(motorPWMR, pwmR);  // Adjust the value (0-255) to control motor speed
    analogWrite(motorPWML, pwmR);
    Serial.println("Motor 2 Stop");
}
