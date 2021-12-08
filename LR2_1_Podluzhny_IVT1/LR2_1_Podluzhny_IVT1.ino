//LR2_1_Podluzhny_IVT1
#define D1 4          // Направление вращение двигателя 1
#define M1 11          // ШИМ вывод для управления двигателем 1
#define D2 7          // Направление вращение двигателя 2
#define M2 3          // ШИМ вывод для управления двигателем 2
#define D3 8          // Направление вращение двигателя 3
#define M3 5          // ШИМ вывод для управления двигателем 3
#define D4 12          // Направление вращение двигателя 4
#define M4 7          // ШИМ вывод для управления двигателем 4

bool direction = 0;   // Текущее направление вращения      
int value;            // Текущее значение ШИМ

void setup()
{
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT); 
    pinMode(D3, OUTPUT); 
    pinMode(D4, OUTPUT); 
}

void loop()
{
  for(value = 0; value <= 255; value+=1)
  {
    digitalWrite(D1, direction);  // Задаем направление вращения
    digitalWrite(D2, direction);
    digitalWrite(D3, direction);
    digitalWrite(D4, direction);
    analogWrite(M1, value);       // Задаем скорость вращения
    analogWrite(M2, value);
    analogWrite(M3, value);
    analogWrite(M4, value);
    delay(20);
  }
  direction = direction ^ 1;      // Инвертируем значение, чтобы в след. цикле вращаться в другую сторону
}
