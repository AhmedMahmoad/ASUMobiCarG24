#define echoPin 7 
#define trigPin 8 
#define LEDPin 9 
const  int f1  = 10;
const int f2 = 11;
const int  b1  =12;
const int b2 = 13 ;

int maximumRange = 7; 
int minimumRange =0; 
long duration, distance; 
void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT);
   pinMode(f1,OUTPUT);
    pinMode(f2,OUTPUT);
      pinMode(b1,OUTPUT);
     pinMode(b2,OUTPUT);
}

void loop() {
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(10); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2;
 
 if (distance< maximumRange){
 digitalWrite(LEDPin, HIGH); 
  digitalWrite  (f1,LOW);
     digitalWrite  (f2,LOW);
     digitalWrite  (b1,HIGH);
     digitalWrite  (b2,HIGH);
      }
 else {
 digitalWrite(LEDPin, LOW); 
  digitalWrite  (f1,HIGH);
     digitalWrite  (f2,HIGH);
     digitalWrite  (b1,HIGH);
    digitalWrite  (b2,HIGH);
     
 }
 

 delay(50);
}
