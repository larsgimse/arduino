int el1 = 13;
int el2 = 12;
int el3 = 11;
int el4 = 10;
int el5 = 9;

void setup() {
       Serial.begin(115200);
       pinMode(el1, OUTPUT);
       pinMode(el2, OUTPUT);
       pinMode(el3, OUTPUT);
       pinMode(el4, OUTPUT);
       pinMode(el5, OUTPUT);
}

void loop() {

   while (Serial.available() > 0 ) {

     String str = Serial.readString();

     if (str.equals("off")) {
        digitalWrite(el1, LOW);
        digitalWrite(el2, LOW);
        digitalWrite(el3, LOW);
        digitalWrite(el4, LOW);
        digitalWrite(el5, LOW);
     }

     else if (str.equals("el1on")) {
        digitalWrite(el1, HIGH);
     }

     else if (str.equals("el1off")) {
        digitalWrite(el1, LOW);
     }

     else if (str.equals("el2on")) {
        digitalWrite(el2, HIGH);
     }

     else if (str.equals("el2off")) {
        digitalWrite(el2, LOW);
     }

     else if (str.equals("el3on")) {
        digitalWrite(el3, HIGH);
     }

     else if (str.equals("el3off")) {
        digitalWrite(el3, LOW);
     }
     else if (str.equals("el4on")) {
        digitalWrite(el4, HIGH);
     }

     else if (str.equals("el4off")) {
        digitalWrite(el4, LOW);
     }
     
     else if (str.equals("el5on")) {
        digitalWrite(el5, HIGH);
     }

     else if (str.equals("el5off")) {
        digitalWrite(el5, LOW);
     }

     else if (str.equals("on")) {
        digitalWrite(el1, HIGH);
        digitalWrite(el2, HIGH);
        digitalWrite(el3, HIGH);
        digitalWrite(el4, HIGH);
        digitalWrite(el5, HIGH);
     }
     
     else {
        digitalWrite(el1, LOW);
        digitalWrite(el2, LOW);
        digitalWrite(el3, LOW);
        digitalWrite(el4, LOW);
        digitalWrite(el5, LOW);
     }

   }

}
