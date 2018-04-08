const int pinL=2;
const int pinC=3;
const int pinR=4;
int LState=0;
int CState=0;
int RState=0;
void setup(){
  Serial.begin(9600);
  pinMode(pinL,INPUT);
  pinMode(pinC,INPUT);
  pinMode(pinR,INPUT);
}
void loop(){
   LState=digitalRead(pinL); 
   CState=digitalRead(pinC); 
   RState=digitalRead(pinR); 
   if(LState==LOW){Serial.print("black1");Serial.print("go");}
   if(LState==HIGH){Serial.print("white1");Serial.print("stop");}
   if (CState == LOW) {Serial.print(" black2"); Serial.print("go");}
   if (CState == HIGH) {Serial.print(" white2");Serial.print("stop"); }
  if (RState == LOW) {Serial.print(" black3"); Serial.print("go"); }
if (RState == HIGH) {Serial.println(" white3"); Serial.print("stop");}
Serial.println("****************************");
delay(1000);
}
