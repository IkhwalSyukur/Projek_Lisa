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
  thistanggal[0] = 27;
  thistanggal[1] = 28;
  thistanggal[2] = 29;
  thistanggal[3] = 30;
  thistanggal[4] = 31;
  thistanggal[5] = 1;
  thistanggal[6] = 2;
  thistanggal[7] = 3;
  thistanggal[8] = 4;
  thistanggal[9] = 5;
  thistanggal[10] = 6;
  thistanggal[11] = 7;
  thistanggal[12] = 8;

  thissudut[0] = -23,36412081;
  thissudut[1] = -23,31722192;
  thissudut[2] = -23,26341363;
  thissudut[3] = -23,2027119;
  thissudut[4] = -23,13513469;
  thissudut[5] = -23,06070205;
  thissudut[6] = -22,97943603;
  thissudut[7] = -22,8913607;
  thissudut[8] = -22,79650216;
  thissudut[9] = -22,69488853;
  thissudut[10] = -22,58654992;
  thissudut[11] = -22,47151842;
  thissudut[12] = -22,34982813;
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