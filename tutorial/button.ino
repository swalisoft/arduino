int primary = 7, bvalue;

void setup() {
  pinMode(primary, INPUT);

  Serial.begin(9600);
}

void loop() {
  bvalue = digitalRead(primary);

  if (bvalue) {
    Serial.println(bvalue);
  }
}
