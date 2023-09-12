
# Class PID


[**Class List**](annotated.md) **>** [**PID**](class_p_i_d.md)




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GetDeltaTime**](class_p_i_d.md#function-getdeltatime) () <br> |
|   | [**PID**](class_p_i_d.md#function-pid)  <br> |
|   | [**PID\_Output**](class_p_i_d.md#function-pid-output)  <br> |








## Public Functions Documentation


### function GetDeltaTime 

Calculates the time difference

Returns
dTime
<ensuring that delta time isn't 0

<Takes in the present time

<Calculates the time difference

<Setting the time for the next Calculation

```cpp
 float GetDeltaTime(){
    /**
   * @brief Calculates the time difference
   * @return dTime
   */
    
    delay(50);///<ensuring that delta time isn't 0
    
    float TimeNow = (float)millis()/ 1000;///<Takes in the present time
    float dTime;
    
    dTime = TimeNow - LastTime;///<Calculates the time difference
    
    LastTime = TimeNow;///<Setting the time for the next Calculation
    
    return dTime;
  }


```



### function PID 


PID::PID	(	float 	KpInput,
float 	KiInput,
float 	KdInput,
float 	fInput 
)		
inline
a constructor that takes in the proportional,integration and drivitive coefficients and takes the maximum integration output when making an object

Parameters
KpInput	proportional coefficients
KiInput	integration coefficients
KdInput	drivitive coefficients
fInput	maximum integration output
<initiating the starting time


```cpp
PID(float KpInput,float KiInput,float KdInput,float fInput){
    /**
   * @brief a constructor that takes in the proportional,integration and drivitive coefficients and takes the maximum integration output when making an object
   * @param KpInput proportional coefficients
   * @param KiInput integration coefficients
   * @param KdInput drivitive coefficients
   * @param fInput maximum integration output
   */
  Kp = KpInput;
  Ki = KiInput;
  Kd = KdInput;
  f = fInput;
  LastTime = (float)millis()/ 1000;///<initiating the starting time
  }
```



### function PID\_Output 

float PID::PID_Output	(	float 	OutputNeeded,
float 	SensorReading 
)		
inline
This is not needed in real-world applications it is there to make the simulation work because in the simulation it takes close to 0 seconds to get the sensor readings so deltatime would be 0

Parameters
OutputNeeded	The Actual desired output of system
SensorReading	The reading aquired from the sensor
Returns
PIDProportional+PIDIntegration+PIDDrivitive
<Calculating the error

<Get delta time

<Getting the Proportional, Integration and Drivitive to add




```cpp
float PID_Output(float OutputNeeded,float SensorReading){
    /**
     * @brief This is not needed in real-world applications it is there to make the simulation work because in the simulation it takes close to 0 seconds to get the sensor readings so deltatime would be 0
     * @param OutputNeeded The Actual desired output of system
     * @param SensorReading The reading aquired from the sensor
     * @return PIDProportional+PIDIntegration+PIDDrivitive
    */
    
    float Error = OutputNeeded - SensorReading; ///<Calculating the error
    
    float DeltaTime = GetDeltaTime(); ///<Get delta time
   
    float PIDProportional = Proportional(Kp,Error); ///<Getting the Proportional, Integration and Drivitive to add 
    float PIDIntegration = Integration(Ki,f,Error,DeltaTime);
    float PIDDrivitive = Drivitive(Kd,Error,LastError,DeltaTime);

    return PIDProportional+PIDIntegration+PIDDrivitive;
  }

```



------------------------------
The documentation for this class was generated from the following file `D:/Downloads/Task7_2/Task7_2.cpp`