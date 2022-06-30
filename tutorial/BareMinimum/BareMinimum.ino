
#include <TinyGPS++.h>
#include <AltSoftSerial.h>
//--------------------------------------------------------------
//GPS Module RX pin to Arduino 9
//GPS Module TX pin to Arduino 8
AltSoftSerial neogps;
TinyGPSPlus gps;

// Size of the geo fence (in meters)
const float maxDistance = 30;

//--------------------------------------------------------------
float initialLatitude = 0;
float initialLongitude = 0;

float latitude, longitude;
//--------------------------------------------------------------

void getGps(float& latitude, float& longitude);

void setup() {
  Serial.begin(9600);

  neogps.begin(9600);
}

void loop() {
  //--------------------------------------------------------------
  getGps(latitude, longitude);
  //--------------------------------------------------------------
  //float distance = getDistance(latitude, longitude, initialLatitude, initialLongitude);
  //--------------------------------------------------------------
  Serial.print("Latitude= "); Serial.println(latitude, 6);
  Serial.print("Lngitude= "); Serial.println(longitude, 6);

  delay(1000);
}

void getGps(float& latitude, float& longitude) {
  // Can take up to 60 seconds
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 2000;){
    while (neogps.available()){
      if (gps.encode(neogps.read())){
        newData = true;
        break;
      }
    }
  }
  
  if (newData) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    newData = false;
  } else {
    Serial.println("No GPS data is available");
    latitude = 0;
    longitude = 0;
  }
}
