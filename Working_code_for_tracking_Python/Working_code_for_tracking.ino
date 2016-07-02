#include <Servo.h>

Servo gun;
int degrees[] = {66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114};
int python;
int read;

void setup() {
  gun.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  /*pinMode(8,OUTPUT);
  pinMode(4,OUTPUT);*/
}

void loop() {
  Serial.flush();
  read = Serial.read();
  Serial.print(read);
  if(read != -1){
    python = read - 97;
    if(python < 25){
      gun.write(degrees[python]);
      //SHOOOOOOOT GUN
    }/*elseif(python == 25){
      #DONT SHOOT
    }*/
  }
}

