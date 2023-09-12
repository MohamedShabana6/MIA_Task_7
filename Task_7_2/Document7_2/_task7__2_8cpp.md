
# File Task7\_2.cpp


[**File List**](files.md) **>** [**Task7\_2**](dir_738cd4aa1661aed279a7e4eef8806983.md) **>** [**Task7\_2.cpp**](_task7__2_8cpp.md)

[Go to the source code of this file.](_task7__2_8cpp_source.md)













## Classes

| Type | Name |
| ---: | :--- |
| class | [**PID**](class_p_i_d.md) <br> |



## Public Attributes

| Type | Name |
| ---: | :--- |
|   | [**Counts**](_task7__2_8cpp.md#variable-counts)  <br> |


## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GetCounts**](_task7__2_8cpp.md#function-getcounts) () <br> |
|   | [**GetSensorReading**](_task7__2_8cpp.md#function-getsensorreading) () <br> |
|   | [**loop**](_task7__2_8cpp.md#function-loop) () <br> |
|   | [**setup**](_task7__2_8cpp.md#function-setup) () <br> |







## Macros

| Type | Name |
| ---: | :--- |
| define  | [**OutputOfPID**](_task7__2_8cpp.md#define-outputofpid)  <br> |
| define  | [**Sensor**](_task7__2_8cpp.md#define-sensor)  <br> |

## Public Attributes Documentation


### variable Counts 
How many pulses the Hall Sensor outputs.

```cpp
int Counts = 0;
```


## Public Functions Documentation


### function GetCounts 


```cpp

```



### function GetSensorReading 
takes the reading from the sensor

Returns
FlowRate
450 is how many pulses the Hall Sensor outputs for every liter in the YF-S201 modle it is sensor dependent 2.11888 is the convertion constant to convert from L/S to CFM See https://www.seeedstudio.com/blog/2020/05/11/how-to-use-water-flow-sensor-with-arduino/ for the proof to get the flow rate in L/S

resetting the counts for the next Calculation


```cpp
float GetSensorReading(){
  /**
 * @brief takes the reading from the sensor
 * @return FlowRate
 */
  float BeginTime = millis();
  float TimeNow;
  //waits for 1 second
  while(TimeNow >= BeginTime + 1000){
    TimeNow = millis();
  }
  /**
   * 450 is how many pulses the Hall Sensor outputs for every liter in the YF-S201 modle it is sensor dependent
   *2.11888 is the convertion constant to convert from L/S to CFM
   *See https://www.seeedstudio.com/blog/2020/05/11/how-to-use-water-flow-sensor-with-arduino/ for the proof to get the flow rate in L/S
   */
  float FlowRate = (float)Counts/450*2.11888; 
  Counts = 0; /** resetting the counts for the next Calculation */
  
  
  return FlowRate;
}

```



### function loop 


```cpp
void loop() {

  float OutputNeeded = 90;
  float FlowRateOutput = GetSensorReading();
  
  PID MyPID(5,2,1.2,80);
  float Output = MyPID.PID_Output(OutputNeeded,FlowRateOutput);
  
  Serial.println(Output);

  analogWrite(OutputOfPID, Output);
}
```



### function setup 

Setup code , initializing sensor and ouput pins and attaching interrupt to use the getCount method whenever there is a rising edge
```cpp
void setup() {
  /**
 * @brief Setup code , initializing sensor and ouput pins and attaching interrupt to use the getCount method whenever there is a rising edge
 */

  pinMode(Sensor,INPUT);
  pinMode(OutputOfPID,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(Sensor), GetCounts, RISING);

  Serial.begin(9600);
}

```


## Macro Definition Documentation



### define OutputOfPID 


```cpp

#define OutputOfPID 6
```



### define Sensor 


```cpp
#define Sensor 5
```



------------------------------
The documentation for this class was generated from the following file `D:/Downloads/Task7_2/Task7_2.cpp`


------------------------------
The documentation for this class was generated from the following file `D:/Downloads/Task7_2/Task7_2.cpp`
