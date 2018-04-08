
/* author by Islam Shaaban 
*/
//code is
#define en_motorA 10
#define en_motorB 11
#define A1_pin 9
#define A2_pin 8
#define B1_pin 7 
#define B2_pin 6
#define sensorleft 14
#define sensorcenter 15
#define sensorright 16



int LeftS=1;
int CenterS=1;
int RightS=1;

int f1=0;
int f2=0;
int f3=0;


void forward(int mag);
void backward(int mag);
void turn_left(int mag);
void turn_right(int mag);
void stop_car();
//////////////////////////////////////

void setup()
{

 pinMode(en_motorB, OUTPUT);
	pinMode(en_motorA, OUTPUT);
	pinMode(A1_pin, OUTPUT);
	pinMode(A2_pin, OUTPUT);
	pinMode(B1_pin, OUTPUT);
	pinMode(B2_pin, OUTPUT);

 pinMode(sensorleft,INPUT);
 pinMode(sensorcenter,INPUT);
 pinMode(sensorright,INPUT);

}
///////////////////////////////////////////////////

void loop()
{
LeftS=digitalRead(sensorleft);
CenterS=digitalRead(sensorcenter);
RightS=digitalRead(sensorright);

/////////////////////////////////////////////////////////////////////
if(LeftS==1&&CenterS==1&&RightS==1)   //feedback when comes all sensor on white
{
LeftS=f1;
CenterS=f2;
RightS=f3;
}

////////////////////////////////////////////////////////////////////////////
if(LeftS==0&&CenterS==1&&RightS==1||LeftS==0&&CenterS==0&&RightS==1)   //left turn
{
turn_left(255);
}
else
if(LeftS==1&&CenterS==1&&RightS==0||LeftS==1&&CenterS==0&&RightS==0)  //right turn
{
  turn_right(255);
}
else
if(LeftS==1&&CenterS==0&&RightS==1)  //go forward straight
{
  forward(255);
}
else
if(LeftS==0&&CenterS==0&&RightS==0) //stop
{
 stop_car();
}

///////////////////////////////////////////////////////////////////
f1=LeftS;
f2=CenterS;
f3=RightS;        //memory variables
////////////////////////////////////////////////////////////////////
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
void turn_left(int mag){	
	int i = 1;
	digitalWrite(A2_pin,i);
	digitalWrite(A1_pin,1-i);
	digitalWrite(B2_pin,1-i);
	digitalWrite(B1_pin,i);
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
void stop_car(){
	digitalWrite(A2_pin,0);
	digitalWrite(A1_pin,0);
	digitalWrite(B2_pin,0);
	digitalWrite(B1_pin,0);
	digitalWrite(en_motorA,0);
	digitalWrite(en_motorB,0);
}
