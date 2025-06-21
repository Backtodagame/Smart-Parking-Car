#include<LiquidCrystal.h>
#include<Servo.h>
LiquidCrystal lcd(13,12,7,5,6,4);
int cambien = 10;
int dem=0;
int pre=HIGH;
Servo dongco ;
void setup() {
  // put your setup code here, to run once:
  dongco.attach(11);
  lcd.begin(16,2);
  pinMode(cambien,INPUT);
  dongco.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int doccambien=digitalRead(cambien);
  if(doccambien ==0 and pre==HIGH and dem<=4)
  { 
    dem++;
    dongco.write(90);
  }


  pre=doccambien;
  if(pre==HIGH)
  { delay(2000);
    dongco.write(0);
  }
  if(doccambien==0 and dem==5)
  {
    lcd.setCursor(9,1);
    lcd.print("FULL");
  }
  lcd.setCursor(0, 0);
  lcd.print("Number Of Car");
  lcd.setCursor(5,1);
  lcd.print(dem);
  lcd.print("/5");
}
