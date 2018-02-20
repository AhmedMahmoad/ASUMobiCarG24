
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int val=0;
int i=0;

void setup() {                

  pinMode(led1, OUTPUT);     
   pinMode(led2, OUTPUT); 
   pinMode(led3, OUTPUT);   
    pinMode(led4, OUTPUT);  
}


void loop() {
  if(val==0){
    if(i==0){
  digitalWrite(led1, HIGH);   
  delay(1000);               
  digitalWrite(led1, LOW);    
  delay(1000); 
  i=1;
  }else if(i==1){
  digitalWrite(led2, HIGH);   
  delay(1000);               
  digitalWrite(led2, LOW);    
  delay(1000); 
  i=2;
  }else if(i==2){
    digitalWrite(led3, HIGH);   
  delay(1000);               
  digitalWrite(led3, LOW);    
  delay(1000); 
  i=3;
  
  }else if(i==3){
   digitalWrite(led4, HIGH);   
  delay(1000);               
  digitalWrite(led4, LOW);    
  delay(1000); 
 
  
i=4;
  val=1;
  }
  
}else if(val==1){
if(i==4){
  digitalWrite(led4, HIGH);   
  delay(1000);               
  digitalWrite(led4, LOW);    
  delay(1000); 
  i=5;
  }else if(i==5){
  digitalWrite(led3, HIGH);   
  delay(1000);               
  digitalWrite(led3, LOW);    
  delay(1000); 
  i=6;
  }else if(i==6){
    digitalWrite(led2, HIGH);   
  delay(1000);               
  digitalWrite(led2, LOW);    
  delay(1000); 
  i=7;
  
  }else if(i==7){
   digitalWrite(led1, HIGH);   
  delay(1000);               
  digitalWrite(led1, LOW);    
  delay(1000); 
 
  
i=0;
  val=0;
  }

}

}
