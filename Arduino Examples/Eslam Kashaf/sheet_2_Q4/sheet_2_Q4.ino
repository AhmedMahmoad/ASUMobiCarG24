void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(0, OUTPUT);
  digitalWrite(0, LOW);
}
int Val = 0;
byte analogPin = -1;
void loop() {
  if (digitalRead(2) == LOW) {
    if (analogPin == 5) {
      analogPin = 0 ;
    } else {
      analogPin += 1;
    }
    Val = analogRead(analogPin);
    digitalWrite(0, HIGH);
    delay(Val);
    digitalWrite(0, LOW);
    delay(500);
  }
}
