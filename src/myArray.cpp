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
  thistanggal[0] = 5;
  thistanggal[1] = 6;
  thistanggal[2] = 7;
  thistanggal[3] = 8;
  thistanggal[4] = 9;
  thistanggal[5] = 10;
  thistanggal[6] = 11;
  thistanggal[7] = 12;
  thistanggal[8] = 13;
  thistanggal[9] = 14;
  thistanggal[10] = 15;
  thistanggal[11] = 16;
  thistanggal[12] = 17;

  thissudut[0] = -16,58121484;
  thissudut[1] = -16,86540747;
  thissudut[2] = -17,14460252;
  thissudut[3] = -17,41871725;
  thissudut[4] = -17,68767045;
  thissudut[5] = -17,9513824;
  thissudut[6] = -18,20977497;
  thissudut[7] = -18,7102973;
  thissudut[8] = -18,95227874;
  thissudut[9] = -19,18864421;
  thissudut[10] = -19,41932367;
  thissudut[11] = -19,64424877;
  thissudut[12] = -19,86335285;
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