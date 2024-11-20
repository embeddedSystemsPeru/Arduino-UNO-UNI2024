#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int potenciometro = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.init();   //funcion para inicializar el LCD
  lcd.clear();
  lcd.backlight();
  pantallazo();
}

void pantallazo(){
  lcd.setCursor(0,0);
  lcd.print("Hola mundo!");
  lcd.setCursor(0,1);
  lcd.print("FIIS MIA SETR GA");
  delay(4000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  potenciometro = analogRead(A0);
  lcd.setCursor(0,0);
  lcd.print("Lectura del pot:");
  lcd.setCursor(0,1);
  lcd.print("Puerto A0:");
  lcd.print(potenciometro/1000,DEC);      //muestre el digito millar
  lcd.print((potenciometro%1000)/100,DEC);//muestre el digito centena
  lcd.print((potenciometro%100)/10,DEC);  //muestre el digito decena 
  lcd.print(potenciometro%10,DEC);        //muestre el digito unidad
  //lcd.print("   ");
  delay(50);  
}
