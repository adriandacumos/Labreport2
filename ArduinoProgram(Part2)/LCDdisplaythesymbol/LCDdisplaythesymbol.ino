/* This is the LCD with Arduino to work as ohmmeter with display the Ω symbol program.
The goal of this program is to display the specific symbol in the LCD. */


#include <LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Define the pins for the LCD display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
int backlightPin = 9;         
int LCDlight = 70;            

byte ohm[] = 
{ 
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};

void setup() 
{
  pinMode(backlightPin, OUTPUT);     // Set the backlight pin as an output  
  analogWrite(backlightPin, LCDlight); // Set the backlight brightness
  Serial.begin(9600);        // Initialize the serial communication          
  lcd.begin(16, 2);           // Initialize the LCD display with 16 columns and 2 rows          
  lcd.createChar(0, ohm);              
  lcd.home();                          
}
void loop()  
{
  float voltageA = 0;   // Initialize the voltage across resistor A to zero
  float resistorA = 1000.0;      // Define the resistance of resistor A
  float resistorB = 0;   // Initialize the resistance of resistor B to zero         
  float voltageIN = 5;           // Define the input voltage

  float bitValue = analogRead(A0);  // Read the analog value from pin A0  
  float slope =5.0/1023.0;    // Calculate the slope of the voltage divider        
  float Va = (bitValue*slope);    // Calculate the voltage across resistor A     
  
   
  float Ia = (voltageIN-voltageA)/resistorA;   // Calculate the current flowing through resistor A
  float Rb = (voltageA-0)/Ia;          // Calculate the resistance of resistor B using Ohm's law
  
  // Print the Rb value on Serial monitor 
  Serial.print("Rb ="); 
  Serial.println(Rb);
  
  lcd.clear();                                
  lcd.setCursor(0, 0);                        
  lcd.print("UnkownResistance");    // Print the text "UnkownResistance" on the LCD display          

 if (Rb >= 1000) {     // If Rb is greater than or equal to 1000  
  Rb = Rb/1000;         // Convert Rb to kilo-ohms           
  lcd.clear();           // Clear the LCD display        
  lcd.setCursor(0, 1);          
  lcd.print(Rb);                
  lcd.print("k");               
  lcd.setCursor(7, 1);          
  lcd.write(byte(0));           
 } else {                       
  lcd.clear();           // Clear the LCD display        
  lcd.setCursor(0, 1);          
  lcd.print(Rb);                
  lcd.setCursor(7, 1);          
  lcd.write(byte(0));           
  }
}

