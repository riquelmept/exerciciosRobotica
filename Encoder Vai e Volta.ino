int Sentido, Velocidade;
float Angulo, Volta;

void ContaAngulo(){
   if(digitalRead(4) == 0){
   Angulo = Angulo + 1;
   }
   
   else{
   Angulo = Angulo - 1;
   }
   
   Serial.println(Angulo);
}

void ContaVolta (){
   Volta = Volta + 1;
}

void setup(){
   pinMode(2,INPUT_PULLUP);
   pinMode(3,INPUT_PULLUP);  
   pinMode(4,INPUT_PULLUP);
   attachInterrupt(0, ContaAngulo, RISING);
   attachInterrupt(1, ContaVolta, RISING);
   Serial.begin (9600);
}

void loop(){
   Sentido = digitalRead(13);
   Velocidade = analogRead(A0);
   if(Sentido ==  LOW){
      analogWrite(5, map(Velocidade,0, 1023, 0, 255));
      analogWrite(6, 0);
      }
    if(Sentido == HIGH){
      analogWrite(5, 0);
      analogWrite(6, map(Velocidade,0, 1023, 0, 255));
      }
 }    