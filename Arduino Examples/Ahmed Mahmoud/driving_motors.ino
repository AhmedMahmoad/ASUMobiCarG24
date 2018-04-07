const int f1 = 10;
const int f2 = 11;
const int b1 = 12;
const int b2 = 13;


void  setup()
{
  pinMode(f1,OUTPUT);
  pinMode(f2,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  
  Serial.begin(9600);    
}

void loop()
{
  int value;
  value=Serial.available();
  if (value>0)
  {
    int input;
    input= Serial.parseInt();
    
    if  (input==1)
    {
     digitalWrite  (f1,LOW);
     digitalWrite  (f2,LOW);
     digitalWrite  (b1,HIGH);
     digitalWrite  (b2,HIGH);
     
    }
    else if (input==2)
    {
     digitalWrite  (f1,HIGH);
     digitalWrite  (f2,HIGH);
     digitalWrite  (b1,LOW);
     digitalWrite  (b2,LOW);
  
    }
    else if (input==3)
    {
     digitalWrite  (f1,HIGH);
     digitalWrite  (f2,LOW);
     digitalWrite  (b1,LOW);
     digitalWrite  (b2,HIGH);
     
    }   
    else if  (input==4)
    {
     digitalWrite  (f1,LOW);
     digitalWrite  (f2,HIGH);
     digitalWrite  (b1,HIGH);
     digitalWrite  (b2,LOW);
     
    }
    else
    {
     digitalWrite  (f1,HIGH);
     digitalWrite  (f2,HIGH);
     digitalWrite  (b1,HIGH);
     digitalWrite  (b2,HIGH);
     
    }}
}
