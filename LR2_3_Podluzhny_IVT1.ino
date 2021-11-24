//LR2_3 Podluzhny IVT-1

const byte speedPinButton = 11; // ���, ���������� �� �������� ��������
const byte directionPinButton = 13; // ���, ���������� �� ����������� ��������
const byte RezPinButton = 12; // ��� �������������� ���������, ���������� �� ����������� ��������

int distance; //(�.) ���������� ������� ������ �������� �����
int time; //(���.) ����� �� ������� ����� ������ ��������
float chastota; //(��./���.) ������� �������� ��������� ����
float u; //���������� ������� ���������
float speed; //�������� ��������� 0-255word
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
	distance = 2;//�������� ��� �������
	time = 5;//�������� ��� �������
	Serial.println("LR2_3 Podluzhny IVT-1");
	Serial.println("������� ���������� � ����� ����� ������");
}

void loop()
{
	if(Serial.available()>0)
	{
		str = Serial.readString();
		// ������� ������
		dividerIndex = str.indexOf(' ');
		// �������� ���������� � �����
		distStr = str.substring(0, dividerIndex);
		timeStr = str.substring(dividerIndex + 1);
		// ��������� � int
		distance = distStr.toInt();
		time = timeStr.toInt();
		chastota = (((float)distance/(float)time)/(3.14*0.065))*60; //������� ������� �������� ����
		u = chastota*0.01 + 1.9;//������� ���������� ������� ���������
		speed = 255-(((8-u)*255)/4.8);//��� ������ map(u,3.2,8,0,255)
		if(speed > 0 && speed < 255)//�������� ����� �� ����� ����� ����������� ��������
		{
			analogWrite(speedPinButton, speed); // ��������� ��������
			digitalWrite(directionPinButton, digitalRead(RezPinButton)); // ��������� �����������
			delay(time*1000);//����� �������� ������
			analogWrite(speedPinButton, 0);//��������� ���������
		}
		else//���� ������� ������������, �� ��������� �������
		{
			Serial.print("���� ����� �� ����� ����� ����� ��������");
		}
	}
}
