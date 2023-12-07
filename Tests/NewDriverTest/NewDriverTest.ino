/*Example sketch to control a stepper motor with A4988/DRV8825 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define dirPin 22
#define stepPin 23
#define stepsPerRevolution 1200

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }

  delay(1000);

  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }

  delay(1000);

}
// #include <AccelStepper.h>

// AccelStepper stepper(AccelStepper::DRIVER, 22, 23);  //StepPin D2 and DirPin D3

// void setup()
// {  
//   stepper.setMaxSpeed(4000);
//   stepper.setSpeed(4000);    //One full rotation = 800 steps = 200 steps * 4 (MS1=0, MS2=1, MS3=0)
// }

// void loop()
// {  
//   stepper.runSpeed();
// }