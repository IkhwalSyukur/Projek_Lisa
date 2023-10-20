#include <Arduino.h>

const int tanggalSize = 13;  // Define the size of the array
const int sudutSize = 13;

// Create an std::array
std::array<int, tanggalSize> mytanggal;
std::array<float, sudutSize> mysudut;

void setup() {
  Serial.begin(115200);

  // Add items to the std::array
  mytanggal[0] = 23;
  mytanggal[1] = 24;
  mytanggal[2] = 25;
  mytanggal[3] = 26;
  mytanggal[4] = 27;
  mytanggal[5] = 28;
  mytanggal[6] = 29;
  mytanggal[7] = 30;
  mytanggal[8] = 31;
  mytanggal[9] = 1;
  mytanggal[10] = 2;
  mytanggal[11] = 3;
  mytanggal[12] = 4;

  mysudut[0] = -12.47215613;
  mysudut[1] = -12.81315031;
  mysudut[2] = -13.15034767;
  mysudut[3] = -13.4836483;
  mysudut[4] = -13.81295343;
  mysudut[5] = -14.13816549;
  mysudut[6] = -14.4591881;
  mysudut[7] = -14.77592614;
  mysudut[8] = -15.08828576;
  mysudut[9] = -15.39617439;
  mysudut[10] = -15.69950081;
  mysudut[11] = -15.99817512;
  mysudut[12] = -16.29210883;

  int targetItem = 27;
  int foundIndex = -1;  // Initialize foundIndex to -1 (not found)

  for (int i = 0; i < mytanggal.size(); i++) {
    if (mytanggal[i] == targetItem) {
      foundIndex = i;
      break;  // Exit the loop when the item is found
    }
  }

  if (foundIndex != -1) {
    Serial.println("Item found at index " + String(foundIndex));
  } else {
    Serial.println("Item not found in the array");
  }

    // Find and print an item based on index
  int index = foundIndex;
  if (index >= 0 && index < mysudut.size()) {
    Serial.println(mysudut[index]);
  } else {
    Serial.println("Index out of bounds");
  }
}

void loop() {
  // Your main code here
}
