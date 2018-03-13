#define en_motorA
#define en_motorB
#define A1_pin
#define A2_pin
#define B1_pin
#define B2_pin

int input_word;

void forward(int magnitude);
void backward(int magnitude);
void turn_left(int magnitude);
void turn_right(int magnitude);
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
	if(Serial.available())
		input_word = Serial.read();

	int magnitude = 0;
	switch(input_word){
		case 0:
			magnitude = 0;
			break;
		case 1:
			magnitude = 64;
			break;
		case 2:
			magnitude = 128;
			break;
		case 3:
			magnitude = 192;
			break;
		case 4:
			magnitude = 255;
			break;

	}

	switch(input_word){
		case 'F':
			forward(magnitude);
			break;
		case 'B':
			backward(magnitude);
			break;
		case 'L':
			turn_left(magnitude);
			break;
		case 'R':
			turn_right(magnitude);
			break;
		case 'S':
			stop();
			break;

	}
}

void forward(int magnitude){
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,magnitude);
	analogWrite(en_motorB,magnitude);
}

void backward(int magnitude){
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,magnitude);
	analogWrite(en_motorB,magnitude);
}

void turn_left(int magnitude){	
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,1);
	analogWrite(en_motorA,magnitude);
	analogWrite(en_motorB,magnitude);
}

void turn_right(int magnitude){
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
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
