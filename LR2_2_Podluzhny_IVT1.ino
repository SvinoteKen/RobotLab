//LR2_2_Podluzhny_IVT1

const int MOTOR1 =03;
const int MOTOR2 =05;
const int MOTOR3 =06;
const int MOTOR4 =09;
const int DIR_BUTTON1 = 02;
const int DIR_BUTTON2 = 04;
const int DIR_BUTTON3 = 07;
const int DIR_BUTTON4 = 08;
const int DIRECTION1 = 10;
const int DIRECTION2 = 11;
const int DIRECTION3 = 12;
const int DIRECTION4 = 13;
const int SLIDER1 = A0;
const int SLIDER2 = A1;
const int SLIDER3 = A2;
const int SLIDER4 = A3;

void setup()
{
	pinMode(DIRECTION1,OUTPUT);
	pinMode(DIR_BUTTON1,INPUT);
	pinMode(MOTOR1,OUTPUT);
	pinMode(SLIDER1,INPUT);
	pinMode(DIRECTION2,OUTPUT);
	pinMode(DIR_BUTTON2,INPUT);
	pinMode(MOTOR2,OUTPUT);
	pinMode(SLIDER2,INPUT);	
	pinMode(DIRECTION3,OUTPUT);
	pinMode(DIR_BUTTON3,INPUT);
	pinMode(MOTOR3,OUTPUT);
	pinMode(SLIDER3,INPUT);	
	pinMode(DIRECTION4,OUTPUT);
	pinMode(DIR_BUTTON4,INPUT);
	pinMode(MOTOR4,OUTPUT);
	pinMode(SLIDER4,INPUT);
}
void CONTROL(int motor,int slider,int direction,int dirButton)
{
	int speed = analogRead(slider);
	analogWrite(motor,speed/4);
	digitalWrite(direction,digitalRead(dirButton));
}
void loop()
{
	CONTROL(MOTOR1,SLIDER1,DIRECTION1,DIR_BUTTON1);
	CONTROL(MOTOR2,SLIDER2,DIRECTION2,DIR_BUTTON2);
	CONTROL(MOTOR3,SLIDER3,DIRECTION3,DIR_BUTTON3);
	CONTROL(MOTOR4,SLIDER4,DIRECTION4,DIR_BUTTON4);	
}
