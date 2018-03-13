/*
Author : Ahmad Hassan Yassin
This code uses this android App : http://www.ardumotive.com/bluetooth-rc-car.html
Add the motor pin in the #define lines
To modify the directions in the function modify the "i" intger ivariable 
*/
#define en_motorA
#define en_motorB
#define A1_pin
#define A2_pin
#define B1_pin
#define B2_pin

void forward(int mag);
void backward(int mag);
void turn_left(int mag);
void turn_right(int mag);
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
	//Take the iput word from the app
	int input_word;
	if(Serial.available())
		input_word = Serial.read();

	//setting the magnitude of any action
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

	//moving the car according to the needed direction
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

void forward(int mag){
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void backward(int mag){
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,i);
	digitalWrite(B1_pin,1-i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void turn_left(int mag){	
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,1);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void turn_right(int mag){
	int i = 0;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
	analogWrite(en_motorA,mag);
	analogWrite(en_motorB,mag);
}

void stop(){
	digitalWrite(A2_pin,0);-
	digitalWrite(A1_pin,0);
	digitalWrite(B2_pin,0);
	digitalWrite(B1_pin,0);
	digitalWrite(en_motorA,0);
	digitalWrite(en_motorB,0);
}
