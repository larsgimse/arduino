int ledPins[] = {2,3,4,5,6,7,8,12};
int const DEBUG = 0; // Test LED without Serial feedback
int twitter = 0;
int telleLed = A1;

int signalState;

void setup() {

  for(int i = 0; i < 8; i++) { 
      pinMode(ledPins[i],OUTPUT);
  }
 

  // Enabling communication
  Serial.begin(9600);

  // Test breadboard setup to LED
  if (DEBUG) {
    tweetReceived();
  }
}

void loop() {
  if (!DEBUG) {
    if (Serial.available()) {
      byte receivedValue = Serial.read() - '0';
      signalState = receivedValue;

      if (signalState == 1) {
        tweetReceived();
      }

      else if (signalState == 0) {
//        ledToggle(false);

      }
      
      Serial.flush();
    }
  }
}

// Flash the light when tweet is received
void tweetReceived() {
  twitter = twitter + 1;
  showBinNumber(twitter);
  if (twitter == 255) {
    twitter = 0;
     for (int i = 0; i < 3; i++) {
      ledToggle(true);
      delay(100);
      ledToggle(false);
      delay(100);
       
    }
  }
}


void ledToggle(boolean value) {
  if (value) 
  {
    analogWrite(telleLed, 1023);
  } 
  
  else
  {
    analogWrite(telleLed, 0);  
  }
}

void showBinNumber(int num) {
  for (int i=0; i<8; i++) {
    if (num%2)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
    num/=2;
  } 
}

