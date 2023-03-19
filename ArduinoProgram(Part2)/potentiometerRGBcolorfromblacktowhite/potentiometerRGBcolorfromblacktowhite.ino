/* This is the Potentiometer change RGB color from black to white through different color
variations.
The goal of this program is to travel by changing color from black (off) to white. */

int POT_PIN = A0; // Define the pin for the potentiometer
int RedPin = 10; // Red LED connected to pin 10
int GreenPin = 6; // Green LED connected to pin 6
int BluePin = 3; // Blue LED connected to pin 3

void setup() 
{
  pinMode(POT_PIN, INPUT); // Set the potentiometer pin as input
  Serial.begin(9600); // Start serial communication with a baud rate of 9600
}

void loop() 
{
  int BitValue = analogRead(POT_PIN); // Read the bit value from the potentiometer
  float voltage = BitValue * (5.0 / 1023.0); // Convert the bit value to voltage (assuming 5V reference voltage)

  int RP = 0;
  int GP = 0;  
  int BP = 0;  
  if (voltage == 0.0 ) {                       
      RP = 0;
      GP = 0;
      BP = 0;
      // LED OFF
  } else if (voltage > 0.0 && voltage <1.5 ) { 
      RP = 255;
      GP = 0;
      BP = 0;
      // LED RED
  } else if (voltage > 1.5 && voltage < 3.0) {
      RP = 0;
      GP = 255;
      BP = 0;
      // LED GREEN
  } else if (voltage > 3.0 && voltage < 4.5) { 
      RP = 0;
      GP = 0;
      BP = 255;
      // LED BLUE
  } else if (voltage > 4.5 && voltage <= 5.0) { 
      RP = 255;
      GP = 255;
      BP = 255;
      // LED WHITE
  }
  analogWrite(RedPin, RP);    
  analogWrite(GreenPin, GP);   
  analogWrite(BluePin, BP);   

  // Print both bit value and voltage on Serial Monitor
  Serial.print("Bit value: ");
  Serial.print(BitValue);
  Serial.print("\t Voltage: ");
  Serial.print(voltage);
  Serial.println("V");

}
