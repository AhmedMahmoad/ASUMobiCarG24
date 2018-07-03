
//connections for the DC motor driver
#define en_motorA 10
#define en_motorB 11
#define A1_pin 9
#define A2_pin 8
#define B1_pin 7 
#define B2_pin 6
 //connections for the ultrasonic rangefinder
  #define trigPin 5
  #define echoPin 4
  #define PinL 3
  #define PinC 2
  #define PinR 12
  
  #define safety_distance 15
  String inputString="";
  int magnitude;
  int state=3;
  unsigned int distance = 200;
  const int brakes_time = 50;
  void forward(int mag);
  void backward(int mag);
  void turn_left(int mag);
  void turn_right(int mag);
  void stop_car();
  double get_distance();

  void setup()
  {
    Serial.begin(9600);
    pinMode(en_motorB, OUTPUT);
    pinMode(en_motorA, OUTPUT);
    pinMode(A1_pin, OUTPUT);
    pinMode(A2_pin, OUTPUT);
    pinMode(B1_pin, OUTPUT);
    pinMode(B2_pin, OUTPUT);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(PinL, INPUT);
    pinMode(PinC, INPUT);
    pinMode(PinR, INPUT);

  }

  void loop()
  {
    //Take the iput word from the app
    
    
    while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }

    //Setting the magnitude of any action  
    if (inputString == "0")
    magnitude = 0;
    else if (inputString == "1")
    magnitude = 64;
    else if (inputString == "2")
    magnitude = 128;
    else if (inputString == "3")
    magnitude = 192;
    else if (inputString == "4")
    magnitude = 255;

    //taking action depending on the sent charachter
    if (inputString == "F")
    forward(magnitude);
    else if (inputString == "B")
    backward(magnitude);
    else if (inputString == "L")
    turn_left(magnitude);
    else if (inputString == "R")
    turn_right(magnitude);
    else if (inputString == "S")
    stop_car();
    else if(inputString == "T")
    {
      char inChar1='p';
      while ((inChar1!='S'))
      {
        inChar1 = (char)Serial.read();
        int LState = digitalRead(PinL);
        int CState = digitalRead(PinC);
        int RState = digitalRead(PinR);
       
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
      }
    }
    
      
   
    inputString = ""; //resetting the input string
    distance = get_distance();
    Serial.print("1 ");Serial.println(distance);
    if ((distance <= safety_distance) && (distance != -1))
    {
      backward(255);
      Serial.println(distance);
      delay(brakes_time);
      stop_car();
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

void stop_car()
{
	digitalWrite(A2_pin,0);
	digitalWrite(A1_pin,0);
	digitalWrite(B2_pin,0);
	digitalWrite(B1_pin,0);
	digitalWrite(en_motorA,0);
	digitalWrite(en_motorB,0);
}

double get_distance()
{
  unsigned long duration;
  float range;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  range = (float)duration*0.034/2;
  if(range >= 200 || range <= 0)
    return -1;
  else
    return range;
}





