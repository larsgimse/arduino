//source code from https://gist.github.com/jamesotron/766994

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
int potPin = 2;
int val = 0;

void setup() {
  // Start off with the LED off.

  setColourRgb(0,0,0);
}

void loop() {
  
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {

    val = analogRead(potPin); //read pot value
    delay(val*10); //speed of rainbow cycle, value of pot (0-1024) * 10
    
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(5);
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
