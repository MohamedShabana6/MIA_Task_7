# Task 7.1

This objective of this project is to make an Autonomous Planet Cleaner (APC) machine using a DC motor controlled using cytron which is a DC motor driver , in addition to implementing an exponential smoothing filter to achieve a soft start for the motor.  

# components :

1. DC motor
2. Arduino UNO board
3. Cytron motor driver
4. 12V battery to drive the motor

# Hardware Connections:

- **Motor to cytron** : connect the +ve and -ve terminals of the motor to the +Motor and -Motor terminals on the cytron .
- **Power supply to cytron :** connect 12V power supply to the +ve and -ve terminals on the Cytron motor driver.
- **Cytron to Arduino**  :  Connect the "GND" pin of the Cytron motor driver to one of the GND pins on the Arduino , then connect the “PWM” pin of the cytron to a pwm(~) pin Arduino in our case it is pin3 and connect the “DIR” pin to a any pin in Arduino in our case it is pin 2
    
    ![2023-09-10.png](Task%207%201%20ca95157262154affa93e9cd8183ee951/2023-09-10.png)
    

# Code :

## Hardware Setup :

```arduino
# define MotorDirection  2           // pin 2 as dir pin
# define MotorSpeed   3             // the pwd pin ~3 as pwd pin
```

## Variables :

```arduino
const float alpha = 0.9 ;         // The smoothing factor 
double speed_filt = 0.0 ;
```

## Setup :

```arduino
void setup() {
  Serial.begin(9600);                                        //intialize the serial monitor
  pinMode (MotorDirection,OUTPUT);                          // declare pin MotorDirection as OUTPUT
  pinMode (MotorSpeed,OUTPUT);                             // declare pin MotorSpeed as OUTPUT
}
```

## Loop :

in loop we control the motor speed and integrate the smoothing filter to add the soft start function to the motor 

```arduino
void loop() {
   digitalWrite(MotorDirection,LOW);            // output A is HIGH , so the motor goes in the counter clockwise direction
   digitalWrite(MotorSpeed,LOW);
   digitalWrite(MotorSpeed,HIGH);                                
   speed_filt =  (alpha * MotorSpeed) + ((1-alpha) *speed_filt ) ;          // smooth filtering equation 
   Serial.println(speed_filt);                                      // Printing the filtered speed to the serial monitor
   delay(10);
  }
```

# Soft Start Filter :

In our application we want the motor to reach its maximum speed without noticeable gradual acceleration but that abrupt change can cause damage to the motor and to protect the motor and its components we can implement a soft start mechanism which can be done using exponential smoothing filter.

Exponential smoothing can be used to gradually change the motor speed, preventing sudden changes, the simplest form an exponential smoothing formula is  :

$$
S_t = αx_t + (1-α)S_{t-1}
$$

where 

- $S_t$ : The smoothed value at time (t) , which in our case is the (filt_speed).
- $x_t$ :  The observed value at time (t) , which in our case is the (MotorSpeed).
- $α$ (alpha) : The smoothing factor, a value between 0 and 1. α is chosen depending on the application , for our application we set it to 0.9 as we want high responsiveness .

Here is a graph that shows the change of the motor speed over time with and without the exponential smoothing filter that creates a soft start

![soft start.png](Task%207%201%20ca95157262154affa93e9cd8183ee951/soft_start.png)

---

# How suitable is the DC motor for this project :

The DC motor is a suitable motor and a good match for the Autonomous Planet Cleaner (APC) project , this because the DC motor is usually chosen for its reliability as it provides constant torque regardless of the load conditions which will ensure consistent performance from our APC , it also has excellent controllability as it is easier to control than other motors, and all these specifications go well with the APC requirements