// search on setting > "C_Cpp.clang_format_fallbackStyle" change "VS Code" >
// "Google"
/* params:
  *  0: What port we'll use 0-13
  *  1: should be HIGH u LOW
  */
#include <LiquidCrystal.h>

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
  lcd.begin(16,2);
  // Serial.begin(9600);
  // Serial.println(HIGH);
  // Serial.println(LOW);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Juan Carlos");
  lcd.setCursor(0,1);
  lcd.print("es tonto");
}
