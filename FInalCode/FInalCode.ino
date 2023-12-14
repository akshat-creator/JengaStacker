#include <ezButton.h>

ezButton button0(9);
ezButton button1(10);  
ezButton button2(11);

// const int buttonPin0 = A2;  // the number of the pushbutton pin
// const int buttonPin1 = A1;  // the number of the pushbutton pin
// const int buttonPin2 = A2;  // the number of the pushbutton pin

// Variables will change:
int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

int count1 = 0;
int count2 = 0;

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
int StepCountY = 710;
int StepCountZ = 710;
int StepCountA = 800;
int StepCountE = 350;

int DelayMicroX = 600;
int DelayMicroY = 650;
int DelayMicroZ = 650;
int DelayMicroA = 600;
int DelayMicroE = 400;


void setup() {
  Serial.begin(9600);
  button0.setDebounceTime(50); // set debounce time to 50 milliseconds
  button1.setDebounceTime(50); // set debounce time to 50 milliseconds
  button2.setDebounceTime(50); // set debounce time to 50 milliseconds

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

}

void cnc_sheildX() {
  
  for(int x = 0; x<StepCountX; x++) { // loop for 200 steps
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
  for(int x = 0; x<StepCountX; x++) { // loop for 200 steps
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
  delay(500);

  // for(int x = 0; x<600; x++) { // loop for 200 steps
 
  //   digitalWrite(DirA, HIGH); // set direction, HIGH for clockwise
  //   digitalWrite(StepA,HIGH);
  //   delayMicroseconds(DelayMicroA);
  //   digitalWrite(StepA,LOW); 
  //   delayMicroseconds(DelayMicroA);
 
  // }
  // delay(500);

  // for(int x = 0; x<StepCountX+600; x++) { // loop for 200 steps
 
  //   digitalWrite(DirA, LOW); // set direction, HIGH for clockwise
  //   digitalWrite(StepA,HIGH);
  //   delayMicroseconds(DelayMicroA);
  //   digitalWrite(StepA,LOW); 
  //   delayMicroseconds(DelayMicroA);
 
  // }
  // delay(500);

  // for(int x = 0; x<600; x++) { // loop for 200 steps
 
  //   digitalWrite(DirX, LOW); // set direction, HIGH for clockwise
  //   digitalWrite(StepX,HIGH);
  //   delayMicroseconds(DelayMicroX);
  //   digitalWrite(StepX,LOW); 
  //   delayMicroseconds(DelayMicroX);
 
  // }
  // delay(500);

  // for(int x = 0; x<StepCountX+600; x++) { // loop for 200 steps
 
  //   digitalWrite(DirX, HIGH); // set direction, LOW for anticlockwise
  //   digitalWrite(StepX,HIGH);
  //   delayMicroseconds(DelayMicroX);
  //   digitalWrite(StepX,LOW); 
  //   delayMicroseconds(DelayMicroX);
 
  // }
  // delay(500);
  // for(int x = 0; x<StepCountX; x++) { // loop for 200 steps
  //   digitalWrite(DirX, LOW); // set direction, HIGH for clockwise
  //   digitalWrite(StepX,HIGH);
  //   delayMicroseconds(DelayMicroX);
  //   digitalWrite(StepX,LOW); 
  //   delayMicroseconds(DelayMicroX);
 
  //   digitalWrite(DirA, HIGH); // set direction, HIGH for clockwise
  //   digitalWrite(StepA,HIGH);
  //   delayMicroseconds(DelayMicroA);
  //   digitalWrite(StepA,LOW); 
  //   delayMicroseconds(DelayMicroA);
 
  // }
  // delay(500);
  // for(int x = 0; x<StepCountX; x++) { // loop for 200 steps
  //   digitalWrite(DirX, HIGH); // set direction, LOW for anticlockwise
  //   digitalWrite(StepX,HIGH);
  //   delayMicroseconds(DelayMicroX);
  //   digitalWrite(StepX,LOW); 
  //   delayMicroseconds(DelayMicroX);

  //   digitalWrite(DirA, LOW); // set direction, LOW for anticlockwise
  //   digitalWrite(StepA,HIGH);
  //   delayMicroseconds(DelayMicroA);
  //   digitalWrite(StepA,LOW); 
  //   delayMicroseconds(DelayMicroA);
  // }
}

void cnc_sheildY() {

  for(int x = 0; x<StepCountY; x++) { // loop for 200 steps
    digitalWrite(DirY, HIGH);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(DelayMicroY);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(DelayMicroY);
  }

  for(int x = 0; x<StepCountY; x++) { // loop for 200 steps
    digitalWrite(DirY, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepY,HIGH);
    delayMicroseconds(DelayMicroY);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(DelayMicroY);
  }
}

void cnc_sheildZ(){

  for(int x = 0; x<StepCountZ; x++) { // loop for 200 steps
    digitalWrite(DirZ, LOW);
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(DelayMicroZ);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(DelayMicroZ);
  }

  for(int x = 0; x<StepCountZ; x++) { // loop for 200 steps
    digitalWrite(DirZ, HIGH); // set direction, LOW for anticlockwise
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(DelayMicroZ);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(DelayMicroZ);
  }
  
}

void cnc_sheildE() {

  // for(int x = 0; x<StepCountE; x++) { // loop for 200 steps
  //   digitalWrite(DirE, HIGH);
  //   digitalWrite(StepE,HIGH);
  //   digitalWrite(DirE2, HIGH);
  //   digitalWrite(StepE2,HIGH);
  //   delayMicroseconds(DelayMicroE);
  //   digitalWrite(StepE,LOW); 
  //   digitalWrite(StepE2,LOW); 
  //   delayMicroseconds(DelayMicroE);
  // }
  delay(500);
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
  delay(500);
}

void loop() {
  button0.loop(); // MUST call the loop() function first
  button1.loop(); // MUST call the loop() function first
  button2.loop(); // MUST call the loop() function first

  digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
  digitalWrite(DirY, HIGH);
  digitalWrite(DirZ, HIGH);
  digitalWrite(DirE, HIGH);
  digitalWrite(DirE2, HIGH);

  // If the switch changed, due to noise or pressing:

  if(button0.isPressed()){
    Serial.println("The button 0 is pressed");
    //cnc_sheildX();
    cnc_sheildE();
  //   for(int x = 0; x<StepCountE; x++) { // loop for 200 steps
  //   digitalWrite(DirE, HIGH); // set direction, LOW for anticlockwise
  //   digitalWrite(StepE,HIGH);
  //   digitalWrite(DirE2, HIGH); // set direction, LOW for anticlockwise
  //   digitalWrite(StepE2,HIGH);
  //   delayMicroseconds(DelayMicroE);
  //   digitalWrite(StepE,LOW); 
  //   digitalWrite(StepE2,LOW); 
  //   delayMicroseconds(DelayMicroE);
  // }
  }

  if(button1.isPressed()){
    Serial.println("The button 1 is pressed");
    cnc_sheildY();
    count1 += 1;
  }

  if(button2.isPressed()){
    Serial.println("The button 2 is pressed");
    cnc_sheildZ();
    count2 += 1;
  }
  // Y stacker
  if (count1 == 3){
  cnc_sheildX();
  count1 = 0;
  delay(500);
    delay(500);
    for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps
    digitalWrite(DirX, LOW); // set direction, HIGH for clockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(DelayMicroX);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(DelayMicroX);

  }
  delay(500);
  for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps

    digitalWrite(DirX, HIGH); // set direction, LOW for anticlockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(DelayMicroX);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(DelayMicroX);

  
  }
  delay(500);
  for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps
    digitalWrite(DirA, HIGH); // set direction, HIGH for clockwise
    digitalWrite(StepA,HIGH);
    delayMicroseconds(DelayMicroA);
    digitalWrite(StepA,LOW); 
    delayMicroseconds(DelayMicroA);
 
  }
  delay(500);
  for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps

    digitalWrite(DirA, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepA,HIGH);
    delayMicroseconds(DelayMicroA);
    digitalWrite(StepA,LOW); 
    delayMicroseconds(DelayMicroA);
  }
  delay(500);
  cnc_sheildE();
  delay(500);
  for(int x = 0; x<(StepCountY/1.6); x++) { // y moves forward
    digitalWrite(DirY, HIGH);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(DelayMicroY);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(DelayMicroY);
  }
  delay(500);
  for(int x = 0; x<(StepCountZ/1.6); x++) { // Z moves back
    digitalWrite(DirZ, HIGH); // set direction, LOW for anticlockwise
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(DelayMicroZ);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(DelayMicroZ);
  }
    
  }

  // Z stacker 
  if (count2 == 3){
    cnc_sheildX();
    count2 = 0;
    delay(500);
    for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps
    digitalWrite(DirX, LOW); // set direction, HIGH for clockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(DelayMicroX);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(DelayMicroX);

  }
  delay(500);
  for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps

    digitalWrite(DirX, HIGH); // set direction, LOW for anticlockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(DelayMicroX);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(DelayMicroX);

  
  }
  delay(500);
  for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps
    digitalWrite(DirA, HIGH); // set direction, HIGH for clockwise
    digitalWrite(StepA,HIGH);
    delayMicroseconds(DelayMicroA);
    digitalWrite(StepA,LOW); 
    delayMicroseconds(DelayMicroA);
 
  }
  delay(500);
  for(int x = 0; x<StepCountX+275; x++) { // loop for 200 steps

    digitalWrite(DirA, LOW); // set direction, LOW for anticlockwise
    digitalWrite(StepA,HIGH);
    delayMicroseconds(DelayMicroA);
    digitalWrite(StepA,LOW); 
    delayMicroseconds(DelayMicroA);
  }
  cnc_sheildE();
  delay(500);
  for(int x = 0; x<(StepCountZ/1.6); x++) {  // Z moves forward
    digitalWrite(DirZ, LOW);
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(DelayMicroZ);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(DelayMicroZ);
  }

  for(int x = 0; x<(StepCountY/1.6); x++) { // Y moves backward
    digitalWrite(DirY, LOW);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(DelayMicroY);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(DelayMicroY);
  }

  }
}