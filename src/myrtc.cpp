#include "myrtc.h"

RTC_DS3231 rtc;
ArrayHandler mydata;

bool RTCHandler::begin()
{
    mydata.init();
    if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
    }

    if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }

    return true;
}

void RTCHandler::data()
{
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    vTaskDelay(500);
}

int RTCHandler::tanggal()
{
    DateTime now = rtc.now();
    return now.day();
}

int RTCHandler::bulan()
{
    DateTime now = rtc.now();
    return now.month();
}

int RTCHandler::jam()
{
    DateTime now = rtc.now();
    return now.hour();
}

void RTCHandler::calc(int tanggalset)
{
    DateTime now = rtc.now();
    int tanggalnow = now.day();
    if (tanggalnow == tanggalset){
        Serial.println("tes 1 success");
    }
    else{
        Serial.println("tes failed");
    }
    vTaskDelay(300);
}

float RTCHandler::hasilsudut(int tanggalacuan)
{
    int myindex = mydata.data(tanggalacuan);
    float sudutnya = mydata.sudut(myindex);
    vTaskDelay(500);
    return sudutnya;    
}