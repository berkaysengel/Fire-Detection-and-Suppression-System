#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);
  
int redled = 2;
int greenled = 3;
int sensor = A0;
int buzzer = A1;
int sensorThresh = 400;
int slideswitch = 12;
int noelectricity = 13;
int checker, controller = 0;
char start[] = {'S', 't', 'a', 'r', 't', 'i', 'n', 'g'};
char loading[] = {'.', '.', '.'};
char shutdown[] = {'S', 'h', 'u', 't', 't', 'i', 'n', 'g', ' ', 'D', 'o', 'w', 'n'};

#include <Servo.h>
Servo servomotor1;
Servo servomotor2;

void setup()
{
pinMode(redled,OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
pinMode(slideswitch,INPUT);
pinMode(noelectricity,OUTPUT);
servomotor1.attach(4);
servomotor2.attach(7);
Serial.begin(9600);
lcd.begin(16,2);
}
void loop()
{
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
  int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  if(analogValue>sensorThresh)
  {
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
    tone(buzzer,1000,10000);
    servomotor1.write(180);
    servomotor2.write(180);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Gas Alarm");
    delay(1000);
    lcd.clear();
    lcd.setCursor(2,1);
    lcd.print("Fire Danger");
    delay(1000);
  }
  else
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    noTone(buzzer);
    servomotor1.write(0);
    servomotor2.write(0);
    lcd.clear();
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
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  noTone(buzzer);
  servomotor1.write(90);
  servomotor2.write(90);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
