long randNumber;

int el1 = 13;
int el2 = 12;
int el3 = 11;
int el4 = 10;
int el5 = 9;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(el1, OUTPUT);
  pinMode(el2, OUTPUT);
  pinMode(el3, OUTPUT);
  pinMode(el4, OUTPUT);
  pinMode(el5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  randNumber = random(1,10) * 100;
  Serial.println(randNumber);
  digitalWrite(el1, HIGH);
  digitalWrite(el2, LOW);
  digitalWrite(el3, HIGH);
  digitalWrite(el4, LOW);
  digitalWrite(el5, HIGH);
  delay(randNumber);
  digitalWrite(el1, LOW);
  digitalWrite(el2, HIGH);
  digitalWrite(el3, LOW);
  digitalWrite(el4, HIGH);
  digitalWrite(el5, LOW);
  delay(randNumber);
}
