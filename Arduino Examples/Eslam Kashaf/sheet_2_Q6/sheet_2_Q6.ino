void setup() {
  for ( byte i = 0 ; i < 3 ; i++) {
    pinMode(i , OUTPUT);
    digitalWrite(i, LOW);
  }
}
int val[3];
void loop() {
  val[0] = analogRead(0);
  val[1] = analogRead(1);
  val[2] = analogRead(2);

  if (val[0] > val [1]){
    if (val[0] > val[2]){
      digitalWrite(0 , HIGH);
      digitalWrite(1 , LOW);
      digitalWrite(2 , LOW);
    }else{
      digitalWrite(2 , HIGH);
      digitalWrite(0 , LOW);
      digitalWrite(1 , LOW);
    }
  }else{
    if (val[1] > val[2]){
      digitalWrite(1 , HIGH);
      digitalWrite(0 , LOW);
      digitalWrite(2 , LOW);
    }else{
      digitalWrite(2 , HIGH);
      digitalWrite(0 , LOW);
      digitalWrite(1 , LOW);
    }
  }

}
