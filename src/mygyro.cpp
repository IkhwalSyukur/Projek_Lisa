#include "mygyro.h"
#include "myMotor.h"
#include "LiquidCrystal_I2C.h"

MPU6050 mpu6050(Wire);
RTCHandler mytime;
myMotor motorA;
LiquidCrystal_I2C lcd(0x27,16,2);

bool GyroHandler::begin()
{
    Serial.begin(115200);
    Wire.begin();
    lcd.init();
    lcd.backlight();
    lcd.print("Calibrating...");
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);
    motorA.init();
    

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

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Target = ");
    lcd.setCursor(10,0);
    lcd.print(updatesudut);
    lcd.setCursor(0,1);
    lcd.print("Now = ");
    lcd.setCursor(7,1);
    lcd.print(sudutnow);

    if (suduttarget != updatesudut){
        suduttarget = updatesudut;
    }

    if (int(sudutnow)<int(suduttarget-2)){
        Serial.printf("Sudut now : %f\n", sudutnow);
        Serial.printf("Sudut Target : %f\n", suduttarget);
        Serial.println("Maju");
        motorA.kanan(200);
    }
    else if (int(sudutnow)>int(suduttarget+2))
    {
        Serial.printf("Sudut now : %f\n", sudutnow);
        Serial.printf("Sudut Target : %f\n", suduttarget);
        Serial.println("Mundur");
        motorA.kiri(200);
    }
    else{
        Serial.println("Standby");
        motorA.stop();
    }
    vTaskDelay(100);
}

float GyroHandler::target()
{
    mpu6050.update();
    float updatesudut = mytime.hasilsudut() + mytime.sudutupdate();
    return updatesudut;
}

float GyroHandler::now()
{
    mpu6050.update();
    float sudutnow = mpu6050.getAngleX();
    return sudutnow;
}

