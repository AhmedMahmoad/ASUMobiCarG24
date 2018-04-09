
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
}
