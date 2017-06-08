#include <Servo.h>

char tiltChanel=0;
char panChanel = 1;

#define pinTilt 2
#define pinPan 3

Servo servoTilt, servoPan;

char serialChar = 0;

void setup() {
  
  servoTilt.attach(pinTilt);
  servoPan.attach(pinPan);

  servoTilt.write(90);
  servoPan.write(90);

  Serial.begin(57600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() <= 0);
  serialChar = Serial.read();
  
  if(serialChar == tiltChanel){
    while(Serial.available() <=0);
    servoTilt.write(Serial.read());  
  }
  
  else if(serialChar == panChanel){
    while(Serial.available() <= 0);
    servoPan.write(Serial.read());
  }
  
}
