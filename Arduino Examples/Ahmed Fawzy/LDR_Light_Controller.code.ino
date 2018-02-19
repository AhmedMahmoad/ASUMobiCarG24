#include <LiquidCrystal.h>
int led7 = 7;
int led6 = 6;
int led5 = 5;
int led4 = 4;
int led3 = 3;
int led2 = 2;
int led1 = 1;
int led0 = 0;
LiquidCrystal lcd (13,12,11,10,9,8);

void setup() {

lcd.begin (16,2);
pinMode(led0,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT); 
}

void loop() {
int LDR =analogRead(A0);
int temp = map (LDR,0,1023,0,255);
lcd.setCursor(0,0);
lcd.print("ADC VALUE = ");
lcd.setCursor(0,1);
lcd.print (temp);
delay(10);
lcd.clear();

if (LDR==0){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW);
}

////////LED ON CONDITION////////

if (LDR>0){
  digitalWrite (led7,HIGH);
}
if(LDR>32){
  digitalWrite (led6,HIGH);
}
if (LDR>64){
  digitalWrite (led5,HIGH);
}
if (LDR>96){
  digitalWrite (led4,HIGH);
}
if (LDR>128){
  digitalWrite (led3,HIGH);
}
if (LDR>160){
  digitalWrite (led2,HIGH);
}
if (LDR>192){
  digitalWrite (led1,HIGH);
}
if (LDR>224){
  digitalWrite (led0,HIGH);
}

///////////LED OFF CONDITION/////////

if (LDR<0){
  digitalWrite (led7,LOW);
}
if(LDR<32){
  digitalWrite (led6,LOW);
}
if (LDR<64){
  digitalWrite (led5,LOW);
}
if (LDR<96){
  digitalWrite (led4,LOW);
}
if (LDR<128){
  digitalWrite (led3,LOW);
}
if (LDR<160){
  digitalWrite (led2,LOW);
}
if (LDR<192){
  digitalWrite (led1,LOW);
}
if (LDR<224){
  digitalWrite (led0,LOW);
}
}

