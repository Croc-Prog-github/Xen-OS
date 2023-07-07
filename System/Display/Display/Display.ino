#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Indirizzo I2C del display e dimensioni (16 colonne x 2 righe) //0x27 //0x3f

void setup() {
  lcd.init ();
  lcd.backlight ();  // Accendi la retroilluminazione del display
  lcd.setCursor(0, 0);  // Posiziona il cursore all'inizio della prima riga
  lcd.print("Hello, World!");  // Scrivi il testo sul display
}

void loop() {
  //Null
}