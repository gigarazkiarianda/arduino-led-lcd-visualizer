#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


const int ledPin = 13;


const int strobeInterval = 50;

void setup() {
  
  lcd.begin(16, 2);

  
  pinMode(ledPin, OUTPUT);
}

void strobeLED(int duration) {
  unsigned long endTime = millis() + duration;
  while (millis() < endTime) {
    digitalWrite(ledPin, HIGH); 
    delay(strobeInterval); 
    digitalWrite(ledPin, LOW); 
    delay(strobeInterval); 
}

void loop() {
  String message = "Giga Razki Arianda";
  
  
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  for (int i = 0; i < message.length(); i++) {
    lcd.print(message[i]);
    
    
    strobeLED(250); 
  }
  
  delay(2000); 

  
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.scrollDisplayLeft(); // Scroll the display left

    
    strobeLED(250); 
  }

  delay(2000); 
}
