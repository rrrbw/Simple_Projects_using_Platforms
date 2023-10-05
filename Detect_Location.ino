#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

unsigned long last = 0UL;


int LEDPin = 12;


void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
  pinMode(LEDPin, OUTPUT);
}

void loop()
{
  
  while (ss.available() > 0)
    gps.encode(ss.read());

  if (gps.location.isUpdated())
  {
    Serial.print(F("  Lat="));
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(" Long="));
    Serial.println(gps.location.lng(), 6);
  }



  else if (millis() - last > 5000)
  {
    Serial.println();
    if (gps.location.isValid())
    {
      static const double Dest_LAT = 18.786254, Dest_LON = 73.880798;
      double distanceToDest =
        TinyGPSPlus::distanceBetween(
          gps.location.lat(),
          gps.location.lng(),
          Dest_LAT, 
          Dest_LON
          );
      

      Serial.print(F("Distance to Destination ="));
      Serial.print(distanceToDest/1000, 6);    
      
      if(distanceToDest/1000 < 0.050000)   
      }
      else
      {
        digitalWrite(LEDPin, LOW);
      } 

} 

if (gps.charsProcessed() < 10) 

    Serial.println(F("WARNING!: No GPS data."));
    last = millis(); 
    Serial.println(); 

 }
}