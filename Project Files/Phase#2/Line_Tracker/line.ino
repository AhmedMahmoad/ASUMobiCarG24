const int R = 2 ;
const int C = 3 ;
const int L = 4 ;
const  int f1  = 10;
const int f2 = 11;
const int  b1  =12;
const int b2 = 13 ;
void setup(){ 
pinMode(f1,OUTPUT);
pinMode(f2,OUTPUT);
pinMode(b1,OUTPUT);
pinMode(b2,OUTPUT);
pinMode(R,INPUT);
//pinMode(C,INPUT); 
pinMode(L,INPUT);
}
void loop() {
int L=digitalRead (4);
//int C =digitalRead (3);
int  R=digitalRead (2);
if(R==HIGH&&L==HIGH){
     digitalWrite  (f1,LOW);
     digitalWrite  (f2,LOW);
     digitalWrite  (b1,HIGH);
     digitalWrite  (b2,HIGH);
    
      }
     if(R==HIGH&&L==LOW){
     digitalWrite  (f1,LOW);
     digitalWrite  (f2,HIGH);
     digitalWrite  (b1,HIGH);
     digitalWrite  (b2,LOW);
     }
     if(R==LOW&&L==HIGH){
     digitalWrite  (f1,HIGH);
     digitalWrite  (f2,LOW);
     digitalWrite  (b1,LOW);
     digitalWrite  (b2,HIGH);
     }
    
      else{
          digitalWrite  (f1,HIGH);
     digitalWrite  (f2,HIGH);
     digitalWrite  (b1,HIGH);
     digitalWrite  (b2,HIGH);
      }
      }
