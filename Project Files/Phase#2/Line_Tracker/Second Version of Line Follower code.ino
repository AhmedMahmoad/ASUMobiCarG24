// motor pins declaration
const int en_motorA=10;
const int en_motorB=11;
const int A1_pin=9;
const int A2_pin=8;
const int B1_pin=7;
const int B2_pin=6;
// semsor pins declaration
const int PinL= 3;
const int PinC= 4;
const int PinR= 5;

void forward(int mag);
void turn_left(int mag);
void turn_right(int mag);
void stop_car();
int state=3;
void setup()
{
   Serial.begin(9600);
   pinMode(PinL, INPUT);
   pinMode(PinC, INPUT);
   pinMode(PinR, INPUT);
   pinMode(en_motorB, OUTPUT);
   pinMode(en_motorA, OUTPUT);
   pinMode(A1_pin, OUTPUT);
   pinMode(A2_pin, OUTPUT);
   pinMode(B1_pin, OUTPUT);
   pinMode(B2_pin, OUTPUT);
}
void loop()
{
  int LState = digitalRead(PinL);
  int CState = digitalRead(PinC);
  int RState = digitalRead(PinR);
  if (state==3)
  {
    forward(150);
    delay(5);
  }
   else if (state==1)
  {
    turn_right(85);
    delay(5);
  }
  else if (state==2)
  {
    turn_left(85);
    delay(5);
  }

 
    
 

  
    
  if ( (LState == HIGH && CState == LOW && RState== LOW))
  {
    state=1;
  }
 
  else if ( (LState == HIGH && CState == HIGH && RState== LOW) ) 
  {
    state=1;
  }
  else if  ( (LState == LOW && CState == LOW && RState == HIGH) )
  {
    state=2;

  }
  else if( (LState == LOW && CState == HIGH && RState == HIGH) ) // ( 1 && 1 && 0 || 1 && 0 && 0) right 
  {
    state=2;

  } 
  
  else if ( (LState == LOW && CState == HIGH  && RState == LOW)) 
  {
    state=3;
 
  }
  
  else if( (LState == HIGH && CState == HIGH  && RState == HIGH) )
  {
    state =3;
  }
  
  else if ( (LState == LOW && CState == LOW && RState == LOW) )
  {
   
  }
  
  ///////////
  
 
 
}

void forward(int mag){
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}
void turn_left(int mag){	
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void turn_right(int mag){
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}
void stop_car(){
	digitalWrite(A2_pin,0);
	digitalWrite(A1_pin,0);
	digitalWrite(B2_pin,0);
	digitalWrite(B1_pin,0);
	digitalWrite(en_motorA,0);
	digitalWrite(en_motorB,0);
}
