
#include <AccelStepper.h>
#include <MultiStepper.h>

// Define the stepper motor and the pins that is connected to
AccelStepper stepper1(1, 2, 5); // (Typeof driver: with 2 pins, STEP, DIR)
// AccelStepper stepper2(1, 3, 6);
AccelStepper stepper2(1, 4, 7);
AccelStepper stepper3(1, 12, 13);

MultiStepper steppersControl;  // Create instance of MultiStepper

long gotoposition[3]; // An array to store the target positions for each stepper motor

void run(int x, int y) {
  gotoposition[0] = x;
  gotoposition[1] = x;
  gotoposition[2] = y;
  steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
  steppersControl.runSpeedToPosition(); // Blocks until all steppers are in position
}

void setup() {

  stepper1.setMaxSpeed(550); // Set maximum speed value for the stepper
  stepper2.setMaxSpeed(550);
  stepper3.setMaxSpeed(550);

  // Adding the 3 steppers to the steppersControl instance for multi stepper control
  steppersControl.addStepper(stepper1);
  steppersControl.addStepper(stepper2);
  steppersControl.addStepper(stepper3);

  run(0, 0);
  delay(1000);
  run(1200, -1200);
  run(1800, -1200);
  run(2100, -900);
  run(2100, -600);
  run(1500, 0);
  run(2100, 600);
  run(2100, 900);
  run(1800, 1200);
  run(1200, 1200);
  run(0, 0);
}

void loop() {
}