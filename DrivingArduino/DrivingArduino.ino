#include <NewPing.h>
#include <SharpIR.h>

//INPUT
int pin4 = 4; //High if targeted

//MOTOR
  int pinI1 = 11;//define I1 interface
  int pinI2 = 8;//define I2 interface 
  int speedpinA = 9;//enable motor A
  int pinI3 = 13;//define I3 interface 
  int pinI4 = 12;//define I4 interface 
  int speedpinB = 10;//enable motor B
  int spead = 127;//define the spead of motor
 
//IR SENSOR
  int outPut = 6;
  int inPut = 7;
 // NewPing sensor(outPut, inPut, 250);
  //int dist;

void setup() {
  //INPUT
    pinMode(pin4,INPUT);
  
  //MOTOR
    pinMode(pinI1,OUTPUT);
    pinMode(pinI2,OUTPUT);
    pinMode(speedpinA,OUTPUT);
    pinMode(pinI3,OUTPUT);
    pinMode(pinI4,OUTPUT);
    pinMode(speedpinB,OUTPUT);

    Serial.begin(9600);
    forward();
    delay(100000);
}

void loop() {
  //forward();
  
  //Get Distance
  
  if(digitalRead(pin4) == 1){
    stahp();
    delay(2000);
    forward();
  }
}

void maneuver() {
  right();
  delay(1000);
  forward();
  delay(2000);
  left();
  delay(1000);
  forward();
  delay(2000);
  left();
  delay(1000);
  forward();
  delay(2000);
  right();
  delay(1000);
}

void left() {
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
     digitalWrite(pinI3,LOW);
     digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
     digitalWrite(pinI1,LOW);
}

void right() {
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
     digitalWrite(pinI3,HIGH);
     digitalWrite(pinI2,LOW);//turn DC Motor A move clockwise
     digitalWrite(pinI1,HIGH);
}

void stahp() {
     digitalWrite(speedpinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor. 
     digitalWrite(speedpinB,LOW);
     delay(1000);
 
}

void forward() {
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
     digitalWrite(pinI3,LOW);
     digitalWrite(pinI2,LOW);//turn DC Motor A move anticlockwise
     digitalWrite(pinI1,HIGH);
}

void backward() {
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,LOW);//turn DC Motor B move clockwise
     digitalWrite(pinI3,HIGH);
     digitalWrite(pinI1,LOW);
     digitalWrite(pinI2,HIGH);//turn DC Motor A move anticlockwise    
}
