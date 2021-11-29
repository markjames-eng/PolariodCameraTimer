#include <Servo.h>
Servo myservo; // create servo object to control a servo int pos = 0; // variable to store the servo position
int servoPin = 3; // define the pin of servo signal line
int button;
int toggle;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin); // attaches the servo on servoPin to the servo object
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  Serial.print("Starting");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  toggle = digitalRead(6);
  Serial.print(toggle);
  if(toggle == 1){
    button = digitalRead(7);
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    if(button == 0){
      nSecondDelay(3);
      myservo.write(0);
      delay(1000);
      digitalWrite(8, LOW);
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
      
    }
    else{
      myservo.write(180);
    }
  }
  else{
    button = digitalRead(7);
    if(button == 0){
      nSecondDelay(10);
      myservo.write(0);
      delay(1000);
      digitalWrite(8, LOW);
    }
    else{
      myservo.write(180);
    }
  }
}



void nSecondDelay(int seconds){

  for(int i = 0; i < seconds; i++){
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(8, HIGH);
  }
  
}
