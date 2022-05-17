int Buzzer = 13; 
void setup() 
{
  Serial.begin(9600);
}
 
void loop() 
{
  float sensorVoltage; 
  float sensorValue;
 
  sensorValue = analogRead(A2);
  sensorVoltage = sensorValue/1024*5.0;
 
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);2
  Serial.println(" V");
  delay(1000);
  if (sensorVoltage>1.2)
  {
  tone(Buzzer, 1000); 
  delay(1000);       
  noTone(Buzzer);     
  delay(1000);
}
  else
{
 digitalWrite(Buzzer, HIGH);
 }
}
