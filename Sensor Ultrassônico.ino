float Duracao, Distancia;
 
void setup()
 { 
   Serial.begin(9600);
   pinMode(6,OUTPUT);
   pinMode(7, INPUT);
 }

void loop()
{ 
   delayMicroseconds(2);
   digitalWrite(6, HIGH);
   delayMicroseconds(10);
   digitalWrite(6, LOW);
   
   Duracao = pulseIn(7, HIGH);
   Distancia = 3.43e-2 * (Duracao/2);
   Serial.print(Distancia);
   Serial.println("  cm");
   delay(100);
 }