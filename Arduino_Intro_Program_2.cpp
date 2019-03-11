/* This program is designed to just read the input from analogPin 2. Analog Digital Converter is 10-bit (2^10 = 1024 descrete levels)
 *  Converts analogPin 2 input to digital read of volts and resistance from the potentiometer.
 */

// initialize analogPin 2
int potInPin = 2;

void setup() {
  Serial.begin(9600);
}


void loop() {
  // Read input from 0 (0V) - 1023 (5V)
  int val = analogRead(potInPin);

  // Convert from 0 - 1023 to voltage 0 - 5V
  float voltage = val * (5.0/1023.0);

  // Convert 0 - 1023 to resistance 0 - 10K
  float potPer = 10000.0 - (val * (10000.0 / 1023.0));

  
  Serial.print("Volts : ");
  Serial.println(voltage);
  Serial.print("POT %: ");
  Serial.println(potPer);
  Serial.println();
  delay(1000);
}
