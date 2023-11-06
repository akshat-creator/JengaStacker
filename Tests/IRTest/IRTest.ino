// Arduino IR Sensor Code
#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

int IRSensor = A1; // connect ir sensor module to Arduino pin 9

int motorStatus = 0;
void setup(){
  Serial.begin(9600); // Init Serila at 115200 Baud
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT

  while (!Serial);
  Serial.println("Stepper test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  myMotor->setSpeed(10);  // 10 rpm

}

void loop(){
  int sensorStatus = analogRead(IRSensor); // Set the GPIO as Input
  Serial.println(sensorStatus);

  if (sensorStatus<100 & motorStatus==0){
    Serial.println("Interleave coil steps");
    myMotor->step(10000, FORWARD, MICROSTEP);
    //myMotor->step(100, BACKWARD, INTERLEAVE);
  
    motorStatus ==  1;

  }

  // if (sensorStatus<100 & motorStatus==1){
  //   Serial.println("stopping");
  //   motorStatus ==  0;
  //   myMotor->step(0, FORWARD, INTERLEAVE);
  //   myMotor->step(0, BACKWARD, INTERLEAVE);
  // }
  // if (sensorStatus == 1) // Check if the pin high or not
  // {
  //   // if the pin is high turn off the onboard Led

  //   digitalWrite(LED, LOW); // LED LOW
  //   Serial.println("Motion Ended!"); // print Motion Detected! on the serial monitor window
  // }
  // else
  // {
  //   //else turn on the onboard LED
  //   digitalWrite(LED, HIGH); // LED High
  //   Serial.println("Motion Detected!"); // print Motion Ended! on the serial monitor window
  // }
}

