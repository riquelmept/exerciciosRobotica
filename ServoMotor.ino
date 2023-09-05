#include <Servo.h>
Servo Motor0;
 
void setup()
 { 
   Motor0.attach(3,500,2400);
 }

void loop()
{ 
  Motor0.write(map(analogRead(A0) , 0, 1023, 0, 180));
  delay(1000);
 }