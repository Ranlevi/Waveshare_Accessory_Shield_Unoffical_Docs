/*
Waveshare Accessory Shield Joystick Demo
========================================

The following code is based on the demo code provided
by Waveshare. 

Author:   Ran Levi
Email:    ran@ranlevi.com
Date:     July 23rd, 2022
Revision: 0.1

Description:
- When the user uses the joystick, relevant messages will
appear in the Serial Monitor.
- The Uno's built-in LED will flash, as a visual confirmation 
that the software is runnihg.
*/

// I/O pins definition
#define    KEY_UP        A1
#define    KEY_DOWN      A5
#define    KEY_LEFT      A3
#define    KEY_RIGHT     A2
#define    KEY_ENTER     A4

//Global variales declartion.
int key_release_flag  = 1;
int i;
int time_ticks        = 0;

void setup(void)
{
  //Pin for Built-in LED
  pinMode(13, OUTPUT);
  
  //Pins for the joystick
  //Default value is HIGH.
  pinMode(KEY_UP, INPUT);
  digitalWrite(KEY_UP, HIGH);
  
  pinMode(KEY_DOWN, INPUT);
  digitalWrite(KEY_DOWN, HIGH);
  
  pinMode(KEY_LEFT, INPUT);
  digitalWrite(KEY_LEFT, HIGH);
  
  pinMode(KEY_RIGHT, INPUT);
  digitalWrite(KEY_RIGHT, HIGH);
  
  pinMode(KEY_ENTER, INPUT);
  digitalWrite(KEY_ENTER, HIGH);
 
  //Init the Serial communication with the board.
  Serial.begin(9600);
}

void loop(void)
{
  
  //Flashing the Bulit-in LED
  //Note: we're using a 1ms delay since delay() blocks the input pins
  //      from being read. 
  
  delay(1);
  time_ticks++;  
  
  if(time_ticks == 500)
  {
    digitalWrite(13, HIGH);
  }
  else if(time_ticks == 1000)
  {
    digitalWrite(13, LOW);
    time_ticks = 0;
  }
  
  if( (digitalRead(KEY_UP)    == LOW) || 
      (digitalRead(KEY_DOWN)  == LOW) || 
      (digitalRead(KEY_LEFT)  == LOW) || 
      (digitalRead(KEY_RIGHT) == LOW) || 
      (digitalRead(KEY_ENTER) == LOW)){
    
    
    
  }
  
  //Reading the Joystick position.
  //Note: key_released_flag is used to make sure that each press is
  //      detected only once (i.e., messages are not sent continuesly
  //      while the joystick is kept pressed.)
  
  if( (digitalRead(KEY_UP)    == LOW) || 
      (digitalRead(KEY_DOWN)  == LOW) || 
      (digitalRead(KEY_LEFT)  == LOW) || 
      (digitalRead(KEY_RIGHT) == LOW) || 
      (digitalRead(KEY_ENTER) == LOW))
  {
    
    if(key_release_flag) //Joystick wasn't pressed before.
    {
      
      //Debounce protection: wait for 10ms to make sure the 
      //press is continuos. 
      delay(10); 
      
      key_release_flag = 0;
    
      if(digitalRead(KEY_UP) == LOW)
        Serial.print("you press UP\n");
      else if(digitalRead(KEY_DOWN) == LOW)
        Serial.print("you press DOWN\n");
      else if(digitalRead(KEY_LEFT) == LOW)
        Serial.print("you press LEFT\n");
      else if(digitalRead(KEY_RIGHT) == LOW)
        Serial.print("you press RIGHT\n");
      else if(digitalRead(KEY_ENTER) == LOW)
        Serial.print("you press ENTER\n");
    
    }
  }
  else
    key_release_flag = 1;
  
}
