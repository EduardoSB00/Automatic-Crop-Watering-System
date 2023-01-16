
//Primero tendremos que incluir las siguientes librerias para utilizar el LCD y el Servo motor
#include <LiquidCrystal.h>
#include <Servo.h>
int umbral1;
int umbral2;
//Establecemos una variable especifica del lcd con los pines asociados
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Establecemmos una variable especifica para utilizar el servomotor
Servo Servo1;

//En esta variable guardaremos el valor del sensor
int sensor;
int sensor2;
int maiz;
int frijol;
int cafe;
void setup() {
  
  // Establecemos todos los pines que estaremos utilizando para interactuar con los otros componentes
  
  pinMode (A0,INPUT);
  pinMode (A1,INPUT);
  pinMode (10,INPUT);
   pinMode (8,INPUT);
   pinMode (7,INPUT);
  //Inicializamos el motor
  Servo1.attach(9);
  
  //Inicializamos la pantalla Lcd
  lcd.begin(16, 2);
  
  //Mensaje de incio al prender el sistema
  lcd.print("System Online");
  delay (5000);
  lcd.clear();   
}

void loop() {
// guardamos el valor del sensor
 sensor = analogRead(A0);
 sensor2 =analogRead (A1);
 maiz = digitalRead(10);
 frijol = digitalRead(8);
 cafe = digitalRead(7);
  
  
  if (maiz==HIGH){
    umbral1 =500;
     umbral2 =700;
  }else
  
    if (frijol==HIGH){
    umbral1 =700;
     umbral2 =700;
  }else
  
  
    if (cafe==HIGH){
    umbral1 =900;
     umbral2 =800;
  }else{
    umbral1=umbral1;
    umbral2=umbral2;
  }
  
  
  
  if((sensor<umbral1)||(sensor2>umbral2)){
    
  Servo1.write(90);  
  lcd.print("Watering");
  }else{
    Servo1.write(0);
    lcd.print("Standby");
  }
delay (1000);
  //reseteo del display para poder escribir algo nuevo en la siguiente iteracion del codigo
   lcd.clear();  

}   