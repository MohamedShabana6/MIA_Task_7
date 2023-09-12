#define Sensor 5
#define OutputOfPID 6
//How many pulses the Hall Sensor outputs
int Counts = 0;
//This is the pid class definition
class PID{
  public:
  //Takes in the proportional,integration and drivitive coefficients
  //and takes the maximum integration output when making an object
  PID(float KpInput,float KiInput,float KdInput,float fInput){
  Kp = KpInput;//proportional coefficients
  Ki = KiInput;//integration coefficients
  Kd = KdInput;//drivitive coefficients
  f = fInput;//maximum integration output
  LastTime = (float)millis()/ 1000;//initiating the starting time
  }
  //Calculates the time difference
  float GetDeltaTime(){
    //ensuring that delta time isn't 0
    delay(50);
    //Takes in the present time
    float TimeNow = (float)millis()/ 1000;
    float dTime;
    //Calculates the time difference
    dTime = TimeNow - LastTime;
    //Setting the time for the next Calculation
    LastTime = TimeNow;
  	
    return dTime;
  }
  
  float PID_Output(float OutputNeeded,float SensorReading){
    //Calculating the error
    float Error = OutputNeeded - SensorReading;
    //Getting deltatime
    float DeltaTime = GetDeltaTime();
    //Getting the Proportional, Integration and Drivitive to add 
    float PIDProportional = Proportional(Kp,Error);
    float PIDIntegration = Integration(Ki,f,Error,DeltaTime);
    float PIDDrivitive = Drivitive(Kd,Error,LastError,DeltaTime);

    return PIDProportional+PIDIntegration+PIDDrivitive;
  }
  
  private:
  //This is the accumulative integration error
  float IntegrationError = 0;
  //Keeps the last error value 
  float LastError = 0;
  
  float Kd,Ki,Kp,f;
  float LastTime;
  //Calculates the proportional part of PID
  float Proportional(float Kp,float Error){
    
    return Kp * Error;
  }
  //Calculates the integration part of PID
  float Integration(float Ki,float f,float Error,float DeltaTime){
    //Solves the Integral windup by giving a max value
    if(IntegrationError <= f){
    //calculates the integration 
    IntegrationError += Error * DeltaTime;
    
    }
    
    return Ki * IntegrationError;
  }
  //Calculates the drivitive part of PID
  float Drivitive(float Kd,float Error,float LastError,float DeltaTime){
    //Calculates the drivitive
    float DrivitiveError = (Error - LastError) / DeltaTime;
    //Setting the time for the next Calculation
    LastError = Error;

    return Kd * DrivitiveError;
  }
  

};

float GetSensorReading(){
  float BeginTime = millis();
  float TimeNow;
  //waits for 1 second
  while(TimeNow >= BeginTime + 1000){
    TimeNow = millis();
  }
  //450 is how many pulses the Hall Sensor outputs for every liter in the YF-S201 modle it is sensor dependent
  //2.11888 is the convertion constant to convert from L/S to CFM
  //See https://www.seeedstudio.com/blog/2020/05/11/how-to-use-water-flow-sensor-with-arduino/ for the proof to get the flow rate in L/S
  float FlowRate = (float)Counts/450*2.11888;
  //Resetting the counts for the next Calculation
  Counts = 0;
  
  return FlowRate;
}

void GetCounts(){
  Counts++;
}

void setup() {

  pinMode(Sensor,INPUT);
  pinMode(OutputOfPID,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(Sensor), GetCounts, RISING);

  Serial.begin(9600);
}

void loop() {

  float OutputNeeded = 90;
  float FlowRateOutput = GetSensorReading();
  
  PID MyPID(5,2,1.2,80);
  float Output = MyPID.PID_Output(OutputNeeded,FlowRateOutput);
  
  Serial.println(Output);

  analogWrite(OutputOfPID, Output);
}
