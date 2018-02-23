/*
  This Code produces continuous pulses with duration of 2 seconds and duty cycle of
  25% an led can be used to illustrate the output
  
  Created by Ahmad Hassan Yassin AbdulAziz
*/

const int led_pin = 7;

void setup(){
  pinMode(led_pin, OUTPUT);
}

void loop(){
  digitalWrite(led_pin, 1);
  delay(500);
  digitalWrite(led_pin, 0);
  delay(1500);
}
