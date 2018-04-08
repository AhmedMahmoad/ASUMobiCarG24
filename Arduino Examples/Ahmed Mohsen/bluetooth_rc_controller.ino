//Bluetooth RC Controller 
#include "SoftwareSerial.h"// استدعاء المكتبه
const int IN1=3;
const int IN2=5;
const int IN3=6;
const int IN4=9;
int BluetoothData;
SoftwareSerial HC05(11, 12); // TX, RX
int SPEED_Control=200;
void setup() 
{
// تعريف مخارج الاردوينو للموتور
pinMode( IN1 ,OUTPUT);// Right Motor 1st wire
pinMode( IN2 ,OUTPUT);// Right Motor 2nd wire
pinMode( IN3 ,OUTPUT);// left Motor 1st wire
pinMode( IN4 ,OUTPUT);// left Motor 2nd wire
HC05.begin(9600);
}
void FORWARD(int Speed)
{
// للتحرك للامام
analogWrite(IN1,0);
analogWrite(IN2,Speed);
analogWrite(IN3,Speed);
analogWrite(IN4,0);
}
void BACKWARD(int Speed)
{
//للرجوع للخللف
analogWrite(IN1,Speed);
analogWrite(IN2,0);
analogWrite(IN3,0);
analogWrite(IN4,Speed);
}
void LEFT(int Speed)
{
//عشان الموتور يدور جهة اليسار
analogWrite(IN1,0);
analogWrite(IN2,Speed);
analogWrite(IN3,0);
analogWrite(IN4,Speed);
}
void RIGHT(int Speed)
{
//الدوران لليمين
analogWrite(IN1,Speed);
analogWrite(IN2,0);
analogWrite(IN3,Speed);
analogWrite(IN4,0);
}
void Stop()
{
//لوقف الموتور عن الحركة 
analogWrite(IN1,0);
analogWrite(IN2,0);
analogWrite(IN3,0);
analogWrite(IN4,0);
}
void loop()
{
if (HC05.available())
{ // فحص حالة الاستقبال بتاع الاردوينو من البلوتوث
BluetoothData=HC05.read(); 
Serial.println(BluetoothData);
if(BluetoothData=='F')
{ /* لو جالك حرف اف هتتحرك للامام وفوق الخطوات اللي بتوضح اذاي هيتحرك للامام */
FORWARD(SPEED_Control);
}
if(BluetoothData=='B')
{ /* لو جالك حرف بي هتتحرك للخلف وفوق الخطوات اللي بتوضح اذاي هيتحرك للخلف */
BACKWARD(SPEED_Control);
}
if(BluetoothData=='R')
{ /* لو جالك حرف ار هتتحرك لليمين وفوق الخطوات اللي بتوضح اذاي هيتحرك لليمين */
RIGHT(SPEED_Control);
}
if(BluetoothData=='L')
{ /* لو جالك حرف ال هتتحرك لليسار وفوق الخطوات اللي بتوضح اذاي هيتحرك لليسار */
LEFT(SPEED_Control);
}
if(BluetoothData=='S')
{ /* لو جالك حرف اس هتوقف الروبوت وفوق الخطوات اللي بتوضح اذاي هتوقف المحركات */ 
Stop();
}
// للتحكم في سرعة العربية
if(BluetoothData=='0')
{ SPEED_Control=0 ;} 
if(BluetoothData=='1')
{ SPEED_Control=50; } 
if(BluetoothData=='2')
{ SPEED_Control=100; } 
if(BluetoothData=='3')
{ SPEED_Control=120; } 
if(BluetoothData=='4')
{ SPEED_Control=140; }
if(BluetoothData=='5')
{ SPEED_Control=160; } 
if(BluetoothData=='6')
{ SPEED_Control=180; } 
if(BluetoothData=='7')
{ SPEED_Control=200; } 
if(BluetoothData=='8')
{ SPEED_Control=220; } 
if(BluetoothData=='9')
{ SPEED_Control=240; } 
if(BluetoothData=='q')
{ SPEED_Control=255; } 
}
}
