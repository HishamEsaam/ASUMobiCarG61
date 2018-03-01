byte led = 13;
int sensorIn = 0;  
int sensorVal; 
void setup() {
  pinMode(led, OUTPUT); 
  Serial.begin(9600); 

}

void loop() {
  sensorVal = analogRead (sensorIn) / 1.023; // read value from 0 to 1000 (0 sec to 1 sec) 
  Serial.println(sensorVal); // show the value of the sensor
  digitalWrite (led, HIGH); 
  delay (sensorVal);
  digitalWrite (led, LOW); 
  delay (sensorVal);  
}
