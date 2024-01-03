#include "mygyro.h"
#include "myMotor.h"
#include "LiquidCrystal_I2C.h"
#include "mysolar.h"

MPU6050 mpu6050(Wire);
RTCHandler mytime;
myMotor motorA;
SolarPositionDemo solar;
LiquidCrystal_I2C lcd(0x27,16,2);

bool GyroHandler::begin()
{
    Serial.begin(115200);
    Wire.begin();
    lcd.init();
    lcd.backlight();
    mpu6050.begin();
    lcd.print("Calibrating...");
    mpu6050.calcGyroOffsets(true);
    motorA.init();
    

    return true;
}

void GyroHandler::data()
{
    mpu6050.update();
    float suduttarget = mytime.hasilsudut();
    float sudutnow = mpu6050.getAngleX();
    float updatesudut = mytime.hasilsudut() + mytime.sudutupdate();
    // Serial.printf("Sudut now : %f\n", sudutnow);
    // Serial.printf("Sudut Target : %f\n", updatesudut);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("S.T= ");
    lcd.setCursor(4,0);
    lcd.print(updatesudut,0);
    lcd.setCursor(0,1);
    lcd.print("S.S= ");
    lcd.setCursor(4,1);
    lcd.print(sudutnow,0);

    if (suduttarget != updatesudut){
        suduttarget = updatesudut;
    }
    vTaskDelay(100);
}

void GyroHandler::calc()
{
    mpu6050.update();
    float suduttarget = mytime.hasilsudut();
    float sudutnow = mpu6050.getAngleX();
    float updatesudut = mytime.hasilsudut() + mytime.sudutupdate();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("S.T= ");
    lcd.setCursor(4,0);
    lcd.print(updatesudut,0);
    lcd.setCursor(0,1);
    lcd.print("S.S= ");
    lcd.setCursor(4,1);
    lcd.print(sudutnow,0);

    if (suduttarget != updatesudut){
        suduttarget = updatesudut;
    }

    if (int(sudutnow)<int(suduttarget-3)){
        Serial.printf("Sudut now : %f\n", sudutnow);
        Serial.printf("Sudut Target : %f\n", suduttarget);
        Serial.println("Maju");
        motorA.kiri(70);
    }
    else if (int(sudutnow)>int(suduttarget+3))
    {
        Serial.printf("Sudut now : %f\n", sudutnow);
        Serial.printf("Sudut Target : %f\n", suduttarget);
        Serial.println("Mundur");
        motorA.kanan(70);
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

void GyroHandler::ajimuth()
{
    mpu6050.update();
    int detik = mytime.lastsecond();
    float azimuth_target = (solar.runDemo(detik));
    float azimuth_now = mpu6050.getAngleZ();
    Serial.printf("Azimuth = %.2f\n", azimuth_target);
    Serial.printf("Sudut Z = %.2f\n", azimuth_now);

    // lcd.clear();
    lcd.setCursor(8,0);
    lcd.print("A.T= ");
    lcd.setCursor(13,0);
    lcd.print(azimuth_target,0);
    lcd.setCursor(8,1);
    lcd.print("A.S= ");
    lcd.setCursor(13,1);
    lcd.print(azimuth_now,0);

    vTaskDelay(100);
    
}

