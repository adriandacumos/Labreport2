/* This is Connect potentiometer and display bit-value and voltage value on serial monitor Program.
The goal in this program is to use a potentiometer to control a display bit value.
The bit-value must then convert its value to voltage equivalent 
 (1023 = 5V). Both bit and votlage values must be displayed on the serial
 monitor. */

int POT_PIN = A0; // Define the pin for the potentiometer

void setup() 
{
  pinMode(POT_PIN, INPUT); // Set the potentiometer pin as input
  Serial.begin(9600); // Start serial communication with a baud rate of 9600
}

void loop() 
{
  int BitValue = analogRead(POT_PIN); // Read the bit value from the potentiometer
  float voltage = BitValue * (5.0 / 1023.0); // Convert the bit value to voltage (assuming 5V reference voltage)

  Serial.print("Bit value: ");
  Serial.print(BitValue);
  Serial.print("\t Voltage: ");
  Serial.print(voltage);
  Serial.println("V");

  delay(100); // Delay for a short time to avoid flooding the serial monitor with data
}

