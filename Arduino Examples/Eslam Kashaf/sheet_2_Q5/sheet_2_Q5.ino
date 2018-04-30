void setup() {
  for (byte i = 0 ; i < 10 ; i++) {
    pinMode(i , OUTPUT);
    digitalWrite(i , LOW);
  }
}

void loop() {
  for (byte i = 0 ; i < 10 ; i ++ ) {
    digitalWrite(i , HIGH);
    delay(analogRead(0));
    digitalWrite(i , LOW);
  }
}
