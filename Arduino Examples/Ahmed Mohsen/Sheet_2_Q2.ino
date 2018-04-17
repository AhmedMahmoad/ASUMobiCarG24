//Sheet 2
//Q2
void setup() 
{
  pinMode(2 , INPUT_PULLUP);
  pinMode(3 , INPUT_PULLUP);
  pinMode(0 , OUTPUT);
  digitalWrite(0 , LOW);
}
int   x = 0;
void IncreaseDuration() 
{
  if (x < 10000)
  {
    x += 1000;
  }
}
void decreaseDuration() 
{
  if (x > 0){
  x -= 1000;
}

}
void loop()
{
  attachInterrupt(digitalPinToInterrupt(2), IncreaseDuration, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), decreaseDuration, FALLING);
  digitalWrite(0 , HIGH);
  delay((x / 2));
  digitalWrite(0 , LOW);
  delay((x / 2));
}
