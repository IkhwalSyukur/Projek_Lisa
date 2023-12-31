#include "myINA.h"
#include "LiquidCrystal_I2C.h"

Adafruit_INA219 ina219;
LiquidCrystal_I2C inalcd(0x27,16,2);


void InaHandler::init()
{
Serial.begin(115200);
inalcd.init();
inalcd.backlight();
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }
    
  Serial.println("Hello!");
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    inalcd.clear();
    inalcd.print("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  Serial.println("Measuring voltage and current with INA219 ...");
  inalcd.clear();
  inalcd.print("Measuring with INA219 ...");
}

void  InaHandler::data()
{
    float shuntvoltage = 0;
    float busvoltage = 0;
    float current_mA = 0;
    float loadvoltage = 0;
    float power_mW = 0;

    shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage = ina219.getBusVoltage_V();
    current_mA = ina219.getCurrent_mA();
    power_mW = ina219.getPower_mW();
    loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  // Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  // Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  // Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  // Serial.println("");

  vTaskDelay(1000);
}

float InaHandler::BusVoltage()
{
    float busvoltage = 0;
    busvoltage = ina219.getBusVoltage_V();
    return busvoltage;
}

float InaHandler::ShuntVoltage()
{
    float shuntvoltage = 0;
    shuntvoltage = ina219.getShuntVoltage_mV();
    return shuntvoltage;
}

float InaHandler::Current()
{
    float current_mA = 0;
    current_mA = ina219.getCurrent_mA();
    return current_mA/1000;
}

float InaHandler::Power()
{
    float power_mW = 0;
    power_mW = ina219.getPower_mW();
    return power_mW;
}