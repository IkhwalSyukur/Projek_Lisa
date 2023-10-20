#include "mygyro.h"

MPU6050 mpu6050(Wire);

bool GyroHandler::begin()
{
    Serial.begin(115200);
    Wire.begin();
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);

    return true;
}

void GyroHandler::data()
{
    mpu6050.update();
    Serial.print("angleX : ");
    Serial.print(mpu6050.getAngleX());
    Serial.print("\tangleY : ");
    Serial.print(mpu6050.getAngleY());
    Serial.print("\tangleZ : ");
    Serial.println(mpu6050.getAngleZ());
    vTaskDelay(300);
}

// void GyroHandler::Calc(int tanggalset)
// {
    
//     int tanggalnow = waktu.tanggal();
//     int jamnow = waktu.jam();
//     if (tanggalnow == tanggalset){
//         Serial.println("uji coba 1 works");
//     }

//     vTaskDelay(3000); 
// }

