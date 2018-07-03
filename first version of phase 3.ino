#define en_motorA 10
#define en_motorB 11
#define A1_pin 9
#define A2_pin 8
#define B1_pin 7 
#define B2_pin 6
#define ruptPin 2
int magnitude;
int val;
int count=0;
String inString="";
bool rising = false; // bool for rising edge of encoder signal
void forward(int mag);
void backward(int mag);
void turn_left(int mag);
void turn_right(int mag);
void stop_car();

void setup()
{
    Serial.begin(9600);
    pinMode(en_motorB, OUTPUT);
    pinMode(en_motorA, OUTPUT);
    pinMode(A1_pin, OUTPUT);
    pinMode(A2_pin, OUTPUT);
    pinMode(B1_pin, OUTPUT);
    pinMode(B2_pin, OUTPUT);
    pinMode(ruptPin,INPUT);
}
void loop()
{
  char inChar;
  int inNum;
  if(Serial.available())
  {
    inChar = (char)Serial.read();
    inNum=Serial.parseInt();
    inString+=inChar;
  }
  Serial.println(inChar);
  Serial.println(inString);
  Serial.println(inNum);
  if(inString=="F")
  {
    Serial.println("inside F");
    while(1)
    {
      forward(100);
      val = digitalRead(ruptPin);
      Serial.println(val);  
      if (val==0)
      {
        rising=true;
      }
      if((rising) && ( val==1) )
      {
       count++;
       Serial.println(count);
       if(count==inNum/0.3 )
       {
         while(1)
         {
           stop_car();
         }
       }
       rising=false;
      }
    }
  }
  else if(inString=="B")
  {
    Serial.println("inside B");
    while(1)
    {
      backward(100);
      val = digitalRead(ruptPin);
      Serial.println(val);  
      if (val==0)
      {
        rising=true;
      }
      if((rising) && ( val==1) )
      {
       count++;
       Serial.println(count);
       if(count==inNum/0.3 )
       {
         while(1)
         {
           stop_car();
         }
       }
       rising=false;
      }
    }
  }
  inString="";
}

void forward(int mag)
{
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void backward(int mag)
{
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void turn_left(int mag)
{	
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void turn_right(int mag)
{
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void stop_car()
{
	digitalWrite(A2_pin,0);
	digitalWrite(A1_pin,0);
	digitalWrite(B2_pin,0);
	digitalWrite(B1_pin,0);
	digitalWrite(en_motorA,0);
	digitalWrite(en_motorB,0);
}
