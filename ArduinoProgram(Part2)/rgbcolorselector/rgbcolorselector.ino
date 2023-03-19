/* This is the RGB Color Selector Program.
The goal of this program is to display a specific selected color in the LED.
To do that, the right code of the color should be put in the RgbColor section. 
Such as; 
Cyan  (0,255,255)
Purple (123,0,80)
Yellow (255,128,0)
Note: There is some different codes that shows a similar color.
It is different but just looks very similar.*/

int red = 10;  // red LED connected to pin 10
int blue = 6;  // blue LED connected to pin 6
int green = 3; // green LED connected to pin 3
void setup()
{
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
}

void loop()
{
RgbColor(123,0,80); // This is the section where the code will display the color in the LED
}
void RgbColor(int redvalue, int greenvalue, int bluevalue)
{
analogWrite(red,redvalue);
analogWrite(green,greenvalue);
analogWrite(blue,bluevalue);
}
