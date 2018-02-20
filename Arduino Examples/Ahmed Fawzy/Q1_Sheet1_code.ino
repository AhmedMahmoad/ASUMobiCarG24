///////// Q1 SHEET 1 ////////

const int LED = 13;  

void setup() 
{
pinMode(LED,OUTPUT);
}

void loop() {

digitalWrite(LED,HIGH);
delay(440);
digitalWrite(LED,LOW);
delay(1560);
}
