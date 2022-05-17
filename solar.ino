// http://www.mrmodder.com visits for more Arduino Projects //
int Buzzer = 13; // Use buzzer for alert 
int FlamePin = 2; // This is for input pin
int Flame = HIGH; // HIGH when FLAME Exposed
 
void setup() {
 pinMode(Buzzer, OUTPUT);
 pinMode(FlamePin, INPUT);
 Serial.begin(9600);
 
}
 
void loop() {
 Flame = digitalRead(FlamePin);
 if (Flame== LOW)
 {
 Serial.println("HIGH FLAME");
 tone(Buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(Buzzer);     // Stop sound...
  delay(1000);
 }
 else
 {
 Serial.println("No flame");
 digitalWrite(Buzzer, HIGH);
 }
}
