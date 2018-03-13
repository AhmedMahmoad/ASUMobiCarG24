#define en_motorA
#define en_motorB
#define A1_pin
#define A2_pin
#define B1_pin
#define B2_pin

void forward(magnitude);
void backward(magnitude);
void turn_left(magnitude);
void turn_right(magnitude);
void stop();

void setup(){
	Serial.begin(38400);
	pinMode(en_motorB, OUTPUT);
	pinMode(en_motorA, OUTPUT);
	pinMode(A1_pin, OUTPUT);
	pinMode(A2_pin, OUTPUT);
	pinMode(B1_pin, OUTPUT);
	pinMode(B2_pin, OUTPUT);
}


void loop(){

}

void forward(magnitude){
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,magnitude);
	analogWrite(en_motorB,magnitude);
}

void backward(magnitude){
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,magnitude);
	analogWrite(en_motorB,magnitude);
}

void turn_left(magnitude){	
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,magnitude);
	analogWrite(en_motorB,magnitude);
}

void turn_right(magnitude){
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,magnitude);
	analogWrite(en_motorB,magnitude);
}

void stop(){
	digitalWrite(A2_pin,0);
	digitalWrite(A1_pin,0);
	digitalWrite(B2_pin,0);
	digitalWrite(B1_pin,0);
	digitalWrite(en_motorA,0);
	digitalWrite(en_motorB,0);
}
