/*
Waveshare Accessory Shield RGB LED Demo
=========================================================

The following code is based on the demo code provided
by Waveshare. 

Author:   Ran Levi
Email:    ran@ranlevi.com
Date:     July 26rd, 2022
Revision: 0.1

Description:
  Cycles the RGB LED.

*/

//Library for control of the P9813 LED driver.
#include <ChainableLED.h>

//I/O define
const int rgb_pwr     = 12; //rgb power control
const int clk_pin     = 6;  //clock
const int data_pin    = 5;  //data

float   hue         = 0.0;
boolean up          = true;

//Init the driver object.
ChainableLED leds(clk_pin, data_pin, rgb_pwr, 1);

void setup()
{
  //open the rgb power supply
  leds.pwr_set(PWR_ENABLE);                                 
}

void loop()
{
  
  delay(30);
  
  leds.setColorHSB(
    0,    //byte  LED number.
    hue,  //float hue
    1.0,  //float saturation
    1.0); //float brightness
  
  //Hue goes up to 1.0, then back to 0.
  if (up)
    hue+= 0.025;
  else
    hue-= 0.025;
    
  if (hue>=1.0 && up)
    up = false;
  else if (hue<=0.0 && !up)
    up = true;
}

