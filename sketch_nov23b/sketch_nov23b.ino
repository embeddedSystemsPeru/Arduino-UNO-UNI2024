#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4 
#define DHTTYPE DHT11

//declaramos variables
//float temperatura = 0;
//float humedad = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  dht.begin();
  lcd.backlight();
  pantallon();
}

void pantallon(){
  lcd.setCursor(0,0);
  lcd.print("MIA 23/11/2024");
  lcd.setCursor(0,1);
  lcd.print("Cargando");
  for(int x=0;x<8;x++){
    lcd.print('.');
    delay(500);
  }
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.write(0xDF);
  lcd.print('C');
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(humedad);
  lcd.print("%RH");
  delay(2000);
}