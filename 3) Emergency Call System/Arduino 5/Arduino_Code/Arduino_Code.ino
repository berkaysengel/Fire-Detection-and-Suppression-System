#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int A = 8;
int B = 7;
int C = A2;
int D = A1;
int E = A0;
int F = 9;
int G = 10;
int DP = A3;
int noelectricity = 13;
int slideswitch = 6;
int controller, electricblocker, pointer = 0;
unsigned long timer;
unsigned long calculator;
char loading[] = {'.', '.', '.'};
char stop[] = {'S', 'h', 'u', 't', 't', 'i', 'n', 'g', ' ', 'D', 'o', 'w', 'n'};

void setup() {
pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(F, OUTPUT);
pinMode(G, OUTPUT);
pinMode(DP, OUTPUT);
pinMode(slideswitch, INPUT);
pinMode(noelectricity,OUTPUT);
lcd.begin(16, 2);
Serial.begin(9600);
}
void loop() {
 int counter = digitalRead(slideswitch);
 timer=millis();
 if(counter==1)
 {
 if(timer>=9000 && timer<30000)
 {
 lcd.clear();
 lcd.setCursor(2,0);
 lcd.print("Deactivation");
 lcd.setCursor(6,1);
 lcd.print("Code");
 delay(600);
 one();
 delay(400);
 nine();
 delay(400);
 zero();
 delay(400);
 one();
 delay(400);
 eight();
 delay(400);
 zero();
 delay(400);
 two();
 delay(400);
 end();
 delay(600);
 lcd.clear();
 digitalWrite (G, LOW);
 }
   if(timer>=9000 && timer<40000)
   {
     timer=millis();
     calculator=39-timer/1000;
   if(calculator<=30 && calculator>10)
   {
     lcd.print("Remaining Time:");
     lcd.setCursor(3,1);
     timer=millis();
     lcd.print(String(39-timer/1000) + " second.");
     delay(1000);
     lcd.clear();
   }
   if(calculator<=10)
   {
     for(byte i=0; i<=calculator; i++)
     {
     lcd.print("Remaining Time:");
     lcd.setCursor(3,1);
     timer=millis();
     lcd.print(String(39-timer/1000) + " second.");
     delay(1000);
     lcd.clear();
     }
   }
 }
  if(timer<4520)
  {
  lcd.print("Received Signal");
  lcd.setCursor(3,1);
  lcd.print("from ECS.");
  delay(1120);
  lcd.clear();
  delay(1120);
  lcd.setCursor(2,0);
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("Password System.");
  delay(1120);
  lcd.clear();
  delay(1120);
  }
   if(timer<5000)
   {
  pointer++;
  lcd.setCursor(1,0);
  lcd.print("Connecting");
  lcd.setCursor(11,0);
  for (byte i=0; i<3; i++)
 {
    lcd.write(loading[i]);
    delay(1332);
}
     lcd.clear();
   }
  if(timer>=5000 && timer<8500 && pointer == 0)
  {
  lcd.setCursor(2,0);
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("Password System.");
  }
  if(timer>=40000 && timer<=47000)
  {
  electricblocker++;
  lcd.setCursor(2,0);
  lcd.print("Time is up!");
  delay(3000);
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
  lcd.clear();
  digitalWrite (G, LOW);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  }
 if(timer>47000)
 {
  if(controller==0 && electricblocker == 0)
  {
  controller++;
  for (int j = 0; j <= 12; j++) {
  lcd.setCursor(16, 0);
  lcd.print("No Signal");
  lcd.setCursor(16, 1);
  lcd.print("from ECS.");
  delay(100);
  lcd.scrollDisplayLeft();
}
  delay(2000);
  lcd.clear();
  delay(1000);
  for (byte i=0; i<2; i++)
{
  lcd.setCursor(3,0);
  lcd.print("No Signal");
  lcd.setCursor(3,1);
  lcd.print("from ECS.");
  delay(1500);
  lcd.clear();
  delay(1500);
}
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
  digitalWrite (G, LOW);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000); 
 }
 }
  else
  {
  lcd.clear();
  digitalWrite (G, LOW);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  }
 }
  void zero(){
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, LOW);
  digitalWrite (DP, LOW); 
  }
  void one(){
  digitalWrite (A, LOW);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (DP, LOW);
  }
  void two(){
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, LOW);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, LOW);
  digitalWrite (G, HIGH);
  digitalWrite (DP, LOW);
  }
  void eight (){
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
  digitalWrite (DP, LOW);
  }
  void nine(){
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, LOW);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
  digitalWrite (DP, LOW);
 }
  void end(){
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, HIGH);
  digitalWrite (DP, LOW);
 }
