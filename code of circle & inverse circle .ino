#define en_motorA 10
#define en_motorB 11
#define A1_pin 9
#define A2_pin 8
#define B1_pin 7 
#define B2_pin 6
#define ruptPin 2
int magnitude;
int val;
String inString="";
float car_width_2=7.75;
bool rising = false; // bool for rising edge of encoder signal
void forward(int mag);
void backward(int mag);
void turn_left(int mag);
void turn_right(int mag);
void circle(int mag);
void invers_circle(int mag);
void square(int mag);
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
  circle();
  delay(9300);
  while(1)
  {
    stop_car();
    Icircle();
    delay(9800);
    while(1)
    {
      stop_car();
    }
  }
  
}


void circle( )
{
  int i = 1;
  digitalWrite(A2_pin,i);
  digitalWrite(A1_pin,1-i);
  digitalWrite(B2_pin,i);
  digitalWrite(B1_pin,1-i);
  analogWrite(en_motorA,83);
  analogWrite(en_motorB,100);
}
void Icircle( )
{
  int i = 1;
  digitalWrite(A2_pin,i);
  digitalWrite(A1_pin,1-i);
  digitalWrite(B2_pin,i);
  digitalWrite(B1_pin,1-i);
  analogWrite(en_motorA,100);
  analogWrite(en_motorB,73);
}
void stop_car( )
{
  digitalWrite(A2_pin,0);
  digitalWrite(A1_pin,0);
  digitalWrite(B2_pin,0);
  digitalWrite(B1_pin,0);
  analogWrite(en_motorA,0);
  analogWrite(en_motorB,0);
}
