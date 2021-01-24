#include <TinyGPS++.h>           
#include <SoftwareSerial.h>      

#define NEOSS_RX    10                // Arduino RX pin
#define NEOSS_TX    11                // Arduino TX pin
SoftwareSerial neoSS(NEOSS_RX, NEOSS_TX);
TinyGPSPlus gps;

bool updateLoc(double &lat, double &lon, unsigned long timeoutms);

void setup() {
  Serial.begin(9600);
  neoSS.begin(9600);
}

void loop() {
  double LAT, LON;
  bool loc_available = updateLoc(LAT, LON, 5000);
  if (loc_available) {
    Serial.print("LAT: ");
    Serial.println(LAT, 6);
    Serial.print("LON: ");
    Serial.println(LON, 6);
  } else {
    Serial.println("Loc unavailable");
  }
  Serial.println("------------------");
  delay(5000);
}

bool updateLoc(double &lat, double &lon, unsigned long timeoutms) {
  unsigned long start_time = millis();
  while (millis() - start_time < timeoutms) {
    while (neoSS.available() > 0) {
      if (gps.encode(neoSS.read())) {
        if (gps.location.isValid()) {
          lat = gps.location.lat();
          lon = gps.location.lng();
          return true;
        }
      }
    }
  }
  return false;
}
