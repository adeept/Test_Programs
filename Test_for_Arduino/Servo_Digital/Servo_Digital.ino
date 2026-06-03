/***********************************************************
File name: Servo.ino
Website: www.adeept.com
E-mail: support@adeept.com
Date: 2023/07/26
***********************************************************/
#include <Servo.h>
int servoPin1 = A1;    //Define servo interface digital interface A1
int servoPin2 = A2;    //Define servo interface digital interface A2

int number = 0;

Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin1,OUTPUT);//Set the servo interface as the output interface
  pinMode(servoPin2,OUTPUT);//Set the servo interface as the output interface

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop()
{
  servo_loop();
}


void servo_loop(){
  servo1.write(0);  // Set servo 1 to turn to 0 degrees.
  delay(100);
  servo2.write(0);  // Set servo 2 to turn to 0 degrees.
  delay(100);
  delay(1000);
  // servo1.write(90); // 90 degrees.
  // servo2.write(90);
  // delay(1000);
  servo1.write(180); // 180 degrees.
  delay(100);
  servo2.write(180);
  delay(100);
  delay(1000);
  
}
