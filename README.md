/* My first program. Outputs 5 volts to Pin 3 when '1' is input into Serial Monitor. Outputs 0 Volts to Pin 3 when '0' is input into Serial Monitor.
 *  
 *  The Circuit starts with a cable from Arduino Pin 3 out to Breadboard positive terminal. Jack wire from positive terminal to
 *  330 ohm resistor. Jack wire from Resistor to LED. Jack Wire from LED to Switch. Jack Wire from Switch to ground.
 *  
 */

//initialize output pin to pin 3
const int outPin = 3;

void setup() {
  
  //sets output voltage to pin 3
  pinMode(outPin, OUTPUT);

  //sets transfer of characters from computer to Arduino at 9600/sec
  Serial.begin(9600);

  //prints message into serial monitor
  Serial.println("Enter 1 or 0");
}

void loop() {

  //checks if available number of bites read from serial port is greater than 0
  if (Serial.available()> 0){

  //initalize character to get input from serial monitor
    char ch = Serial.read();
  //if serial monitor input is 1, output 5V
    if (ch == '1'){
      digitalWrite(outPin, HIGH);
    }
  //if serial monitor input is 0, output 0V  
    else if (ch == '0'){
      digitalWrite(outPin, LOW);
    }
  }
}
