#include "mygyro.h"

MPU6050 mpu6050(Wire);
RTCHandler mytime;

bool GyroHandler::begin()
{
    Serial.begin(115200);
    Wire.begin();
    mpu6050.begin();
    mpu6050.calcGyroOffsets();

    return true;
}

void GyroHandler::data()
{
    mpu6050.update();
    Serial.print("angleX : ");
    Serial.println(mpu6050.getAngleX());
    vTaskDelay(300);
}

void GyroHandler::calc()
{
    mpu6050.update();
    float suduttarget = mytime.hasilsudut();
    float sudutnow = mpu6050.getAngleX();
    float updatesudut = mytime.hasilsudut() + mytime.sudutupdate();

    if (suduttarget != updatesudut){
        suduttarget = updatesudut;
    }

    if (int(sudutnow)<int(suduttarget)){
        Serial.printf("Sudut now : %f\n", sudutnow);
        Serial.printf("Sudut Target : %f\n", suduttarget);
        Serial.println("Maju");
    }
    else if (int(sudutnow)>int(suduttarget))
    {
        Serial.printf("Sudut now : %f\n", sudutnow);
        Serial.printf("Sudut Target : %f\n", suduttarget);
        Serial.println("Mundur");
    }
    else{
        Serial.println("Standby");
    }
    vTaskDelay(100);
}

