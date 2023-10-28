#include <Servo.h>
const int trigPin = 9;
const int echoPin = 10;
Servo myservo;  
float duration;
float ugao = 0;
int pos = 0;    
int mode = 1;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  myservo.attach(11);  
}

void loop() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    ugao += mode * duration/200;
    if(ugao >= 180) mode = -1;
    if(ugao <= 1) mode = 1;
    myservo.write(ugao);              
    delay(15);                      
          
  
}
