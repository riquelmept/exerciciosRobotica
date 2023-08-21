int LeituraA0, SinalPWM;

void setup(){
   pinMode(3, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(9, OUTPUT);
   Serial.begin(9600);
 }
 
 
 void loop(){
 LeituraA0 = analogRead(A0);
 SinalPWM = map(LeituraA0, 0, 1023, 0, 255);
 Serial.print(LeituraA0);
 Serial.print("   -   ");
 Serial.println(SinalPWM);
 analogWrite(3, SinalPWM);
 analogWrite(5, SinalPWM);
 analogWrite(6, SinalPWM);
 analogWrite(9, SinalPWM);
 delay(1000);
 }