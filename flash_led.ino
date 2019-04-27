 byte led = 13;  
 byte button = 1; 
 int val=0;
 void setup() {
  pinMode(led,OUTPUT);
  pinMode (button, INPUT); 

}

void loop() {
  val = digitalRead (button);
  if (val == HIGH){
  digitalWrite (led, HIGH);
  delay(500);
  digitalWrite (led, LOW);
  delay(500);
  }
  if (val == LOW){ 
    digitalWrite (led, LOW);
  }
}
