/* This is the PB value displayed on serial monitor and blink (without using Delay) Program.
The goal of this program is to blink a LED and in the serial monitor,
PB value should display a 1 when it's not pressed and 0 while it's pressed.*/


int BUTTON_PIN = 2; // Define the pin for the push button
int LED_PIN = 13; // Define the pin for the LED

unsigned long previousMillis = 0; // Variable to store the last time the LED was updated
const long interval = 1000; // Interval at which to blink the LED (in milliseconds)

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set the push button pin as input with internal pull-up resistor
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as output
  Serial.begin(9600); // Start serial communication with a baud rate of 9600
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // Read the state of the push button

  Serial.print("PB value = "); // Print "PB Value =" on the serial monitor
  Serial.println(buttonState); // Print the button state on the serial monitor

  unsigned long currentMillis = millis(); // Get the current time in milliseconds

  if (currentMillis - previousMillis >= interval) { // If it's time to blink the LED
    previousMillis = currentMillis; // Save the last time the LED was updated

    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle the state of the LED
  }
}
