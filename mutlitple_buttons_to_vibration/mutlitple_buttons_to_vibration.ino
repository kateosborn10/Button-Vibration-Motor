

#include <Sparkfun_DRV2605L.h> //SparkFun Haptic Motor Driver Library 
#include <Wire.h> //I2C library 

SFE_HMD_DRV2605L HMD; //Create haptic motor driver object 

int button_middle = 7;
int button_index = 5; // choose the input pin for pushbutton 
int button_ring = 9; 
int button_pinky = 3;

void setup() 
{
  HMD.begin();
  Serial.begin(9600);
  HMD.Mode(0); // Internal trigger input mode -- Must use the GO() function to trigger playback.
  HMD.MotorSelect(0x36); // ERM motor, 4x Braking, Medium loop gain, 1.365x back EMF gain
  HMD.Library(2); //1-5 & 7 for ERM motors, 6 for LRA motors 

}
void loop() 
{
  
   HMD.go(); // start the vibration motor

   /* Check which button is pushed and output waveform 0-122 */
   if(digitalRead(button_middle)== HIGH) {
      Serial.println("Button pressed.");
       HMD.Waveform(0, 112);}   
    else if(digitalRead(button_index) == HIGH){
      HMD.Waveform(0,20);
    }
    else if(digitalRead(button_ring) == HIGH){
      HMD.Waveform(0,80);
    }
    else if(digitalRead(button_pinky) == HIGH){
      HMD.Waveform(0,100);
    }
    /* If no button pushed then stop */
    else{
      HMD.stop();
    }


}

