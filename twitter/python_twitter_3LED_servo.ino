/*
  * Author: Nicholas Bester
  * Title: Twitter Mention Test
  * Version: 0.1
  * Modify by Lars Gimse
*/

#include <Servo.h>

// Debuging variables
int const DEBUG = 0; // Test LED without Serial feedback

Servo myservo;

// LED control
int ledPin = A1;
int ledPin2 = A0;
int ledPin3 = 13;
int pos = 0;
int pos2 = 0;



// Value sent from Python
int signalState;

void setup() {
  // Transistor pin connection on board
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  myservo.attach(9);

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
        ledToggle(false);
        ledToggle2(false);
        ledToggle3(false);
        servo(false);

      }
      
      Serial.flush();
    }
  }
}

// Flash the light when tweet is received
void tweetReceived() {
  for (int i = 0; i < 3; i++) {
    ledToggle(true);
    delay(100);
    ledToggle2(true);
    ledToggle(false);
    delay(100);
    ledToggle2(false);
    ledToggle3(true);
    delay(100);
    ledToggle3(false);
  } 
    servo(true);
  }


// turn LED on and off
void ledToggle(boolean value) {
  if (value) {
    analogWrite(ledPin, 1023);
  } 
  
  else {
    analogWrite(ledPin, 0); 
  }
}

void ledToggle2(boolean value) {
  if (value) {
    analogWrite(ledPin2, 1023);
  } 
  
  else {
    analogWrite(ledPin2, 0);
  }
}

void ledToggle3(boolean value) {
  if (value) {
    digitalWrite(ledPin3, HIGH);
  }

  else {
    digitalWrite(ledPin3, LOW);
  }
}


void servo(boolean value) {
  if (value) {
    for (pos = 0; pos <= 180; pos += 1) { 
      myservo.write(pos);              
      delay(15);                       
    }
  for (pos = 180; pos >= 0; pos -= 1) {   
    myservo.write(pos);               
    delay(15);                        
  }
  }
    else {
    myservo.write(pos2);
  }
}



