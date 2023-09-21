#include <Stepper.h>

Stepper MotorPasso1(200, 8, 9, 10,11);
float Angulo = 0;
int Tempo;

void setup(){
   MotorPasso1.setSpeed(3600);
   Serial.begin(9600);
   pinMode(5, INPUT_PULLUP);
}

void loop(){
   Tempo = map(analogRead(A0), 0,1023,20,1000);
   if(digitalRead(5) == HIGH){
      MotorPasso1.step(+1);
      Angulo = Angulo + 1.8;
      }
      
   else{
      MotorPasso1.step(-1);
      Angulo = Angulo - 1.8;
      }
      
      Serial.println(Angulo);
      delay(Tempo);
}