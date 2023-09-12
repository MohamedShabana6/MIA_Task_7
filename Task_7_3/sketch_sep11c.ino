#define EN1  3
#define IN1  5
#define EN2  11
#define IN2  13
#define IN3  8
#define IN4  7
#define Button1  2
#define Button2  4
#define volt A0
#define trig 10
#define echo 9
const float alpha =0.5;
unsigned long distance = 0;
int speed = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EN1,OUTPUT);
  pinMode(IN1,OUTPUT);
  //pinMode(EN2,OUTPUT);
  pinMode(IN2,OUTPUT);
 // pinMode(IN3,OUTPUT);
  //pinMode(IN4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(Button1,INPUT);
  pinMode(Button2,INPUT);
  pinMode(volt,INPUT);
 
}
double cur_avg= 0.0;
double last_avg= 0.0;
void loop() {
  // put your main code here, to run repeatedly:
 int volts = analogRead(volt);
 speed = volts/4;
 Serial.println(speed);
cur_avg=(speed*alpha) + ((last_avg)*(1-alpha));
last_avg =cur_avg ;
//Serial.print("volt before: ");
//Serial.println(volts);

Serial.println(cur_avg);
analogWrite(EN1,cur_avg);
int Reading1 = digitalRead(Button1);
if(Reading1 == HIGH)
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
Serial.println("Motion is Anti-Clockwise");
}
int Reading2 = digitalRead(Button2);
if (Reading2 == HIGH)
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
Serial.println("Motion is Clockwise");
}
//digitalWrite(EN2,HIGH);
//digitalWrite(IN3,HIGH);
//digitalWrite(IN4,HIGH);
unsigned long distance2 = Measure();
Serial.print("distance: ");
Serial.println(distance2);
}
unsigned long Measure(){
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
distance = pulseIn(echo,HIGH);
//digitalWrite(trig,HIGH);
distance = distance/29/2;
return distance;
}
