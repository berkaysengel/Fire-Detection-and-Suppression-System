#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int BlueLed = 6;
int GreenLed = 7;
int RedLed = 8;
int YellowRed = 9;
int noelectricity = 13;
int count, onlyone = 0;
int slideswitch = 10;
char developer[] = {'B', 'e', 'r', 'k', 'a', 'y', ' ', 'S', 'E', 'N', 'G', 'E', 'L'};
char BAU[] = {'B', 'a', 'h', 'c', 'e', 's', 'e', 'h', 'i', 'r', ' ', 'U', 'n', 'i'};
char start[] = {'S', 't', 'a', 'r', 't', 'i', 'n', 'g'};
char loading[] = {'.', '.', '.'};
char shutdown[] = {'S', 'h', 'u', 't', 't', 'i', 'n', 'g', ' ', 'D', 'o', 'w', 'n'};
void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(slideswitch, INPUT);
  pinMode(noelectricity,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop() 
{
  int counter;
  counter= digitalRead(slideswitch);
  if(counter==0)
  {
  Stop();
  }
  else
  {
  onlyone++;
  Start();  
  }
}
  void Start()
  {
  if(count==0)
  {
  count++;
  for (int i = 0; i <= 12; i++) {
  lcd.setCursor(19, 0);
  lcd.print("Fire");
  lcd.setCursor(17, 1);
  lcd.print("Detection");
  delay(100);
  lcd.scrollDisplayLeft();
  }
  delay(3000);
  lcd.clear();
  for (int i = 0; i <= 14; i++) {
  lcd.setCursor(17, 0);
  lcd.print("Suppression");
  lcd.setCursor(20, 1);
  lcd.print("System");
  delay(100);
  lcd.scrollDisplayLeft();
  }
  delay(3000);
  lcd.clear();
  delay(500);
  lcd.setCursor(2,0);
  lcd.print("Developer:");
  delay(1500);
  lcd.setCursor(1,1);
for (byte i=0; i<13; i++)
 {
  lcd.write(developer[i]);
  delay(200);
 }
  delay(5000);
  lcd.clear();
  delay(500);
  lcd.setCursor(1,0);
for (byte i=0; i<=13; i++)
 {
  lcd.write(BAU[i]);
  delay(200);
 }
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print("E.E. Engineering");
  delay(3000);
  lcd.clear();
  delay(500);
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
    delay(1500);
  }
    else
    {
  lcd.setCursor(1, 0);
  lcd.print("Berkay SENGEL");
  digitalWrite(6, HIGH);
  delay(2000);
  lcd.setCursor(4, 1);
  lcd.print("1901802");
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(2000);
  lcd.clear();
  digitalWrite(7, LOW);
  delay(2000);
  lcd.setCursor(1, 0);
  lcd.print("Berkay SENGEL");
  digitalWrite(8, HIGH);
  delay(2000);
  lcd.setCursor(4, 1);
  lcd.print("1901802");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9, LOW);
  lcd.clear();
  delay(2000);
  }
    }
void Stop()
{
 if(onlyone !=0)
 {
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
 if(count !=0 && onlyone != 0)
 {
   onlyone=0;
   count=0;
 }
 digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);
 lcd.clear();
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 delay(1000);
}
