// cpd 
#include <MsTimer2.h>
void setup() {
  for (byte i = 0 ; i < 8 ; i++) {
    pinMode(i , OUTPUT);
  }
  MsTimer2::set(1000, increase);
  MsTimer2::start();
}
byte no = 0;
byte imd = 0;

void increase() {
  for (byte i = 0 ; i < 8 ; i++) {
    digitalWrite(i , LOW);
  }
  for (byte i = 0 ; i < 8 ; i++) {
    if ( imd % 2 == 1) {
      digitalWrite(i , HIGH);
    }
    imd = imd / 2 ;
  }
  if ( no == 255) {
    no = 0 ;
  } else {
    no += 1 ;
  }
  imd = no;
}
void loop() {

}
