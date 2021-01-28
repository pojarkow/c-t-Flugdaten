/*
  c't Beispiel für Fludatenanzeige auf einem LC-Display
*/
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(A1, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, c't");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.clear();
  String s1; String s2; String s3;
  char t = ';';
  lcd.setCursor(0, 0);
  if (Serial.available() > 10) {
    s1 = Serial.readStringUntil(t);
    s2 = Serial.readStringUntil(t);
    s3 = Serial.readStringUntil(t);

    lcd.print("Alt " + s1);
    lcd.setCursor(0, 1);
    lcd.print("IAS " + s2);

  }
  //lcd.print(s1+s2+s3);
  /*lcd.print("Alt " + s1 + " ft");
    lcd.print(" Gear");
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    //lcd.print(millis() / 1000);
    //lcd.setCursor(5, 1);
    lcd.print("IAS 215 kts");
    lcd.print(" UP");
    delay(1000);*/
}
