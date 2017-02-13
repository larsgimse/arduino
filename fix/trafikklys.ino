// code with some errors

const int redPin = 11; 
const int yellowPin = 10; 
const int greenPin = 9; 

void setup(){
  pinMode(redPin, OUTPUT); 
  pinMode(yellowPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
}

void loop(){ 
 analogWrite(redPin, 10); 
 analogWrite(yellowPin, 0); 
 analogWrite(greenPin, 0); 
 delay(3000); 
 
 analogWrite(redPin, 10); 
 analogWrite(yellowPin, 255); 
 analogWrite(greenPin, 0); 
 delay(1500); 
 
 analogWrite(redPin, 255); 
 analogWrite(yellowPin, 0); 
 analogWrite(greenPin, 5); 
 delay(3000); 
 
 analogWrite(redPin, 0); 
 analogWrite(yellowPin, 255); 
 analogWrite(greenPin, 0); 
 delay(100); 
}
