//Primera prueba de circuito en físico empleando Arduino UNO
//Desarrollado por Kalun
//Noviembre del 2024

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);     //pin2 como salida
  pinMode(3, OUTPUT);     //pin3 como salida
  pinMode(4, INPUT);      //pin4 como entrada
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(4) == 1){
    //cuando es verdad
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    delay(100);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    delay(100);
  }
  else{
    //cuando es falso
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
}
