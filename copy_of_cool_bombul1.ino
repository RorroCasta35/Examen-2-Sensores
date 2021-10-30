// C++ code
//
#include <LiquidCrystal.h> // se incluye librería con display
LiquidCrystal lcd{12,11,5,4,3,2}; // Conexiones{rs,eneble,d4,d5,d6,d7}

float V = 0.0;
float R = 0.0;
float N = 0.0;
float P = 0.0;

void setup()
{
  pinMode(A0, INPUT);
  lcd.begin(16,2); //Se inicia interfaz del lcd
  Serial.begin(9600);
}

void loop()
{
  V = analogRead(A0);
  V = (V*5)/1023;
  
  R = 1200*((5/V)-1);
  
  if(R>10848)
    N = pow((R/7370.1),(-1/0.865));
  else
    N = pow((R/5991.5),(-1/0.699));
  
  P = N/9.81;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fuerza:");
  lcd.setCursor(9,0);
  lcd.print(N);
  lcd.println(" N ");
  lcd.setCursor(0,1);
  lcd.print("Peso:");
  lcd.setCursor(9,1);
  lcd.print(P);
  lcd.println(" kg");
  delay(2000);
}