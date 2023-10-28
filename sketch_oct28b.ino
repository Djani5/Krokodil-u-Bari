#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    

void setup() {
  myservo.attach(11);  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 

    myservo.write(pos);              
    delay(15);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);             
    delay(15);                       
  }
}
