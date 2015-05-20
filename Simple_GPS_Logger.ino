#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

/*
  Author: Max from MaxTechTV
  This is a simple GPS-Coordinate-Datalogger using the TinyGPS++ Library, the Arduino Wifi Shield, a Micro SD Card and a ublox neo 6m Module
  It saves GPS Coordinates to a CSV File in a configurable Interval.
  
  It uses the TinyGPS++ Library (http://arduiniana.org/libraries/tinygpsplus/) written by Mikal Hart.
  
*/

static const int RXPin = 6, TXPin = 3;
static const uint32_t GPSBaud = 9600;
const int chipSelect = 4;

// set interval for data to be written to the SD Card

int interval = 5000;  //in ms

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {

  delay(1000);

  // Start Software Serial for GPS Module

  ss.begin(GPSBaud);

  // Try to create SD instance

  if (!SD.begin(chipSelect)) {
    return;
  }

  // Check if CSV File already exists, if not create it with header information

  if (!SD.exists("datalog.csv")) {
    File dataFile = SD.open("datalog.csv", FILE_WRITE);
    if (dataFile) {
      dataFile.println("longitude,latitude,altitude");
      dataFile.close();
    }
  }
}

void loop() {

  // Get informationen from the gps module and pass it to the tinyGPS instance

  while (ss.available() > 0)
    if (gps.encode(ss.read()))

      // Write informationen to the SD Card in configured interval

      if ((millis() - millis1) > interval) {
        printInfo();
        millis1 = millis();
      }
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    while (true);
  }
}


void printInfo()
{

  // check if data is valid

  if (gps.location.isValid())
  {

    // create String and write it to the SD card

    String dataString = "";
    dataString += String(gps.location.lat(), 6);
    dataString += ",";
    dataString += String(gps.location.lng(), 6);
    dataString += ",";
    dataString += gps.altitude.meters();

    File dataFile = SD.open("datalog.csv", FILE_WRITE);

    if (dataFile) {
      dataFile.println(dataString);
      dataFile.close();
    }
  }
}
