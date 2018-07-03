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
  for(int i=0; i<4;i++)
  {
    forward(120);//1
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
      if(count==400)
      {
        stop_car();
        count=0;
        rising= false;
        delay(6000);
        while(1)
        {
          turn_right(100);//11
          val= digitalRead(ruptPin);
          if (val==0)
          {
           rising=true;
          }
          if((rising) &&(val==1))
          {
            count++;
            if(count==12)
            {
              stop_car();
              delay(6000);
              if (i==3)
              {
                while(1)
                {
                  stop_car();
                }
              }
              break;
            }
            rising=false;
          }
        }
      }
      rising=false;
    }
  }
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
void circle( int mag)
{
  int i = 1;
  digitalWrite(A2_pin,i);
  digitalWrite(A1_pin,1-i);
  digitalWrite(B2_pin,1-i);
  digitalWrite(B1_pin,i);
  analogWrite(en_motorA,(mag * 27.8));
  analogWrite(en_motorB,(mag * 12.2));
}
void invers_circle( int mag)
{
  int i = 1;
  digitalWrite(A2_pin,i);
  digitalWrite(A1_pin,1-i);
  digitalWrite(B2_pin,1-i);
  digitalWrite(B1_pin,i);
  analogWrite(en_motorA,(mag * 12.2));
  analogWrite(en_motorB,(mag * 27.8));
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
