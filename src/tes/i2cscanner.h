#include <Arduino.h>
#include <Wire.h>

#define SDA_2 17
#define SCL_2 16

void setup()
{
  Wire.begin();
  Wire1.begin(SDA_2, SCL_2);
  Serial.begin(115200);
  while (!Serial);             
  Serial.println("\nI2C Scanner");
}

void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
//    Wire1.beginTransmission(address);
    error = Wire.endTransmission();
//    error = Wire1.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
      Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
     }
     else if (error==4)
     {
      Serial.print("Unknown error at address 0x");
      if (address<16)
         Serial.print("0");
      Serial.println(address,HEX);
     }    
    }
    if (nDevices == 0)
       Serial.println("No I2C devices found\n");
    else
       Serial.println("done\n");
      
  byte error1, address1;
  int nDevices1;
  Serial.println("Scanning...");
  nDevices1 = 0;
  for(address1 = 1; address1 < 127; address1++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
//    Wire.beginTransmission(address);
    Wire1.beginTransmission(address1);
//    error = Wire.endTransmission();
    error1 = Wire1.endTransmission();
    if (error1 == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address1<16)
         Serial.print("0");
      Serial.print(address1,HEX);
      Serial.println("  !");
      nDevices1++;
     }
     else if (error1==4)
     {
      Serial.print("Unknown error at address 0x");
      if (address1<16)
         Serial.print("0");
      Serial.println(address1,HEX);
     }    
    }
    if (nDevices1 == 0)
       Serial.println("No I2C devices found\n");
    else
       Serial.println("done\n");
    delay(5000);           // wait 5 seconds for next scan
}