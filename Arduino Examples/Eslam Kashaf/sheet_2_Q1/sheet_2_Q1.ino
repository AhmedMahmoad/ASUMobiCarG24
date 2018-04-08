void setup() {
  for (byte i = 0 ; i < 8 ; i++) {
    pinMode(i , INPUT_PULLUP);
  }
  pinMode(8 , OUTPUT);
  digitalWrite(8, LOW);
  int no = 0;
  for (byte i = 0 ; i < 8 ; i++) {
    if (digitalRead(i) == LOW ) {
      no += pow(2, i);
    }
  }
  no *= 4;
  digitalWrite(8, HIGH);
  delay(no);
  digitalWrite(8, LOW);
}

void loop() {
  
}
