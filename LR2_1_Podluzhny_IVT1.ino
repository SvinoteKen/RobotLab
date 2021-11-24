//LR2_1_Podluzhny_IVT1

const int motorPin1 = 03;
const int motorPin2 = 05;
const int motorPin3 = 06;
const int motorPin4 = 09;
const int dirButton = 10;
const int direction = 01;

int speed= 0;
const int slider = A0;
void setup()
{
	pinMode(direction,OUTPUT);
	pinMode(dirButton,INPUT);
	pinMode(slider,INPUT);

	pinMode(motorPin1,OUTPUT);
	pinMode(motorPin2,OUTPUT);
	pinMode(motorPin3,OUTPUT);
	pinMode(motorPin4,OUTPUT);
}

void loop()
{
	speed = analogRead(slider);

	analogWrite(motorPin1,speed/4);
	analogWrite(motorPin2,speed/4);
	analogWrite(motorPin3,speed/4);
	analogWrite(motorPin4,speed/4);

	digitalWrite(direction,digitalRead(dirButton));
}
