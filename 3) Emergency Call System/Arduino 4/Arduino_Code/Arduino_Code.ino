#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, A3, 5, 4, 3, 2);

 const byte ROWS = 4;
 const byte COLS = 4;
 char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', 'E', '#', 'D'}
};
byte rowPins[ROWS] = {10, 9, 8, 7};
byte colPins[COLS] = {6, A0, A1, A2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String pressed= "";
String password= "19E18E2";
int counter,checker, timeoutblocker = 0;
int onlyone = 1;
int attemptsleft = 2;
int noelectricity = 13;
int redled=11;
int greenled=A4;
int buzzer = A5;
unsigned long timer;
char success[] = {'C', 'o', 'r', 'r', 'e', 'c', 't', ' ', 'P', 'a', 's', 's', 'w', 'o', 'r', 'd'};
char fail[] = {'W', 'r', 'o', 'n', 'g', ' ', 'P', 'a', 's', 's', 'w', 'o', 'r', 'd'};
char resetting[] = {'R', 'e', 's', 'e', 't', 't', 'i', 'n', 'g'};
char loading[] = {'.', '.', '.'};
char stop[] = {'S', 'h', 'u', 't', 't', 'i', 'n', 'g', ' ', 'D', 'o', 'w', 'n'};
void setup()
{
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(noelectricity,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  analogWrite(greenled,255);
  analogWrite(redled,0);
  for (int j = 0; j <= 14; j++) {
  lcd.setCursor(16, 0);
  lcd.print("Emergency Call");
  lcd.setCursor(20, 1);
  lcd.print("System");
  delay(100);
  lcd.scrollDisplayLeft();
}
  delay(4000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Information:");
  lcd.setCursor(0,1);
  lcd.print("30 seconds left.");
  delay(3500);
  initializeLcd();
}
void loop()
{
timer=millis();
if(timer<40000)
{
Main();
}
if(timer>=40000 && timeoutblocker ==0)
{
if(onlyone==1)
{
onlyone++;
lcd.clear();
lcd.setCursor(2,0);
lcd.print("Time is up!");
analogWrite(redled,255);
analogWrite(greenled,0);
delay(3000);
lcd.clear();
for (int j = 0; j <= 14; j++) {
  lcd.setCursor(16, 0);
  lcd.print("Emergency Call");
  lcd.setCursor(20, 1);
  lcd.print("System");
  delay(100);
  lcd.scrollDisplayLeft();
}
  delay(750);
  lcd.clear();
for (int j = 0; j <= 1; j++){
lcd.setCursor(2,0);
lcd.print("Deactivation");
lcd.setCursor(4,1);
lcd.print("Failed!");
delay(1000);
lcd.clear();
delay(500);
}
lcd.setCursor(1,0);
lcd.print("Call Procedure");
delay(1500);
lcd.setCursor(4,1);
lcd.print("Starting");
delay(500);
tone(buzzer, 1000,10000);
delay(3000);
lcd.clear();
lcd.setCursor(6,0);
lcd.print("Done");
noTone(buzzer);
delay(1500);
lcd.clear();
for (byte i=0; i<13; i++)
 {
 lcd.write(stop[i]);
 delay(400);
 }
 lcd.setCursor(13,0);
for (byte i=0; i<3; i++)
 {
 lcd.write(loading[i]);
 delay(1500);
 }
}
 lcd.clear();
 analogWrite(redled,0);
 analogWrite(greenled,0);
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 delay(1000);
}
if(timer>=40000 && timeoutblocker ==1)
{
 lcd.clear();
 analogWrite(redled,0);
 analogWrite(greenled,0);
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 delay(1000);
 }
}
void Main()
{
if(counter<3 && checker== 0)
{
Start();
}
  else
  {
Stop();
  }
}
void Start()
{
  char key = keypad.getKey();
  if(int(key) != 0)
  {
    if(key == 'C')
    {
    Reset();
    initializeLcd();
    }
    else if(key == '*')
    {
      checkPassword();
    }
    else
    {
      pressed.concat(key);
      lcd.print("*");
      Serial.print(key);
    }
  }
}
void Stop()
{
if(checker==1)
{
checker++;
analogWrite(redled,0);
analogWrite(greenled,255);
  for (int j = 0; j <= 14; j++) {
  lcd.setCursor(16, 0);
  lcd.print("Emergency Call");
  lcd.setCursor(20, 1);
  lcd.print("System");
  delay(100);
  lcd.scrollDisplayLeft();
}
  delay(750);
  lcd.clear();
for (int j = 0; j <= 1; j++){
lcd.setCursor(2,0);
lcd.print("Deactivated");
delay(1000);
lcd.clear();
delay(500);
}
lcd.setCursor(1,0);
lcd.print("Call Procedure");
delay(1500);
lcd.setCursor(3,1);
lcd.print("Canceling");
delay(3500);
lcd.clear();
lcd.setCursor(6,0);
lcd.print("Done");
delay(1500);
lcd.clear();
for (byte i=0; i<13; i++)
 {
 lcd.write(stop[i]);
 delay(400);
 }
 lcd.setCursor(13,0);
for (byte i=0; i<3; i++)
 {
 lcd.write(loading[i]);
 delay(1500);
 }
}
if(checker ==0)
{
checker=checker+2;
analogWrite(redled,255);
analogWrite(greenled,0);
  for (int j = 0; j <= 14; j++) {
  lcd.setCursor(16, 0);
  lcd.print("Emergency Call");
  lcd.setCursor(20, 1);
  lcd.print("System");
  delay(100);
  lcd.scrollDisplayLeft();
}
  delay(750);
  lcd.clear();
for (int j = 0; j <= 1; j++){
lcd.setCursor(2,0);
lcd.print("Deactivation");
lcd.setCursor(4,1);
lcd.print("Failed!");
delay(1000);
lcd.clear();
delay(500);
}
lcd.setCursor(1,0);
lcd.print("Call Procedure");
delay(1500);
lcd.setCursor(4,1);
lcd.print("Starting");
delay(500);
tone(buzzer, 1000,10000);
delay(3000);
lcd.clear();
lcd.setCursor(6,0);
lcd.print("Done");
noTone(buzzer);
delay(1500);
lcd.clear();
for (byte i=0; i<13; i++)
 {
 lcd.write(stop[i]);
 delay(400);
 }
 lcd.setCursor(13,0);
for (byte i=0; i<3; i++)
 {
 lcd.write(loading[i]);
 delay(1500);
 }
}
 lcd.clear();
 analogWrite(redled,0);
 analogWrite(greenled,0);
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 delay(1000);
}
void initializeLcd()
{
  lcd.clear();
  pressed= "";
  lcd.print("Enter Password:");
  lcd.setCursor(0,1);
}
void checkPassword()
{
    counter++;
  if(pressed == password)
  {
    checker++;
    timeoutblocker++;
    lcd.clear();
    for (byte i=0; i<16; i++)
 {
    lcd.write(success[i]);
    delay(500);
 }
    delay(1500);
    if (timer<22000)
    {
      delay(3000);
    }
    lcd.clear();
    Stop();
  }
  else
  {
    lcd.clear();
    lcd.setCursor(1,0);
    for (byte i=0; i<14; i++)
 {
    lcd.write(fail[i]);
    delay(300);
 }
    delay(1000);
    lcd.clear();
    if (attemptsleft==0)
    {
     lcd.print("No attempts left"); 
     delay(1000);
     lcd.clear();
    }
    else
    {
    lcd.print(String(attemptsleft) + " attempts left.");
    delay(1000);
    attemptsleft--;
    initializeLcd();
    }
  }
}
void Reset()
{
 pressed="";
 lcd.clear();
 lcd.setCursor(2,0);
 for (byte i=0; i<9; i++)
 {
 lcd.write(resetting[i]);
 delay(300);
 }
 for (byte i=0; i<3; i++)
 {
 lcd.write(loading[i]);
 delay(600);
 }
}
