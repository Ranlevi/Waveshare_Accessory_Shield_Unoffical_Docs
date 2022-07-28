/*
Waveshare Accessory Shield Adjustable Potentiomenter Demo
=========================================================

The following code is based on the demo code provided
by Waveshare. 

Author:   Ran Levi
Email:    ran@ranlevi.com
Date:     July 25rd, 2022
Revision: 0.1

Description:
  The voltage on the adjustable resistor is read every 0.5 seconds,
  and the result is than sent via serial communication. 

*/

const int analog_pin = 0; //Analog pin A0
int       adcvalue;

void setup(void)
{
  //Init serial comm. with the connected PC. 
  Serial.begin(9600);
}


void loop(void)
{
  adcvalue = analogRead(analog_pin);
  
  Serial.print("The current ADC value is: ");
  Serial.println(adcvalue);
  
  delay(500);
}