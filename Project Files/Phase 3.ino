#define en_motorA 10
#define en_motorB 11
#define A1_pin 9
#define A2_pin 8
#define B1_pin 7 
#define B2_pin 6
#define ruptPin 2
int magnitude;
int count=0;
int val;
String inString="";
bool rising = false; // bool for rising edge of encoder signal
void forward(int mag);
void backward(int mag);
void turn_left(int mag);
void turn_right(int mag);
void circle(int mag);
void Icircle(int mag);
void stop_car();
void turn_right1(int mag);


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
  while(Serial.available())
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
    int count=0;
    do
    {
      int inNumF= inNum-10;
      forward(80);
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
       if(count==inNumF)
       {
         while( inString != "S" )
         {
           stop_car();
           inString=Serial.readString();
         }
       }
       rising=false;
      }
    }while(inString!="S");
  }
  else if(inString=="B")
  {
    Serial.println("inside B");
    int count=0;
    do
    {
      int inNumB= inNum-10;
      backward(80);
      
      val = digitalRead(ruptPin);
      Serial.println(val);  
      if (val==0)
      {
        rising=true;
      }
      if((rising) && ( val== 1) )
      {
       count++;
       Serial.println(count);
       if(count == inNumB) 
       {
         while(inString != "S" )
         {
           stop_car();
           inString=Serial.readString();
         }
       }
       rising=false;
      }
    }while(inString!="S");
  }
  else if(inString=="A")
  {
    Serial.println("inside A");
    int count=0;
    int inNumA=(floor) ( inNum * 1.619 ); 
    int inNum1= (floor)((( inNumA ) * (3.14 /180) )* (7.75) );
    Serial.println(inNumA);
    do
    {
      turn_right1(85);
      val = digitalRead(ruptPin);
      Serial.println(val);  
      if (val==0)
      {
        rising=true;
      }
      if((rising) && ( val== 1) )
      {
       count++;
       Serial.println(count);
       if(count == inNum1) 
       {
         while(inString != "S" )
         {
           stop_car();
           inString=Serial.readString();
         }
       }
       rising=false;
      }
    }while(inString!="S");
  }
  else if(inString=="R")
  { 
    Serial.println("inside R");
    Serial.println(inNum);
    circle();
    delay(9300);
    do
    {
      stop_car();
      Icircle();
      delay(9800);
      while(inString!="S")
      {
        stop_car();
        delay(5000);//25sec
        circle();
        delay(9300);
        stop_car();
        delay(5000);//25sec
        for(int i=0; i<4;i++)
        {
          int count =0;
          forward(80);//1
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
            if(count==90)//1m
            {
              stop_car();
              count=0;
              rising= false;
              delay(1000);
              while(1)
              {
                turn_right1(85);//11
                val= digitalRead(ruptPin);
                if (val==0)
                {
                  rising=true;
                }
                if((rising) &&(val==1))
                {
                  count++;
                  if(count==18)
                  {
                    stop_car();
                    delay(1000);
                    if (i==3)
                    {
                      while(inString!="S")
                      {
                        stop_car();
                        inString=Serial.readString();
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
    }while(inString!="S");
  }

  else if(inString=="S" )
  {
    stop_car();
    count=0;
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
	analogWrite(en_motorB,mag*0.95);
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
void circle()
{
  int i = 1;
  digitalWrite(A2_pin,i);
  digitalWrite(A1_pin,1-i);
  digitalWrite(B2_pin,i);
  digitalWrite(B1_pin,1-i); 
  analogWrite(en_motorA,100);
  analogWrite(en_motorB,83);
}
void Icircle()
{
  int i = 1;
  digitalWrite(A2_pin,i);
  digitalWrite(A1_pin,1-i);
  digitalWrite(B2_pin,1);
  digitalWrite(B1_pin,i-i);
  analogWrite(en_motorA,75);
  analogWrite(en_motorB,100);
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

void turn_right1(int mag)
{
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
	analogWrite(en_motorA,0);
	analogWrite(en_motorB,mag*0.98);
}
