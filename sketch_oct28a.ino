
#include <Servo.h>

Servo myservo;

const int trigPin = 9;
const int echoPin = 10;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  myservo.attach(11);
}

void loop() {
    int val;
  float duration[11],k;
  float x;
  for(int i = 0; i<=10; i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin, LOW);
    duration[i] = pulseIn(echoPin, HIGH);
    delay(10);
  }
  for(int i = 0; i<= 9; i++){
    for(int j = i + 1; j<= 10; j++){
      if(duration[i] < duration[j])
      {
        x = duration[i];
        duration[i] = duration[j];
        duration[j] = x;
        }}}
  Serial.print("Aproksimatno:");
  k = 0;
  for(int i=3;i<=8; i++)
  {k += duration[i];}
  k = k/6;
  Serial.println(k);
  val = (int)k; 
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);  
  delay(100);
  
}
