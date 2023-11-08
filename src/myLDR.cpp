#include "myLDR.h"
#include "myMotor.h"

myMotor motor;

const int ldr1 = 34;
const int ldr2 = 35;
const int ldr3 = 32;
const int ldr4 = 33;


void LDRHandler::begin()
{
    Serial.begin(115200);
    motor.init();
    pinMode(ldr1, INPUT_PULLUP);
    pinMode(ldr2, INPUT_PULLUP);
    pinMode(ldr3, INPUT_PULLUP);
    pinMode(ldr4, INPUT_PULLUP);
}

void  LDRHandler::read()
{
    int read1 = analogRead(ldr1);
    int read2 = analogRead(ldr2);
    int read3 = analogRead(ldr3);
    int read4 = analogRead(ldr4);

    Serial.printf("LDR1 = %d\n", read1);
    Serial.printf("LDR2 = %d\n", read2);
    Serial.printf("LDR3 = %d\n", read3);
    Serial.printf("LDR4 = %d\n", read4);

    if(read4<100 && read2>100)
    {
        motor.motor2kanan(200);
        motor.kanan(200);
    }

    else if (read2<100 && read4>100)
    {
        motor.motor2kiri(200);
        motor.kiri(200);
    }

    else{
        motor.stop();
    }

    vTaskDelay(100);
}