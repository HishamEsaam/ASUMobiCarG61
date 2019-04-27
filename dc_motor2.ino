int dir1=10; 
int dir2=11;
int sp= 9;
int sw=0;  
int pot=0; 
int val;  

void setup() {
  pinMode (dir1, OUTPUT);
  pinMode (dir2, OUTPUT);
  pinMode (sp, OUTPUT);
  pinMode (sw, INPUT);

}

void loop() {
  val = analogRead (pot); 
  val = map (val , 0, 1023, 0, 255);
  if (digitalRead (sw) == HIGH){
    digitalWrite (dir1, LOW);
    analogWrite (dir2, val);
    delay (200); 
  }
  else{
    digitalWrite (dir2, LOW);
    analogWrite (dir1, val);
    delay (200); 
  }  

}
