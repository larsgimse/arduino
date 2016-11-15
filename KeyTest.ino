void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Analog Input: ");
  Serial.println(analogRead(A0)); // Endre til A1, A2... for de andre portene

}
