/* This is Connect LCD and Display bitvalue and voltage on the same screen Program.
The goal of this program is to display both bit-value and voltage value
on the LCD */

#include <LiquidCrystal.h> // Include the library code

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Assigning digital pins to LCD pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Initialize the LCD with the pins

int backlightPin = 9; // Set pin 9 to output signal
int LCDlight = 90; // This is to adjust the light in the LCD

void setup() 
{
  pinMode(backlightPin, OUTPUT); // Set the backlightPin (9) as OUTPUT
  lcd.begin(16, 2); // Start the LCD with 16 columns and 2 rows
  Serial.begin(9600); // Serial communication at 9600 bits per second
}

void loop() 
{
   analogWrite(backlightPin, LCDlight); // Control the backlight of the LCD by PWM signal
                                         
  int sensorValue = analogRead(A0); // Read the analog value from the analog pin A0
  float slope =5.0/1023.0; // Calculate the slope of the conversion between ADC bits and voltage
  float voltage = (sensorValue*slope); // Calculate the voltage from the sensorValue
  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0, 0); // Set the cursor to the top left corner of the LCD
  lcd.print("Bit = "); // Print "Bit = " on the first row of the LCD
  lcd.print(sensorValue); // Print the sensorValue on the first row of the LCD

  lcd.setCursor(0, 1); // Set the cursor to the second row of the LCD
  lcd.print("Voltage = "); // Print "Voltage = " on the second row of the LCD
  lcd.print(voltage); // Print the voltage on the second row of the LCD
  
  // Print both bit value and voltage on Serial Monitor
   Serial.print("Bit value: ");
   Serial.print(sensorValue);
   Serial.print("\t Voltage: ");
   Serial.print(voltage);
   Serial.println("V");
}