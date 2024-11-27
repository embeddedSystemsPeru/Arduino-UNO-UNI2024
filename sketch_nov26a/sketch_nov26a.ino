#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  //conf LCDI2C tamaño 16x2

int tiempo_hcsr04 = 0;    //variable que alojará el tiempo del pulso en ECHO
float distancia = 0;
int distancia_int;

void setup() {
  // put your setup code here, to run once:
  lcd.init();   //inicialice el LCD_I2C
  lcd.backlight();  //enciende la luz de fondo del LCD
  //conf de los puertos de E/S
  pinMode(4, OUTPUT);   //salida para el LED en 4
  pinMode(2, OUTPUT);   //salida en 2 para el TRIG del HCSR04
  pinMode(3, INPUT);    //entrada en 3 para el ECHO del HCSR04
  pantallazo();
}

void pantallazo(){
  lcd.setCursor(0,0);
  lcd.print("Prueba de HCSR04");
  lcd.setCursor(0,1);
  lcd.print("Cargando...");
  for(int x_var=0;x_var<15;x_var++){
    digitalWrite(4, HIGH);
    delay(100);   //retardo en terminos de milisegundo
    digitalWrite(4, LOW);
    delay(100);
  }
  lcd.clear();
}

void pulso_hcsr04(){
  digitalWrite(2, HIGH);
  delayMicroseconds(10);    //retardo de 10 microsegundos
  digitalWrite(2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulso_hcsr04();   //mando el pulso de 10us
  tiempo_hcsr04 = pulseIn(3, HIGH);
  lcd.setCursor(0,0);
  //lcd.print("Tiempo del pulso");
  //lcd.setCursor(0,1);
  lcd.print("Echo:");
  lcd.print((tiempo_hcsr04/10000),DEC); //digito diezmillar
  lcd.print(((tiempo_hcsr04%10000)/1000),DEC); //digito millar
  lcd.print(((tiempo_hcsr04%1000)/100),DEC); //digito centena
  lcd.print(((tiempo_hcsr04%100)/10),DEC); //digito decena
  lcd.print((tiempo_hcsr04%10),DEC); //digito unidad
  lcd.print("us");
  lcd.setCursor(0,1);
  lcd.print("Dist:");
  distancia = tiempo_hcsr04 / 58.31;
  distancia_int = distancia;
  lcd.print((distancia_int/100),DEC); //digito centena
  lcd.print(((distancia_int%100)/10),DEC); //digito decena
  lcd.print((distancia_int%10),DEC); //digito unidad
  lcd.print("cm");
  if(tiempo_hcsr04 >= 5847){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);    
  }
}
