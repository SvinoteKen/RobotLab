//LR3_1_Podluzhny_IVT1
#include "DHT.h"

#define DHTPIN 2     // к какому пину будет подключен вывод Data
//выбор используемого датчика
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
//инициализация датчика
int ledPin = 13;
int switchPin = 8;
int value = 0;
DHT dht(DHTPIN, DHTTYPE);

 void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  dht.begin();
}

 

void loop() {
  // чтение температуры и влажности займет примерно 250 миллисекунд
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // проверяем правильные ли данные получили
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Error reading from DHT");
  } 
  else 
  {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
  }
   value = digitalRead(switchPin);
    if (HIGH == value) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}
