
/* Code adapted from https://learn.sparkfun.com/tutorials/haptic-motor-driver-hook-up-guide?_ga=2.227031901.1514248658.1513372975-1149214600.1512613196 */
#include <Sparkfun_DRV2605L.h> //SparkFun Haptic Motor Driver Library 
#include <Wire.h> //I2C library 

SFE_HMD_DRV2605L HMD; //Create haptic motor driver object 
int button = 7; // choose the input pin 7 for pushbutton 
int button_val = 0; // variable for reading the pin status

void setup() 
{
  /* Initialize Haptic Motor Driver Object */
  HMD.begin(); 
  Serial.begin(9600);
  HMD.Mode(0); // Internal trigger input mode -- Must use the GO() function to trigger playback.
  HMD.MotorSelect(0x36); // ERM motor, 4x Braking, Medium loop gain, 1.365x back EMF gain
  HMD.Library(2); //1-5 & 7 for ERM motors, 6 for LRA motors 

}
void loop() 
{
  /* Start the vibration motor */
   HMD.go();
   button_val = digitalRead(button);
   if(button_val== HIGH) {
    /* This outputs to log that button has been pressed, use for debugginh*/
      Serial.println("Button pressed.");
      /* The waveform library has 0-122 different types of waves */
       HMD.Waveform(0, 69);}
    else{
      /* If button not pushed then stop the vibration motor */
      HMD.stop();
    }


}

