#include <Servo.h>

Servo gateServo;

// Ultrasonic pins
const int trigPin = 9;
const int echoPin = 10;

// Variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gateServo.attach(6);
  gateServo.write(0);   // Gate closed

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Open gate if car is near
  if (distance > 0 && distance <= 15) {
    gateServo.write(90);   // Open gate
    Serial.println("Gate Open");
  }
  else {
    gateServo.write(0);    // Close gate
    Serial.println("Gate Closed");
  }

  delay(1000);
}