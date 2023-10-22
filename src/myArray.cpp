#include "myArray.h"

const int tanggalSize = 13;  // Define the size of the array
const int sudutSize = 13;

// Create an std::array
std::array<int, tanggalSize> thistanggal;
std::array<float, sudutSize> thissudut;

void ArrayHandler::init()
{
    Serial.begin(115200);

  // Add items to the std::array
  thistanggal[0] = 23;
  thistanggal[1] = 24;
  thistanggal[2] = 25;
  thistanggal[3] = 26;
  thistanggal[4] = 27;
  thistanggal[5] = 28;
  thistanggal[6] = 29;
  thistanggal[7] = 30;
  thistanggal[8] = 31;
  thistanggal[9] = 1;
  thistanggal[10] = 2;
  thistanggal[11] = 3;
  thistanggal[12] = 4;

  thissudut[0] = -12.47215613;
  thissudut[1] = -12.81315031;
  thissudut[2] = -13.15034767;
  thissudut[3] = -13.4836483;
  thissudut[4] = -13.81295343;
  thissudut[5] = -14.13816549;
  thissudut[6] = -14.4591881;
  thissudut[7] = -14.77592614;
  thissudut[8] = -15.08828576;
  thissudut[9] = -15.39617439;
  thissudut[10] = -15.69950081;
  thissudut[11] = -15.99817512;
  thissudut[12] = -16.29210883;
}

int ArrayHandler::data(int targettanggal)
{
      int foundIndex = -1;
      for (int i = 0; i < thistanggal.size(); i++) {
        if (thistanggal[i] == targettanggal) {
        foundIndex = i;
      break;  // Exit the loop when the item is found
    }
  }

  if (foundIndex != -1) {
    // Serial.println("Item found at index " + String(foundIndex));
  } else {
    Serial.println("Item not found in the array");
  }

  return foundIndex;
}

float ArrayHandler::sudut(int dataindex)
{
  int index = dataindex;
  if (index >= 0 && index < thissudut.size()) {
    // Serial.println(thissudut[index]);
  } else {
    Serial.println("Index out of bounds");
  }
  return thissudut[index];
}