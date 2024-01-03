#pragma once
#include <Arduino.h>
#include <SolarPosition.h>

class SolarPositionDemo {
public:
  int runDemo(int detiknow) {
    // number of decimal digits to print
    const uint8_t digits = 3;

    // A solar position structure to demonstrate storing complete positions
    SolarPosition_t savedPosition;

    // a test position:
    // (43.6777, -79.6248) Toronto, Canada airport (YYZ)
    const float Latitude = -0.8464090;
    const float Longitude = 119.8927907;

    Serial.begin(115200);
    // Serial.println(F("\tSolar Position Utility Function Demo"));

    // obtain a complete current position
    savedPosition = calculateSolarPosition(detiknow, Latitude * DEG_TO_RAD, Longitude * DEG_TO_RAD);
    // savedPosition = calculateSolarPosition(SECS_YR_2000, Latitude * DEG_TO_RAD, Longitude * DEG_TO_RAD);

    // Serial.print(F("The sun was at an elevation of "));
    // Serial.print(savedPosition.elevation * RAD_TO_DEG, 4);
    // Serial.print(F(" and an azimuth of "));
    // Serial.println(savedPosition.azimuth * RAD_TO_DEG, 4);
    // Serial.print(F("in YYZ airport at "));
    // printTime(savedPosition.time);

    // Serial.print(F("The earth was "));
    // Serial.print(savedPosition.distance * KM_PER_AU, 0);
    // Serial.println(F(" km from the Sun."));
    // Serial.println();

    // Serial.println(F("Finished..."));
    // Serial.println();

    return (savedPosition.azimuth * RAD_TO_DEG);
  }

private:
  static void printTime(time_t t) {
    tmElements_t someTime;
    breakTime(t, someTime);

    Serial.print(someTime.Hour);
    Serial.print(F(":"));
    Serial.print(someTime.Minute);
    Serial.print(F(":"));
    Serial.print(someTime.Second);
    Serial.print(F(" UTC on "));
    Serial.print(dayStr(someTime.Wday));
    Serial.print(F(", "));
    Serial.print(monthStr(someTime.Month));
    Serial.print(F(" "));
    Serial.print(someTime.Day);
    Serial.print(F(", "));
    Serial.println(tmYearToCalendar(someTime.Year));
  }
};

// void setup() {
//   SolarPositionDemo::runDemo();
// }

// void loop() {
//   // Your loop code here
// }
