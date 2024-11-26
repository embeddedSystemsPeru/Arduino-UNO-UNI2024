#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//declaracion de variables
float humedad = 0;
float temperatura = 0;

DHT dht(2, DHT22);    //configuracion del DHT(pin conectado y tipo)
LiquidCrystal_I2C lcd(0x27,16,2); //conf del LCD I2C


void setup() {
  // put your setup code here, to run once:
  //inicializacion del LCD
  lcd.init();
  lcd.backlight();
  //inicializacion del DHT11
  dht.begin();
  pantallazo();
}

void pantallazo(){
  lcd.setCursor(0,0);
  lcd.print("Sensor DHT22");
  lcd.setCursor(0,1);
  lcd.print("Cargando...");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();
  float f = dht.readTemperature(true);

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.write(0xDF);
  lcd.print('C');
  lcd.setCursor(0,1);
  lcd.print("Humedad:");
  lcd.print(humedad);
  lcd.print("%RH");
  delay(1000);  
}
