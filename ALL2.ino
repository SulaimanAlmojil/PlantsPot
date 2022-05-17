int Buzzer1 = 13; // Use buzzer for alert 
int Buzzer2 = 13; // Use buzzer for alert 
int FlamePin = 2; // This is for input pin
int Flame = HIGH; // HIGH when FLAME Exposed
int moistureSensor = 7;
int relay = 3;
int led1 = 4;
int led2 = 5;
#include <Servo.h> 
Servo tracker;  // create servo object to control a servo 
int eastLDRPin = 0;  //Assign analogue pins
int westLDRPin = 1;
int eastLDR = 0;   //Create variables for the east and west sensor values
int westLDR = 0;
int error = 0;
int calibration = 204;  //Calibration offset to set error to zero when both sensors receive an equal amount of light
int trackerPos = 90;    //Create a variable to store the servo position

 void setup() {
 pinMode(Buzzer1, OUTPUT);
 pinMode(Buzzer2, OUTPUT);
 pinMode(FlamePin, INPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(relay, OUTPUT);
 tracker.attach(11);  // attaches the servo on pin 11 to the servo object
 Serial.begin(9600);
 }

void loop() {
  
  Flame = digitalRead(FlamePin);
 if (Flame== LOW)
 {
 Serial.println("HIGH FLAME");
 tone(Buzzer1, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(Buzzer1);     // Stop sound...
  delay(1000);
 }
 else
 {
 Serial.println("No flame");
 digitalWrite(Buzzer1, HIGH);
 }

{
 int sensorValue = digitalRead(moistureSensor);
 Serial.println(sensorValue);
digitalWrite(relay, HIGH);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
if (sensorValue == 1)
{
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
digitalWrite(relay, LOW);
Serial.println("watering");
delay(5000);
// run pump for 10 seconds
Serial.println("Finished watering");
}
delay(1000);

}


{ 
  eastLDR = calibration + analogRead(eastLDRPin);    //Read the value of each of the east and west sensors
  westLDR = analogRead(westLDRPin);
  if(eastLDR<350 && westLDR<350)  //Check if both sensors detect very little light, night time
  {
    while(trackerPos<=160)  //Move the tracker all the way back to face east for sunrise
    {
      trackerPos++;
      tracker.write(trackerPos);
      delay(100);
    }
  }
  error = eastLDR - westLDR;          //Determine the difference between the two sensors.
  if(error>15)        //If the error is positive and greater than 15 then move the tracker in the east direction
  {
    if(trackerPos<=160)  //Check that the tracker is not at the end of its limit in the east direction
    {
      trackerPos++;
      tracker.write(trackerPos);  //Move the tracker to the east
    }
  }
  else if(error<-15)  //If the error is negative and less than -15 then move the tracker in the west direction
  {
    if(trackerPos>20)  //Check that the tracker is not at the end of its limit in the west direction
    {
      trackerPos--;
      tracker.write(trackerPos);  //Move the tracker to the west
    }
  }
  delay(100);
} 


{
  float sensorVoltage; 
  float sensorValue;
  sensorValue = analogRead(A2);
  sensorVoltage = sensorValue/1024*5.0;
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  delay(10);
  if (sensorVoltage>1.5)
  {
  tone(Buzzer2, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(Buzzer2);     // Stop sound...
  delay(1000);
}
  else
{
 digitalWrite(Buzzer2, HIGH);
 }
}
}

 

