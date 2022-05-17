/*
Flower Soil Mosture Sensor
D2 - Soil Mosture Sensor
D3 - Relay module
D4:D5 - LEDS 1,2
LED1 - Green
LED2 - Red
Connect the Soil Moisture Sensor to Digital input pin 2 and your 2 led's to digital out 4-5
*/
#include <Servo.h> 

int moistureSensor = 7;

int relay = 3;

int led1 = 4;

int led2 = 5;

int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int led = 9; // Output pin for LED
int buzzer = 12; // Output pin for Buzzer
Servo tracker;  // create servo object to control a servo 
int eastLDRPin = 0;  //Assign analogue pins
int westLDRPin = 1;
int eastLDR = 5;   //Create variables for the east and west sensor values
int westLDR = 10;
int error = 0;
int calibration = 204;  //Calibration offset to set error to zero when both sensors receive an equal amount of light
int trackerPos = 90;    //Create a variable to store the servo position

void setup()

{ 

// setting the led pins to outputs

pinMode(led1, OUTPUT);

pinMode(led2, OUTPUT);

pinMode(led, OUTPUT);
pinMode(buzzer,OUTPUT);


// setting the Relay pin to output

pinMode(relay, OUTPUT);

// Serial Begin so we can see the data from the moisture sensor in our serial input window.

Serial.begin(9600); }

 tracker.attach(11);  // attaches the servo on pin 11 to the servo object
} 
 

// the loop routine runs over and over again forever:

void loop()

{

// read the input on digital pin 2:

int sensorValue = digitalRead(moistureSensor);

// print out the value you read:

Serial.println(sensorValue);

digitalWrite(relay, HIGH);

digitalWrite(led1, LOW);

digitalWrite(led2, HIGH);

if (sensorValue == 1) {

digitalWrite(led1, HIGH);

digitalWrite(led2, LOW);

digitalWrite(relay, LOW);

Serial.println("watering");

delay(5000);

// run pump for 10 seconds

Serial.println("Finished watering"); }

delay(1000);
\
// delay 1 second between reads


Serial.println("Welcome to TechPonder Flame Sensor Tutorial");
sensorValue = analogRead(sensorPin);
Serial.println(sensorValue);
if (sensorValue < 100)
{
Serial.println("Fire Detected");
Serial.println("LED on");
digitalWrite(led,HIGH);
digitalWrite(buzzer,HIGH);
delay(1000);
}

digitalWrite(led,LOW);
digitalWrite(buzzer,LOW);
delay(sensorValue);

}

