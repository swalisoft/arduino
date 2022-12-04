#include "DHT.h"
#include <FirebaseArduino.h> 
#include <ESP8266WiFi.h>

#define DHT_PIN 5 // GPIO5 = D1
#define LED_PIN 2 // GPIO2 = D4

#define DHT_TYPE DHT11
#define LM35_ANALOG A0

#define FIREBASE_HOST "arduino-conector-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "iufGVltFp8EuGtNsx1GNxeiUNgJQC9j3xGtSjMzQ"

#define WIFI_SSID "TIGO-F50D"
#define WIFI_PASSWORD "Jhomani123"

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_PIN, OUTPUT); // LED config

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Connect via WIFI

  while (WiFi.status() != WL_CONNECTED) { // wait while connecting
    Serial.println("Connecting...");
    delay(500);
  }

  Serial.println("Connected to: " + WiFi.localIP());

  // Init firebase connection
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
  dht.begin();
}

void loop() {

  managerLedActions();
  showDHTOutputs(); 
  showLM35Outputs();

  delay(200);
}

void managerLedActions() {
  bool ledOn = Firebase.getBool("ledOn");

  Serial.println("LED state: " + String(ledOn));

  if(ledOn) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

void showDHTOutputs() {
  float humidity = dht.readHumidity(); // on %
  float tempretureC = dht.readTemperature();  // on °C
  float tempretureF = dht.readTemperature(true);// on °Fahrenheit

  if (isnan(humidity) || isnan(tempretureC) || isnan(tempretureF)) {
    Serial.println("Falla al leer");
    return;
  }

  Serial.print("DHT: Humidity: " +  String(humidity) + " %");
  Serial.println("; Temperature: " + String(tempretureC) + " *C ");

  Firebase.setFloat("humidity", humidity);
  Firebase.setFloat("dhtTemperature", tempretureC);
}

void showLM35Outputs() {
  int ValorAnalogo = analogRead(LM35_ANALOG);
  
  float millivolts = (ValorAnalogo/1024.0) * 3300; //3300 es el voltaje proporcionado por NodeMCU
  float celsius = millivolts/10;
  
  Firebase.setFloat("temperature", celsius);

  Serial.println("LM35: Temperature *C= " + String(celsius));
}
