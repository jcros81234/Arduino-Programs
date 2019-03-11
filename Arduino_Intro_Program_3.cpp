/* This program takes distance measurement from the ultrasonic sensor and prints output in serial monitor.
   */
   
// Identify which pins are being used for what purpose
int triggerPin = 11;
int echoPin = 10;


long duration, distance;

void setup() {
  Serial.begin(9600);

// Designates input pin and output pin
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);

// preps LED pins to provide an output voltage
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {

// Loops trigger pin to send 8 cycle frequency
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(triggerPin, LOW);

// Converts time to centimeters
  duration = pulseIn(echoPin, HIGH);
  distance = MicrosecondsToCentimeters(duration);
  Serial.print("Distance : ");
  Serial.println(distance);

// Turns on 1 LED if distance is less than 20 centimeters
  if (distance < 20){
    analogWrite (3, 91.5);
  }else {
    analogWrite(3,0);
  }
// Turns on next LED if distance is less than 15 centimeters  
  if (distance < 15){
    analogWrite (5, 91.5);
  }else {
    analogWrite(5,0);
  }
// Turns on next LED if distance is less than 10 centimeters 
  if (distance < 10){
    analogWrite (6, 91.5);
  }else {
    analogWrite(6,0);
  }
  
}

// Speed of sound is .0343 cm/microsecond
// Divide by two for recieving distance from sensor and back again
long MicrosecondsToCentimeters(long duration){
  long d = (duration / 2) * .0343;
  return d;
}
