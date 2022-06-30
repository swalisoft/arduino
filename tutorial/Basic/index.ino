const int pin = 2;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  digitalWrite(pin, LOW);
  delay(500);
  digitalWrite(pin, HIGH);
  delay(500);
}