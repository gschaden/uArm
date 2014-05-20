/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int i;

#define P_I_SWITCH 2
#define P_O_BUZZER 3
#define P_I_BUTTON_1  4
#define P_O_VALVE  5
#define P_O_PUMP   6

#define P_I_BUTTON_2  7

#define P_O_MOTOR_8  8
#define P_O_MOTOR_9  9
#define P_O_MOTOR_10  10
#define P_O_MOTOR_11 11
#define P_O_MOTOR_12  12
#define P_O_MOTOR_13  13

#include <Servo.h> 

Servo servo_9;  // create servo object to control a servo 
Servo servo_10;  // create servo object to control a servo 
Servo servo_11;  // create servo object to control a servo 
Servo servo_12;  // create servo object to control a servo 
Servo servo_13;  // create servo object to control a servo 

// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);

  // initialize the digital pin as an output.
  for (i=0;i<13;i++){
    pinMode(i, OUTPUT); 
  }    


  servo_9.attach(9); 
  servo_9.write(90);
  servo_10.attach(10);   
  servo_10.write(90);
  servo_11.attach(P_O_MOTOR_11);   
  servo_11.write(90);
  servo_12.attach(P_O_MOTOR_12);  
  servo_12.write(90);
  servo_13.attach(P_O_MOTOR_13);  
  servo_13.write(90);

}

int cmd = 0;
int s11 = 0;
int s12 = 0;
int s13 = 0;

// the loop routine runs over and over again forever:
void loop() {

  // send data only when you receive data:
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    int cmd = Serial.parseInt(); 
    int s11 = Serial.parseInt(); 
    int s12 = Serial.parseInt(); 
    int s13 = Serial.parseInt(); 

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      if (cmd == 1) { // goto position
        s11 = constrain(s11, 0, 180);
        s12 = constrain(s12, 0, 180);
        s13 = constrain(s13, 0, 180);
  
        servo_11.write(s11);
        servo_12.write(s12);
        servo_13.write(s13);
  
        Serial.print(s11, HEX);
        Serial.print(s12, HEX);
        Serial.println(s13, HEX);
      }
    }
  }
}


