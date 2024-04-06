
const int StepX1 = 12;
const int DirX1 = 13;
const int StepX2 = 3;
const int DirX2 = 6;
const int StepY = 4;
const int DirY = 7;

void setup() {
  pinMode(StepX1,OUTPUT);
  pinMode(DirX1,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepX1,OUTPUT);
  pinMode(DirX2,OUTPUT);
  // digitalWrite(DirX1, LOW);
  // digitalWrite(DirY, LOW);
  // digitalWrite(DirX2, LOW);
  digitalWrite(DirX1, HIGH);
  digitalWrite(DirY, HIGH);
  digitalWrite(DirX2, HIGH);
  
  for(int x = 0; x<200; x++) { // Fast right
    digitalWrite(StepX1,HIGH);
    digitalWrite(StepY,HIGH);
    digitalWrite(StepX2,HIGH);
    delayMicroseconds(2000);
    digitalWrite(StepX1,LOW); 
    digitalWrite(StepY,LOW);
    digitalWrite(StepX2,LOW); 
    delayMicroseconds(2000);
  }
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
