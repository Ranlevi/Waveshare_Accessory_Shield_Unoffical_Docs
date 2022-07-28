/*
Waveshare Temperature Sensor Demo
=========================================================

The following code is based on the demo code provided
by Waveshare. 

Author:   Ran Levi
Email:    ran@ranlevi.com
Date:     July 28rd, 2022
Revision: 0.1

Description:
  Read the temperature from the device, and prints it to 
  the serial monitor.

*/

#include <Wire.h>
#include <lm75.h>

//
TempI2C_LM75 termo = TempI2C_LM75(
  0x48,                   //I2C address
  TempI2C_LM75::nine_bits //Resolution 
);

void setup()
{
    //Enable Serial Comm. to uController.
    Serial.begin(9600);
}

void loop()
{
    Serial.print("The current temperature is: ");
    Serial.println(termo.getTemp());
    delay(1000);
}
