// This is LCD show bitvalue when PB is not pressed and Voltage when it is pressed Program.

#include <LiquidCrystal.h> // Include the library code

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  // Assigning digital pins to LCD pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Initialize the LCD with the pins

int backlightPin = 9;  
int LCDlight = 90;         
const int pushbuttonPin = 13;    
int pushbuttonState;             

void setup() {
  pinMode(pushbuttonPin, INPUT_PULLUP);      
  pinMode(backlightPin, OUTPUT);         
  lcd.begin(16, 2);                      
  Serial.begin(9600);                    // Serial communication at 9600 bits per second
}

void loop() {
  pushbuttonState = digitalRead(pushbuttonPin);   // Read the pushbutton state (HIGH or LOW)    
 
   analogWrite(backlightPin, LCDlight);  // Control the brightness of the LCD backlight   
                                              
  int BitValue = analogRead(A0);              
  float slope =5.0/1023.0;                    
  float voltage = (BitValue*slope);  // Calculate the voltage from the BitValue         

  if (pushbuttonState == HIGH) {   // If the pushbutton is pressed             
      lcd.clear();             // Clear the LCD screen             
      lcd.setCursor(0, 0);     // Set the cursor to the top left corner of the LCD            
      lcd.print("Bit = ");     // Print "Bit = " on the first row of the LCD             
      lcd.print(BitValue);     // Print the BitValue on the first row of the LCD
}   
else {                        // If the button is not pressed              
      lcd.clear();            // Clear the LCD screen              
      lcd.setCursor(0, 0);    // Set the cursor to the top left corner of the LCD              
      lcd.print("Voltage = "); // Print "Voltage = " on the first row of the LCD            
      lcd.print(voltage);    // Print the voltage on the first row of the LCD
}

  // Print both bit value and voltage on Serial Monitor
  Serial.print("Bit value: ");
  Serial.print(BitValue);
  Serial.print("\t Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
}

