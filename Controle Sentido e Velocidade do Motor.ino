int Vel0, Vel1;
 
void setup()
 { 
   pinMode(4, INPUT_PULLUP);
   pinMode(5, INPUT_PULLUP);
   pinMode(6, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
 }

void loop(){ 
   Vel0 = map(analogRead(A0), 0, 1023, 0, 255);
   if(digitalRead(4) == LOW){
     analogWrite(6, Vel0);
     analogWrite(9, 0); }
     else{
      analogWrite(9, Vel0);
      analogWrite(6, 0); }
      
      
   Vel1 = map(analogRead(A1), 0, 1023, 0, 255);
     if(digitalRead(5) == LOW) {
     analogWrite(10, Vel1);
     analogWrite(11, 0); }
     else {
      analogWrite(11, Vel1);
      analogWrite(10, 0); }
 }