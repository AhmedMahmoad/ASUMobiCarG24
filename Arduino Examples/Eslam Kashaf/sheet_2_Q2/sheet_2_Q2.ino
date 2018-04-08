int t = 1 ;
byte dig = 1 ;
byte button1 = 2 ;
byte button2 = 3 ;
void setup() {
  pinMode(button1,INPUT_PULLUP) ;
  pinMode(button2,INPUT_PULLUP) ;
  pinMode(dig,OUTPUT) ;
}

void loop() {
   digitalWrite(dig,HIGH) ;
   delay(t*1000) ;
   digitalWrite(dig,LOW) ;
   delay(t*1000) ;
  if((digitalRead(button1))==LOW){   
      t = t / 2 ;
     if(t<1){
      t = 1 ;  
     }
  }
  if((digitalRead(button2))==LOW){  
      t = t * 2 ;
     if(t>10){
      t = 10 ;
     }
  }

}
