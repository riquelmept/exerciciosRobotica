int LeituraAnt, LeituraAtual, Volta, Angulo, Passo;

void setup(){
   pinMode(2, INPUT_PULLUP);
   Serial.begin(9600);
   Angulo = 0;
   Passo = 18;
   LeituraAnt = digitalRead(2);
}

void loop(){
   LeituraAtual  = digitalRead(2);
   if ((LeituraAnt == LOW) && (LeituraAtual == HIGH)){
   Angulo = Angulo + Passo;
      if(Angulo > 360){
	 Angulo = Angulo - 360;	
	 Volta = Volta + 1;
	 }
   
   Serial.print(Angulo);
   Serial.print("  -  ");
   Serial.println(Volta);
}
   LeituraAnt = LeituraAtual;
}