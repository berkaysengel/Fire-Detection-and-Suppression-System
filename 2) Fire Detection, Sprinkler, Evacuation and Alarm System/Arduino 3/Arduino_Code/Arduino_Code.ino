#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define pinTemp A0
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
int buzzer = A1;
int slideswitch = 9;
int noelectricity = 13;
int checker, controller = 0;
char start[] = {'S', 't', 'a', 'r', 't', 'i', 'n', 'g'};
char loading[] = {'.', '.', '.'};
char shutdown[] = {'S', 'h', 'u', 't', 't', 'i', 'n', 'g', ' ', 'D', 'o', 'w', 'n'};

#include <Servo.h>
Servo servomotor1;
Servo servomotor2;

void setup() {
  pinMode(pinTemp,INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(noelectricity,OUTPUT);
  pinMode(slideswitch, INPUT);
  servomotor1.attach(8);
  servomotor2.attach(10);
  Serial.begin(9600);
  lcd.begin(16, 2);
  }
void loop() {
  int counter;
  counter= digitalRead(slideswitch);
  if(counter==0)
     {
    lcd.clear();
    Stop();
  }
  else
  {
  Start();
  } 
}
void Start()
  {
  controller++;
  if(checker==0)
  {
  checker++;
  lcd.setCursor(2,0);
 for (byte i=0; i<8; i++)
 {
  lcd.write(start[i]);
  delay(200);
 }
  lcd.setCursor(10,0);
for (byte i=0; i<3; i++)
 {
  lcd.write(loading[i]);
  delay(1000);
 }
  lcd.clear();
  }
  baselineTemp = 50;
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  if (celsius >= baselineTemp) 
   {
   digitalWrite(6, HIGH);
   digitalWrite(7, LOW);
   tone(buzzer, 1000,10000);
   servomotor1.write(180);
   servomotor2.write(180);
   }
  else
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    noTone(buzzer);
    servomotor1.write(0);
    servomotor2.write(0);
  }
 float temp = ((analogRead(pinTemp) * (5.0/1024))-0.5 )/0.01;
 lcd.setCursor(2, 0);
 lcd.print("Temperature:");
 lcd.setCursor(0, 1);
 lcd.print("                ");
 delay(1000);
 lcd.setCursor(4, 1);
 lcd.print( temp );
 lcd.print(" C");
 Serial.println( temp );
 delay(1000);
 lcd.clear();
  if(temp>=baselineTemp)
  {
  lcd.setCursor(4,0);
  lcd.print("Warning");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("High Temperature");
  delay(1000);
  }
  else
   {
  lcd.setCursor(6,0);
  lcd.print("Safe");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Completely Clear");
  delay(1000);
   }
 }
  void Stop()
  {
  if(controller != 0)
  {
  controller=0;
   for (byte i=0; i<13; i++)
 {
  lcd.write(shutdown[i]);
  delay(200);
 }
  lcd.setCursor(13,0);
  for (byte i=0; i<3; i++)
 {
  lcd.write(loading[i]);
  delay(1000);
 } 
   }
  checker=0;
  lcd.clear();
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  noTone(buzzer);
  servomotor1.write(90);
  servomotor2.write(90);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  }
