#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int LDRPin = A0;         
const int BuzzerPin = 8;        
const int PotPin = A1;         


LiquidCrystal_I2C lcd(0x27, 16, 2);  



void setup() {
  lcd.init();                   
  lcd.backlight();              
  pinMode(BuzzerPin, OUTPUT);   
}

void loop() {

  int LDRValue = analogRead(LDRPin);     
  int volume = analogRead(PotPin);      
  int volumeMapped = map(volume, 0, 1023, 0, 255);  
  float VoltageOnLDR = (10*LDRValue)/1023.0;
  
  lcd.setCursor(0, 0);
  lcd.print("Tensao :");
  lcd.print(VoltageOnLDR);
  lcd.print("V");

  noTone(BuzzerPin);

  lcd.setCursor(0, 1);
  lcd.print("                "); 
  
  if (VoltageOnLDR < 1.00) {
    lcd.setCursor(0, 1);
    lcd.print("Escuro");
    tone(BuzzerPin, 1000);   
  }
  else if (VoltageOnLDR < 2.30) {
    lcd.setCursor(0, 1);
    lcd.print("Meio Claro");
    noTone(BuzzerPin);               
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Claro");
    noTone(BuzzerPin);               
  }
  
  delay(500);  
}
