//Example_2_Blinking_with_Switch

const int ledPin = 13;           
const int buttonPin = 2;         
int val;               

void setup ( )

 {
  pinMode(ledPin, OUTPUT);  
  pinMode(buttonPin, INPUT);    

 }

void loop()

{
  val = digitalRead(buttonPin);  

  if (val == HIGH)
     
     {
  digitalWrite(ledPin, HIGH);     
  delay(1000);            
  digitalWrite(ledPin, LOW);   
  delay(1000);     
      }                     

  else {digitalWrite(ledPin, LOW); } }

