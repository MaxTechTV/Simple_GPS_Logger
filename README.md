# Simple_GPS_Logger
A simple GPS Coordinate to MicroSD Card Logger using an Arduino.

Components:

* Arduino Board
* ublox GY-NEO6Mv2 GPS Module
* MicroSD Card
* Arduino Wifi Proto Shield

CAUTION: The GY-NEO6MV2 Module uses 3.3V Logic. Make sure to only connect The Modules TX Pin when using with a 5V Board to avoid destroying the Module.
I'm not responsible for any Damage!

It uses the [TinyGPS++ Library](http://arduiniana.org/libraries/tinygpsplus/) written by Mikal Hart.

Please make sure to install the Library before using this Sketch.
