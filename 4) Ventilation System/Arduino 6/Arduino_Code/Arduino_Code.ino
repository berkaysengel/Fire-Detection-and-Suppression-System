#include <LiquidCrystal.h>
#include <IRremote.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

int RECV_PIN = 8;
int counter = 0;
int noelectricity = 13;
char loading[] = {'.', '.', '.'};
char shutdown[] = {'S', 'h', 'u', 't', 't', 'i', 'n', 'g', ' ', 'D', 'o', 'w', 'n'};
char activate[] = {'A', 'c', 't', 'i', 'v', 'a', 't', 'i', 'n', 'g'};
char deactivate[] = {'D', 'e', 'a', 'c', 't', 'i', 'v', 'a', 't', 'i', 'n', 'g'};
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
irrecv.enableIRIn();
pinMode(2,OUTPUT);
pinMode(noelectricity,OUTPUT);
lcd.begin(16, 2);
Serial.begin(9600);
}
void loop()
{
 if(irrecv.decode(&results))
    {
    irrecv.resume();
 if(results.value == 0xFD00FF && counter == 0)
    {
      counter = 1;
      Open();
    }
 else if(results.value == 0xFD00FF && counter == 1)
    {
      counter = 0;
      Close();
    }
    delay(100);
  }
else if(counter==0)
{
 lcd.clear();
 digitalWrite(2,LOW);
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 delay(1000);
}
}
void Open()
{
  lcd.clear();
  for (int j = 0; j <= 13; j++) {
  lcd.setCursor(16, 0);
  lcd.print("Ventilation");
  lcd.setCursor(19, 1);
  lcd.print("System");
  delay(50);
  lcd.scrollDisplayLeft();
}
  delay(2500);
  lcd.clear();
  for (int j = 0; j <= 1; j++){
  lcd.setCursor(3,0);
  lcd.print("Procedure");
  delay(1500);
  lcd.setCursor(4,1);
  lcd.print("Started");
  delay(1500);
  lcd.clear();
  delay(500);
}
 lcd.setCursor(1,0);
 for (byte i=0; i<10; i++)
 {
 lcd.write(activate[i]);
 delay(200);
 }
 lcd.setCursor(11,0);
for (byte i=0; i<3; i++)
 {
 lcd.write(loading[i]);
 delay(1000);
 }
  lcd.clear();
  digitalWrite(2,HIGH);
  lcd.setCursor(3,0);
  lcd.print("Active now");
}
void Close()
{
  lcd.clear();
  for (int j = 0; j <= 13; j++) {
  lcd.setCursor(16, 0);
  lcd.print("Ventilation");
  lcd.setCursor(19, 1);
  lcd.print("System");
  delay(50);
  lcd.scrollDisplayLeft();
}
  delay(2500);
  lcd.clear();
  for (int j = 0; j <= 1; j++){
  lcd.setCursor(3,0);
  lcd.print("Procedure");
  delay(1500);
  lcd.setCursor(4,1);
  lcd.print("Stopped");
  delay(1500);
  lcd.clear();
  delay(500);
    }
  for (byte i=0; i<12; i++)
 {
  lcd.write(deactivate[i]);
  delay(200);
 }
  lcd.setCursor(12,0);
 for (byte i=0; i<3; i++)
 {
  lcd.write(loading[i]);
  delay(1000);
 }
  lcd.clear();
  digitalWrite(2,LOW);
  lcd.setCursor(2,0);
  lcd.print("Inactive now");
  delay(4000);
  lcd.clear();
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
  lcd.clear();
}
