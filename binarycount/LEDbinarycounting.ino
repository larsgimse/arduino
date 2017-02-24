//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// 12 + 3 LED binary counting
// 
// Made by Lars Gimse
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4112913-12-led-binary-counting

/*    
 *
 * Taken from this circuit http://tinyurl.com/d2hrud
 *
 */
 
int ledPins[] = {2,3,4,5,6,7,8,9,10,11,12,13};
int ledPins2[] = {A0,A1,A2};
int var = 0;
int lap = 0;

void setup()
{
  Serial.begin(9600);
  
  for(int i = 0; i < 12; i++){      
      pinMode(ledPins[i],OUTPUT);
  	}
  for(int j = 0; j < 3; j++){      
      pinMode(ledPins2[j],OUTPUT);
  	}
  }                                   
 
 
void loop()                   
{

  for (int i=0; i<=4096; i++) {
    showBinNumber(i);
    showBinNumber2(lap);
    Serial.println(i);
    Serial.println(lap);

    delay(5);
    if (i == 4096) {
		while(var < 20){
    		showBinNumber(i -1);
     		delay(100);
    		showBinNumber(0);
     		delay(100);
            var++;
		}

      delay(100);
    	showBinNumber2(lap);

      int i = 0;
      lap++;
    }
  }
}

void showBinNumber(int num) {
  for (int i=0; i<12; i++) {
    if (num%2)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
    num/=2;
  } 
}

void showBinNumber2(int num2) {
  for (int j=0; j<3; j++) {
    if (num2%2)
      digitalWrite(ledPins2[j], HIGH);
    else
      digitalWrite(ledPins2[j], LOW);
    num2/=2;
  } 
}

