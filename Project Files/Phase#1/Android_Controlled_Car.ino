#define en_motorA
#define en_motorB
#define A1_pin
#define A2_pin
#define B1_pin
#define B2_pin

void forward(magnitude);
void backward(magnitude);
void left(magnitude);
void right(magnitude);
void stop();

void setup(){
	pinMode(en_motorB, OUTPUT);
	pinMode(en_motorA, OUTPUT);
	pinMode(A1_pin, OUTPUT);
	pinMode(A2_pin, OUTPUT);
	pinMode(B1_pin, OUTPUT);
	pinMode(B2_pin, OUTPUT);

}


void loop(){

}

