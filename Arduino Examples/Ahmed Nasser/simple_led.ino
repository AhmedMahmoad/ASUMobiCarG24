/*
  Blinking LEDs - test program to run 3 LEDs in a pattern of blinks
*/

int yellowled = 12;
int greenled = 10;
int blueled = 7;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(yellowled, OUTPUT);   
  pinMode(greenled, OUTPUT);  
  pinMode(blueled, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(yellowled, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(80);                      // wait for 1/2 a second
  digitalWrite(yellowled, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(greenled, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(80);                      // wait for 1/2 a second
  digitalWrite(greenled, LOW);     // turn the LED off by making the voltage LOW
  digitalWrite(blueled, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(80);                      // wait for 1/2 a second
  digitalWrite(blueled, LOW);      // turn the LED off by making the voltage LOW
  delay(500);                     // wait for a second
}
