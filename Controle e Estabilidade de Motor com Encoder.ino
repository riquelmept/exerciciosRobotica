#include "TimerOne.h"

int Vel = 0;
int PulsosPorVolta = 20, Pulsos = 0, PulsoFinal;
int RPM1 = 90, RPM2 = 45;

void ContaPulsos(){
   Pulsos = Pulsos +1;
}
   
void AjusteVelocidade(){
   Vel = Vel + 1 *(PulsoFinal - Pulsos);
   if(Vel>255) Vel = 255;
   Serial.print(Pulsos);
   Pulsos = 0;
   Serial.print(" - ");
   Serial.println(Vel);
   analogWrite(5, Vel);
}
void setup()
 { 
   Timer1.initialize(1000000);
   Timer1.attachInterrupt(AjusteVelocidade);
   pinMode(4, INPUT_PULLUP);
   pinMode(2, INPUT_PULLUP);
   attachInterrupt(0, ContaPulsos, RISING);
   Serial.begin(9600);
   analogWrite(5, Vel);
   analogWrite(6, 0);
 }

void loop()
 {
   if(digitalRead(4) == LOW){
      PulsoFinal = (RPM1 *  PulsosPorVolta)/60;
     }
     else{
	 PulsoFinal = (RPM2 * PulsosPorVolta)/60;
      }
 }
