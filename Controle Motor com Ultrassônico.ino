#include <Servo.h>

int distancia_esq, distancia_dir;
int Vel_100 = 255, Vel_70 = 180;
boolean frente = true;

Servo Motor;

void setup()
{
   Serial.begin(9600);
//Servo
   Motor.attach(10, 600, 2200);
//Motor
   pinMode(3, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(11, OUTPUT);
//Sensor Distância
   pinMode(4, OUTPUT);
   pinMode(7, INPUT);
}

void move(int M1a, int M1b, int M2a, int M2b)
{
   analogWrite(3, M1a);
   analogWrite(5, M1b);
   analogWrite(6, M2a);
   analogWrite(11, M2b);
}

int ler_distancia()
{
   int tempo, distancia;
   delayMicroseconds(2);
   digitalWrite(4, HIGH);
   delayMicroseconds(20);
   digitalWrite(4, LOW);
   tempo = pulseIn(7, HIGH);
   distancia = (tempo/2) / 29.15;
   Serial.print(distancia);
   Serial.print(" cm");
   Serial.println();
   return(distancia);
}

void loop()
{
   if (ler_distancia() >= 25)
   {
      frente = true;
      Motor.write(90);
      move(Vel_100, 0, Vel_100, 0);}
     
    else
    {  if (frente) {
	 move(0,0,0,0);
	 Motor.write(+45);
	 delay(1000);
	 distancia_esq = ler_distancia();
	 Motor.write(+135);
	 delay(2000);
	 distancia_dir = ler_distancia();
	 Motor.write(90);
	 frente = false;}
	
	if (distancia_dir > distancia_esq)
	 { move(0,0,0,Vel_70); }
	 else{ move(0, Vel_70, 0, 0); }
	}
}	