// search on setting > "C_Cpp.clang_format_fallbackStyle" change "VS Code" >
// "Google"

#include <LiquidCrystal.h>

const int firstPin = 2;
const int secondPin = 3;

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  /* params:
   *  0: What port we'll use 0-13
   *  1: should be INPUT u OUTPUT
   */
//  pinMode(firstPin, OUTPUT);
//  pinMode(secondPin, OUTPUT);

  lcd.begin(16,2);

  // Serial.begin(9600);
  // Serial.println(HIGH);
  // Serial.println(LOW);
}

void loop() {
  /* params:
   *  0: What port we'll use 0-13
   *  1: should be HIGH u LOW
   */

  lcd.setCursor(0,0);
  lcd.print("Aron Puto");
//
//  for (int i = 2; i < 4; i++) {
//    if (i % 2 == 0) {
//      digitalWrite(firstPin, 1);
//      digitalWrite(secondPin, 0);
//    } else {
//      digitalWrite(firstPin, 0);
//      digitalWrite(secondPin, 1);
//    }
//
//    delay(500);  // on milliseconds
//  }
}
