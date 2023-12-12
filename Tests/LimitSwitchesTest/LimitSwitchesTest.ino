#include <ezButton.h>

ezButton button0(9);
ezButton button1(10);  
ezButton button2(11);

ezButton buttonX1(26);
ezButton buttonX2(27);  
ezButton buttonY1(28);
ezButton buttonY2(29);
ezButton buttonZ1(30);  
ezButton buttonZ2(31);
ezButton buttonZ3(32);  
ezButton buttonZ4(33);

int X1,X2,Y1,Y2,Z1,Z2,Z3,Z4 = 0;
// const int buttonPin0 = A2;  // the number of the pushbutton pin
// const int buttonPin1 = A1;  // the number of the pushbutton pin
// const int buttonPin2 = A2;  // the number of the pushbutton pin

// Variables will change:
// int ledState = HIGH;        // the current state of the output pin
// int buttonState;            // the current reading from the input pin
// int lastButtonState = LOW;  // the previous reading from the input pin
/* 
High Debounce to make sure the elevator pushers are in sync and to ignore small a small time differnece between the two 
*/
const int LimitSwitchDebounceTime = 50;  // 

const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;
const int StepA = 12;
const int DirA = 13;
const int StepE = 23;
const int DirE = 22;
const int StepE2 = 25;
const int DirE2 = 24;

int StepCountX = 800;
int StepCountY = 570;
int StepCountZ = 570;
int StepCountA = 800;
int StepCountE = 800;
int StepCountE2 = 800;

int DelayMicroX = 600;
int DelayMicroY = 650;
int DelayMicroZ = 600;
int DelayMicroA = 600;
int DelayMicroE = 600;
int DelayMicroE2 = 600;

void setup() {
  Serial.begin(9600);
  button0.setDebounceTime(50); // set debounce time to 50 milliseconds
  button1.setDebounceTime(50); 
  button2.setDebounceTime(50); 

  buttonX1.setDebounceTime(LimitSwitchDebounceTime); 
  buttonX2.setDebounceTime(LimitSwitchDebounceTime); 
  buttonY1.setDebounceTime(LimitSwitchDebounceTime); 
  buttonY2.setDebounceTime(LimitSwitchDebounceTime); 
  buttonZ1.setDebounceTime(LimitSwitchDebounceTime); 
  buttonZ2.setDebounceTime(LimitSwitchDebounceTime); 
  buttonZ3.setDebounceTime(LimitSwitchDebounceTime); 
  buttonZ4.setDebounceTime(LimitSwitchDebounceTime); 

  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode(DirZ,OUTPUT);
  pinMode(StepA,OUTPUT);
  pinMode(DirA,OUTPUT);
  pinMode(StepE,OUTPUT);
  pinMode(DirE,OUTPUT);
  pinMode(StepE2,OUTPUT);
  pinMode(DirE2,OUTPUT);

  pinMode(26,INPUT_PULLUP);

}

void cnc_sheildX() {
  Serial.println("Shield X");
  if(buttonX1.isPressed()==1) {
    Serial.println(buttonX1.isPressed());

    digitalWrite(DirX, LOW); // set direction, HIGH for clockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(DelayMicroX);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(DelayMicroX);

    digitalWrite(DirA, HIGH); // set direction, HIGH for clockwise
    digitalWrite(StepA,HIGH);
    delayMicroseconds(DelayMicroA);
    digitalWrite(StepA,LOW); 
    delayMicroseconds(DelayMicroA);
    
  }
  delay(500);
  while(buttonX2.getState()==0) { 

      if(buttonX2.isPressed()){
      Serial.println("X22222222222222");
      break;
    }
    digitalWrite(DirX, HIGH); // set direction, LOW for anticlockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(DelayMicroX);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(DelayMicroX);

    digitalWrite(DirA, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepA,HIGH);
    delayMicroseconds(DelayMicroA);
    digitalWrite(StepA,LOW); 
    delayMicroseconds(DelayMicroA);
  }
}

void cnc_sheildY() {

  while(buttonY1.getState()==1); { // loop for 200 steps
    digitalWrite(DirY, HIGH);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(DelayMicroY);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(DelayMicroY);
  }

  while(buttonY2.getState()==1); { // loop for 200 steps
    digitalWrite(DirY, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepY,HIGH);
    delayMicroseconds(DelayMicroY);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(DelayMicroY);
  }
}

void cnc_sheildZ(){

  while(buttonZ1.getState()==1) { // loop for 200 steps
    digitalWrite(DirZ, HIGH);
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(DelayMicroZ);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(DelayMicroZ);
  }

  while(buttonZ2.getState()==1) { // loop for 200 steps
    digitalWrite(DirZ, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(DelayMicroZ);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(DelayMicroZ);
  }
  
}

void cnc_sheildE() {

  for(int x = 0; x<StepCountE; x++) { // loop for 200 steps
    digitalWrite(DirE, HIGH);
    digitalWrite(StepE,HIGH);
    digitalWrite(DirE2, HIGH);
    digitalWrite(StepE2,HIGH);
    delayMicroseconds(DelayMicroE);
    digitalWrite(StepE,LOW); 
    digitalWrite(StepE2,LOW); 
    delayMicroseconds(DelayMicroE);
  }

  for(int x = 0; x<StepCountE; x++) { // loop for 200 steps
    digitalWrite(DirE, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepE,HIGH);
    digitalWrite(DirE2, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepE2,HIGH);
    delayMicroseconds(DelayMicroE);
    digitalWrite(StepE,LOW); 
    digitalWrite(StepE2,LOW); 
    delayMicroseconds(DelayMicroE);
  }
}

void loop() {
  button0.loop(); // MUST call the loop() function first
  button1.loop(); // MUST call the loop() function first
  button2.loop(); // MUST call the loop() function first
  buttonX1.loop();
  buttonX2.loop();


  digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
  digitalWrite(DirY, HIGH);
  digitalWrite(DirZ, HIGH);
  digitalWrite(DirE, HIGH);
  digitalWrite(DirE2, HIGH);

  // If the switch changed, due to noise or pressing:
  //Serial.println(buttonX1.isPressed());
  Serial.println(buttonX1.isPressed());
  if(button0.isPressed()){
    Serial.println("The button 1 is pressed");
    cnc_sheildX();
  }

  // if(button1.isPressed()){
  //   Serial.println("The button 2 is pressed");
  //   cnc_sheildY();
  //   cnc_sheildY();
  //   cnc_sheildY();

  // }

  // if(button2.isPressed()){
  //   Serial.println("The button 3 is pressed");
  //   cnc_sheildZ();
  //   cnc_sheildZ();
  //   cnc_sheildZ();

  // }

}



*/