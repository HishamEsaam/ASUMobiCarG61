const byte green= 13;
const byte yellow= 12;
const byte red= 11; 

void setup() {
    pinMode(green, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(red, OUTPUT); 

}

void loop() {
    digitalWrite (green, LOW); 
    digitalWrite (red, HIGH); 
    delay (2000); 
    digitalWrite (red, LOW); 
    digitalWrite (yellow, HIGH);
    delay (2000); 
    digitalWrite (yellow, LOW);
    digitalWrite (green, HIGH);
    delay (2000);   
}
