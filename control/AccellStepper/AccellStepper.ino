
#include <AccelStepper.h>
#include <MultiStepper.h>

// Define the stepper motor and the pins that is connected to
AccelStepper stepper1(1, 2, 5); // (Typeof driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 3, 6);
AccelStepper stepper3(1, 4, 7);
// AccelStepper stepper4(1, 12, 13);

MultiStepper steppersControl;  // Create instance of MultiStepper

long gotoposition[3]; // An array to store the target positions for each stepper motor

void setup() {

  stepper1.setMaxSpeed(550); // Set maximum speed value for the stepper
  stepper2.setMaxSpeed(550);
  stepper3.setMaxSpeed(550);

  // Adding the 3 steppers to the steppersControl instance for multi stepper control
  steppersControl.addStepper(stepper1);
  steppersControl.addStepper(stepper2);
  steppersControl.addStepper(stepper3);
}

// void mmToSteps(int amount) {
//   // 1 teeth is 2 mm
//   // 1 round is 20 teeth
//   // 200 steps is one round
//   // each step is 40/200 mm
//   return amount * 200/40
// }

// void moveX(int mm) {
//   int steps = mmToSteps(mm)
//   gotoposition[0] = steps;
//   gotoposition[1] = steps;
// }

// void moveY() {
//   int steps = mmToSteps(mm)
//   gotoposition[2] = steps;
// }

void run() {
  steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
  steppersControl.runSpeedToPosition(); // Blocks until all steppers are in position
}

void loop() {
  // Store the target positions in the "gotopostion" array
  gotoposition[0] = 1000;
  gotoposition[1] = 1000;
  gotoposition[2] = 1000;

  run();

  delay(1000);

  gotoposition[0] = 0;
  gotoposition[1] = 0;
  gotoposition[2] = 0;

  steppersControl.moveTo(gotoposition);
  steppersControl.runSpeedToPosition();

  delay(1000);
}