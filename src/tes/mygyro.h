
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 thismpu(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  thismpu.begin();
  thismpu.calcGyroOffsets(true);
}

void loop() {
  thismpu.update();
  Serial.print("angleX : ");
  Serial.print(thismpu.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(thismpu.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(thismpu.getAngleZ());
  delay(500);
}