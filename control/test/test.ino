
// defs
// const int StepX1 = 2;
// const int DirX1 = 5;
// const int StepX2 = 3;
// const int DirX2 = 6;
// const int StepY = 4;
// const int DirY = 7;
// const int StepZ = 12;
// const int DirZ = 13;

const int StepX1 = 2;
const int DirX1 = 5;
const int StepX2 = 4;
const int DirX2 = 7;
const int StepY = 12;
const int DirY = 13;

const int MinDelayTime = 1300;
long CurrentPositions[3]; // [x, y, z]
const int MaxX = 75;
const int MaxY = 75;
const int MaxZ = 0;

// Utils:
int mmToSteps(int amount) {
  // 1 teeth is 2 mm
  // 1 round is 20 teeth
  // 200 steps is one round
  // each step is 40/200 mm
  return round(amount * 200/40);
}

int getDirection(int steps) {
  if (steps > 0) { 
    return LOW; 
  }
  else { 
    return HIGH; 
  }
}

void moveX(int amount) {
  int steps = mmToSteps(amount);
  digitalWrite(DirX1,getDirection(steps));
  digitalWrite(DirX2,getDirection(steps));
  for(int x = 0; x<abs(steps); x++) {
    digitalWrite(StepX1,HIGH);
    digitalWrite(StepX2,HIGH);
    delayMicroseconds(MinDelayTime);
    digitalWrite(StepX1,LOW); 
    digitalWrite(StepX2,LOW);
    delayMicroseconds(MinDelayTime);
 }
}

void moveY(int amount) {
  int steps = mmToSteps(amount);
  digitalWrite(DirY,getDirection(steps));
  for(int x = 0; x<abs(steps); x++) {
    digitalWrite(StepY,HIGH);
    delayMicroseconds(MinDelayTime); 
    digitalWrite(StepY,LOW);
    delayMicroseconds(MinDelayTime);
 }
}

void moveZ(int amount) {
  return 0;
}

void move(long positions[3]) {
  moveX(positions[0] - CurrentPositions[0]);
  moveY(positions[1] - CurrentPositions[1]);
  moveZ(positions[2] - CurrentPositions[2]);
  CurrentPositions[0] = positions[0];
  CurrentPositions[1] = positions[1];
  CurrentPositions[2] = positions[2];
}

void setup_init() {
  pinMode(StepX1,OUTPUT);
  pinMode(DirX1,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepX2,OUTPUT);
  pinMode(DirX2,OUTPUT);
}

void test() {
  for(int x = 0; x<100; x++) { // Fast right
    digitalWrite(StepX1,HIGH);
    digitalWrite(StepY,HIGH);
    digitalWrite(StepX2,HIGH);
    delayMicroseconds(2000);
    digitalWrite(StepX1,LOW); 
    digitalWrite(StepY,LOW);
    digitalWrite(StepX2,LOW); 
    delayMicroseconds(2000);
  }
}

void setup() {
  setup_init();
  test();
  long coordinates[] = {200, 200, 0};
  move(coordinates);
  delay(2000);
  coordinates[0] = 0;
  coordinates[1] = 0;
  move(coordinates);

}

void loop() {
  // put your main code here, to run repeatedly:

}
