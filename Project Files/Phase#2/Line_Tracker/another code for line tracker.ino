//LIR-LEST IR SENSOR

//CIR-CENTRAL IR SENSOR

//RIR-RIGHT IR SENSOR

//ML-LEFT MOTOR
//ML2-LEFT MOTOR

//MR-RIGHT MOTOR
//MR2-RIGHT MOTOR


const int LIR=3;

const int CIR=4;

const int RIR=5;

const int ML=6;
const int ML2=7;

const int MR=8;
const int MR2=9;

int val1=0,val2=0,val3=0;

void setup()

{

pinMode(LIR,INPUT);

pinMode(CIR,INPUT);

pinMode(RIR,INPUT);

pinMode(ML,OUTPUT);
pinMode(ML2,OUTPUT);
pinMode(MR,OUTPUT);
pinMode(MR2,OUTPUT);
}

void loop()

{

val1=digitalRead(LIR);

val2=digitalRead(CIR);

val3=digitalRead(RIR);

if(val1==HIGH && val2==LOW && val3==HIGH)

{

digitalWrite(ML,HIGH);
digitalWrite(ML2,LOW);
digitalWrite(MR,HIGH);
digitalWrite(MR2,LOW);

}

if(val1==LOW && val2==HIGH && val3==HIGH)

{

digitalWrite(ML,LOW);
digitalWrite(ML2,LOW);
digitalWrite(MR,HIGH);
digitalWrite(MR2,LOW);

}

if(val1==HIGH && val2==HIGH && val3==LOW)

{

digitalWrite(ML,HIGH);
digitalWrite(ML2,LOW);
digitalWrite(MR,LOW);
digitalWrite(MR2,LOW);

}if(val1==LOW&& val2==LOW && val3==LOW)
digitalWrite(ML,LOW);
digitalWrite(ML2,LOW);
digitalWrite(MR,LOW);
digitalWrite(MR2,LOW);}

}
