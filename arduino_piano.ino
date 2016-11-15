void setup() {
  pinMode(8, OUTPUT); // port 8 to speaker

}

void loop() {
  if (analogRead(A0) < 1000) {
    tone(8, 262, 200); // tone C4
    delay(10);
  } 
  if (analogRead(A1) < 1000) {
    tone(8, 294, 200); // tone D4
    delay(10);
  }
  if (analogRead(A2) < 1000) {
    tone(8, 330, 200); // tone E4
    delay(10);
  }
  if (analogRead(A3) < 1000) {
    tone(8, 349, 200); // tone F4
    delay(10);
  }
  if (analogRead(A4) < 1000) {
    tone(8, 415, 200); // tone G4
    delay(10);
  }
  if (analogRead(A5) < 1000) {
    tone(8, 392, 200); // tone G4
    delay(10);
  }
}
