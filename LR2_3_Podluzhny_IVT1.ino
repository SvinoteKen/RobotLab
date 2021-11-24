//LR2_3 Podluzhny IVT-1

const byte speedPinButton = 11; // пин, отвечающий за скорость вращения
const byte directionPinButton = 13; // пин, отвечающий за направление вращения
const byte RezPinButton = 12; // пин коммутируемого резистора, отвечающей за направление вращения

int distance; //(м.) расстояние которое должен проехать робот
int time; //(сек.) время за которое робот должен проехать
float chastota; //(об./мин.) частота вращения редуктора вала
float u; //напряжение питания двигателя
float speed; //скорость двигателя 0-255word
String str;
String distStr;
String timeStr;
byte dividerIndex;
void setup()
{
	pinMode(speedPinButton, OUTPUT);
	pinMode(directionPinButton, OUTPUT);
	pinMode(RezPinButton, INPUT);
	Serial.begin(9600);
	distance = 2;//значение для примера
	time = 5;//значение для примера
	Serial.println("LR2_3 Podluzhny IVT-1");
	Serial.println("Введите расстояние и время через пробел");
}

void loop()
{
	if(Serial.available()>0)
	{
		str = Serial.readString();
		// находим пробел
		dividerIndex = str.indexOf(' ');
		// получаем расстояние и время
		distStr = str.substring(0, dividerIndex);
		timeStr = str.substring(dividerIndex + 1);
		// переводим в int
		distance = distStr.toInt();
		time = timeStr.toInt();
		chastota = (((float)distance/(float)time)/(3.14*0.065))*60; //подсчет частоты вращения вала
		u = chastota*0.01 + 1.9;//подсчет напряжения питания двигателя
		speed = 255-(((8-u)*255)/4.8);//это аналог map(u,3.2,8,0,255)
		if(speed > 0 && speed < 255)//проверка может ли робот иметь подсчитаную скорость
		{
			analogWrite(speedPinButton, speed); // установка скорости
			digitalWrite(directionPinButton, digitalRead(RezPinButton)); // установка направления
			delay(time*1000);//время движения робота
			analogWrite(speedPinButton, 0);//остановка двигателя
		}
		else//если скрость недопустимая, то выводится надпись
		{
			Serial.print("Этот робот не может иметь такую скорость");
		}
	}
}
