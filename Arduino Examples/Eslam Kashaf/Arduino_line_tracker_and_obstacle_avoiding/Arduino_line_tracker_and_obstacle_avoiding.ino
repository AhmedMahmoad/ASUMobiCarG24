
const int sag_i = 2;
const int sag_g = 3;
const int sol_i = 5;
const int sol_g = 4;
const int sol_sensor = 6;
const int sag_sensor = 7;
const int trigger_pin = 8;
const int echo_pin = 9;

float sure;
float mesafe;

int sol_durum, sag_durum;
int rast;

void setup()
 {
  pinMode(sag_i, OUTPUT);
  pinMode(sag_g, OUTPUT);
  pinMode(sol_i, OUTPUT);
  pinMode(sol_g, OUTPUT);
  pinMode(sag_sensor, INPUT);
  pinMode(sol_sensor, INPUT);
  pinMode(trigger_pin , OUTPUT);
  pinMode(echo_pin , INPUT);
//  Serial.begin(9600);
 }

void loop() 
{
  sol_durum = digitalRead(sol_sensor);
  sag_durum = digitalRead(sag_sensor);

  digitalWrite(trigger_pin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin , LOW);
  sure = pulseIn(echo_pin , HIGH);
  mesafe = (sure/2) / 28.5;
//  Serial.print("sag sensor = ");
//  Serial.println(sag_durum);
//  Serial.print("sol sensor = ");
//  Serial.println(sol_durum);
//  Serial.print(" cisme olan uzaklik = ");
//  Serial.print(mesafe);
//  Serial.println(" cm ");
//  Serial.println("____________________________");
//  delay(1000);

  rast = random(2);
//  Serial.println(rast);

  if (mesafe < 10) // geri , donus
  {
    digitalWrite(sag_g, HIGH);
    digitalWrite(sag_i, LOW);
    digitalWrite(sol_g, HIGH);
    digitalWrite(sol_i, LOW);
//    Serial.println("geri");
    delay(190);
    if (rast == 0) // sag
    {
      digitalWrite(sag_i, LOW);
      digitalWrite(sag_g, HIGH);
      digitalWrite(sol_i, HIGH);
      digitalWrite(sol_g, LOW);
//      Serial.print("sag");
      delay(300);
      digitalWrite(trigger_pin , HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigger_pin , LOW);
      sure = pulseIn(echo_pin , HIGH);
      mesafe = (sure/2) / 28.5;
      if (mesafe < 10) // sol
      {
        digitalWrite(sag_i, HIGH);
        digitalWrite(sag_g, LOW);
        digitalWrite(sol_i, LOW);
        digitalWrite(sol_g, HIGH);
//        Serial.print("sol");
        delay(300);
        digitalWrite(trigger_pin , HIGH);
        delayMicroseconds(1000);
        digitalWrite(trigger_pin , LOW);
        sure = pulseIn(echo_pin , HIGH);
        mesafe = (sure/2) / 28.5;
        if (mesafe < 10)// geri
        {
          digitalWrite(sag_g, HIGH);
          digitalWrite(sag_i, LOW);
          digitalWrite(sol_g, HIGH);
          digitalWrite(sol_i, LOW);
//          Serial.println("geri");
          delay(190);
        }
      }
       
    }
    else if (rast == 1) // sol
    {
      digitalWrite(sag_i, HIGH);
      digitalWrite(sag_g, LOW);
      digitalWrite(sol_i, LOW);
      digitalWrite(sol_g, HIGH);
//      Serial.print("sol");
      delay(300);
      digitalWrite(trigger_pin , HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigger_pin , LOW);
      sure = pulseIn(echo_pin , HIGH);
      mesafe = (sure/2) / 28.5;
      if (mesafe < 10) // sag
      {
        digitalWrite(sag_i, LOW);
        digitalWrite(sag_g, HIGH);
        digitalWrite(sol_i, HIGH);
        digitalWrite(sol_g, LOW);
//        Serial.print("sag");
        delay(300);
        digitalWrite(trigger_pin , HIGH);
        delayMicroseconds(1000);
        digitalWrite(trigger_pin , LOW);
        sure = pulseIn(echo_pin , HIGH);
        mesafe = (sure/2) / 28.5;
        if (mesafe < 10);
        {
          digitalWrite(sag_g, HIGH);
          digitalWrite(sag_i, LOW);
          digitalWrite(sol_g, HIGH);
          digitalWrite(sol_i, LOW);
//          Serial.println("geri");
          delay(190); 
        }
      }
    }
  }
      
  else if (sol_durum == LOW && sag_durum == LOW) // ileri
  {
    digitalWrite(sag_i, HIGH);
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, HIGH);
    digitalWrite(sol_g, LOW);
  }
  else if (sol_durum == LOW && sag_durum == HIGH) // saga
  {
    digitalWrite(sag_i, LOW);
    digitalWrite(sag_g, HIGH);
    digitalWrite(sol_i, HIGH);
    digitalWrite(sol_g, LOW);
  }
  else if (sol_durum == HIGH && sag_durum == LOW) // sola
  {
    digitalWrite(sag_i, HIGH);
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, LOW);
    digitalWrite(sol_g, HIGH);
  }
  else
  {
    digitalWrite(sag_i, LOW);
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, LOW);
    digitalWrite(sol_g, LOW);
  }
  delay(65);
  digitalWrite(sag_i, LOW);
  digitalWrite(sag_g, LOW);
  digitalWrite(sol_i, LOW);
  digitalWrite(sol_g, LOW);
  delay(25); 
}
