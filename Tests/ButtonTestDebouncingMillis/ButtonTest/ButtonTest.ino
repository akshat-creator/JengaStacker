
const int buttonPin0 = A2;  // the number of the pushbutton pin
const int buttonPin1 = A1;  // the number of the pushbutton pin
const int buttonPin2 = A2;  // the number of the pushbutton pin

// Variables will change:
int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;

void setup() {
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin0, INPUT);

  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode(DirZ,OUTPUT);

}

void cnc_sheild() {


  for(int x = 0; x<500; x++) { // loop for 200 steps
    digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(500);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(500);
  }
  for(int x = 0; x<500; x++) { // loop for 200 steps
    digitalWrite(DirX, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
    digitalWrite(StepX,HIGH);
    delayMicroseconds(500);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(500);
  }
  delay(1000); // delay for 1 second

  for(int x = 0; x<500; x++) { // loop for 200 steps
    digitalWrite(StepY,HIGH);
    delayMicroseconds(500);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(500);
  }
  delay(1000); // delay for 1 second

  for(int x = 0; x<500; x++) { // loop for 200 steps
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(500);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(500);
  }
  delay(1000); // delay for 1 second
   
}

void loop() {
  // read the state of the switch into a local variable:
  int reading2 = digitalRead(buttonPin2);
  int reading1 = digitalRead(buttonPin1);
  int reading0 = digitalRead(buttonPin0);

  digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
  digitalWrite(DirY, HIGH);
  digitalWrite(DirZ, HIGH);
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:
  cnc_sheild();

  // If the switch changed, due to noise or pressing:
  // if (reading2 != lastButtonState) {
  //   // reset the debouncing timer
  //   lastDebounceTime = millis();
  // }

  // if (reading1 != lastButtonState) {
  //   // reset the debouncing timer
  //   lastDebounceTime = millis();
  // }

  // if (reading0 != lastButtonState) {
  //   // reset the debouncing timer
  //   lastDebounceTime = millis();
  // }

  // if ((millis() - lastDebounceTime) > debounceDelay) {
  //   // whatever the reading is at, it's been there for longer than the debounce
  //   // delay, so take it as the actual current state:

  //   // if the button state has changed:
  //   if (reading2 != buttonState) {
  //     buttonState = reading2;

  //     // only toggle the LED if the new button state is HIGH
  //     if (buttonState == HIGH) {
  //       cnc_sheild();
  //       Serial.println("wassup2");
  //     }
  //   }

  //     if (reading1 != buttonState) {
  //     buttonState = reading1;

  //     // only toggle the LED if the new button state is HIGH
  //     if (buttonState == HIGH) {
  //       cnc_sheild();
  //       Serial.println("wassup1");
  //     }
  //   }
  
  //     if (reading0 != buttonState) {
  //     buttonState = reading0;

  //     // only toggle the LED if the new button state is HIGH
  //     if (buttonState == HIGH) {
  //       cnc_sheild();
  //       Serial.println("wassup0");
  //     }
  //   }
  }

  // set the LED:

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  //lastButtonState = reading2;



