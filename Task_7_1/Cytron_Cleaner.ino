/* Code for controling a dc motor using cytron
* this code only uses two pins from cytron which is PWM for the motor speed (pin 3) 
* and Dir for the motor direction (pin 2)
* this code also usues exponential smoothing Filter to smooth to the sudden change of the motor speed from 0 to 255
*/
# define MotorDirection  2           // pin 2 as dir pin
# define MotorSpeed   3             // the pwd pin ~3 as pwd pin 

const float alpha = 0.9 ;         // The smoothing factor
int max_speed = 255 ;            // Maximum speed of dc motor 
double speed_filt = 0.0 ;

void setup() {
  Serial.begin(9600);                                        //intialize the serial monitor
  pinMode (MotorDirection,OUTPUT);                          // declare pin MotorDirection as OUTPUT
  pinMode (MotorSpeed,OUTPUT);                             // declare pin MotorSpeed as OUTPUT
}


void loop() {
   digitalWrite(MotorDirection,LOW);            // output A is HIGH , so the motor goes in the counter clockwise direction
   digitalWrite(MotorSpeed,HIGH);                                
   speed_filt =  (alpha * MotorSpeed) + ((1-alpha) *speed_filt ) ;          // smooth filtering equation 
   digitalWrite(MotorSpeed,LOW);
   speed_filt =  (alpha * MotorSpeed) + ((1-alpha) *speed_filt ) ;
   digitalWrite(MotorDirection,HIGH);
   speed_filt =  (alpha * MotorSpeed) + ((1-alpha) *speed_filt ) ;
   Serial.println(speed_filt);                                      // Printing the filtered speed to the serial monitor
   delay(10);
  }

  