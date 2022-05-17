
int Buzzer = 13; 
int FlamePin = 2; 
int Flame = HIGH;
 
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
 tone(Buzzer, 1000); 
  delay(1000);        
  noTone(Buzzer);     
  delay(1000);
 }
 else
 {
 Serial.println("No flame");
 digitalWrite(Buzzer, HIGH);
 }
}
