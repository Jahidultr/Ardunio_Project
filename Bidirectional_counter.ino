#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 7, 6, 5, 4, 3); // LCD pins
#define in A0
#define out A1
#define relay 2

int count = 0;

void IN() {
  count++;
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
  delay(700);
}

void OUT() {
  if (count > 0) { // Prevent negative counts
    count--;
  }
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
  delay(500);
}

void setup() {
  lcd.begin(16, 2); // Initialize LCD
  lcd.print("Visitor Counter");
  delay(300);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(relay, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
}

void loop() {
  if (digitalRead(in)) {
    IN();
  }
  if (digitalRead(out)) {
    OUT();
  }
  if (count <= 0) {
    lcd.clear();
    digitalWrite(relay, LOW);
    lcd.print("Nobody In Room");
    lcd.setCursor(0, 1);
    lcd.print("Light Is Off");
    delay(200);
  } else {
    digitalWrite(relay, HIGH);
  }
}
