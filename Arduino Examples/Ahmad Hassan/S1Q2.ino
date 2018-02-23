void setup(){
  //using a for loop to initialize the variables
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop(){
  for(int i=4; i<8; i++){
    digitalWrite(i, 1);
    delay(1000);
    digitalWrite(i, 0);
  }

  for(int i=6; i>4; i--){
    digitalWrite(i, 1);
    delay(1000);
    digitalWrite(i, 0);
  }

}
