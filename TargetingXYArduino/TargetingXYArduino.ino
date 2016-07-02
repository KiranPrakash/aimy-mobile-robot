#include <Servo.h>

//INPUT
  int read;
  int x;
  int y;

//OUTPUT
  int pin4 = 4; //High if targeted

//TARGETING
  Servo targetingx;
  Servo targetingy;
  int degreesx[] = {66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114, 0};
  int degreesy[] = {70,80,90,100,110};

/*
//SHOOTING
  int python = 25;  //python default as nothing detected
  int Gun = 3;      //pin for gun
*/
  
void setup() {
  //OUTPUT
    pinMode(pin4,OUTPUT);
  
  //TARGETING
    targetingx.attach(8);
    targetingy.attach(9);
    Serial.begin(9600);

  /*
  //SHOOTING
  pinMode(Gun,OUTPUT);
  */
}


void loop() {
  //READ INPUT
    Serial.flush();
    read = Serial.read();  

  //If input detected
    if(read >=  0 && read != 126){
      x = read % 25;
      y = read / 25;
      //OUTPUT
        //digitalWrite(pin4,HIGH);
      
      //TARGETING
      targetingx.write(degreesx[x]+5);
      targetingy.write(degreesy[y]-10);
  
      /*
      //SHOOTING
      digitalWrite(Gun,HIGH);
      delay(1);
      digitalWrite(Gun,LOW);
      
      python = read;
      */

      //OUTPUT
      digitalWrite(pin4,LOW);
    }else if(read == 126){
      targetingx.write(95);
      targetingy.write(80);
    }
}

