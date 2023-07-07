#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Your_LCD_Class lcd;  // Sostituisci "Your_LCD_Library" e "Your_LCD_Class" con i nomi corretti della tua libreria LCD

void setup() {
  Serial.begin(9600);  // Inizializza il plotter seriale
  lcd.begin();  // Inizializza il display LCD
  lcd.backlight();  // Accendi la retroilluminazione del display
}

void loop() {
  // Leggi i dati dal display LCD
  String data = lcd.readData();  // Sostituisci "readData()" con il metodo corretto per leggere i dati dal tuo display LCD

  // Invia i dati al plotter seriale
  Serial.println(data);

  delay(1000);  // Attendi 1 secondo prima di leggere nuovamente i dati
}