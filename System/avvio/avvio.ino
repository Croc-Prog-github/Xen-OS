void setup() {
  pinMode(13, OUTPUT);  // Imposta il pin 13 come OUTPUT
}

void loop() {
  digitalWrite(13, HIGH);  // Accendi il LED
  delay(100);  // Attendi 100 millisecondi
  digitalWrite(13, LOW);  // Spegni il LED
  delay(500);  // Attendi 100 millisecondi
}
