const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;
char Data ;
const int trigPin = 2;
const int echoPin = 3;
long duration;
int distance;

//.......................functions...by Hisham......... 
void Forward ()
{
  analogWrite ( in1 , 255);
  analogWrite ( in2 , 0);
  analogWrite ( in3 , 255);
  analogWrite ( in4 , 0);
    
}

void Back () 
{
  analogWrite ( in1 , 0);
  analogWrite ( in2 , 255);
  analogWrite ( in3 , 0);
  analogWrite ( in4 , 255);
  
}

void Left () 
{
  analogWrite ( in1 , 255);
  analogWrite ( in2 , 0);
  analogWrite ( in3 , 0);
  analogWrite ( in4 , 0); 
}

void Right () 
{
  analogWrite ( in1 , 0);
  analogWrite ( in2 , 0);
  analogWrite ( in3 , 255);
  analogWrite ( in4 , 0);
}

void ForwardLeft ()
{
  analogWrite ( in1 , 255);
  analogWrite ( in2 , 0);
  analogWrite ( in3 , 130);
  analogWrite ( in4 , 0);
}

void ForwardRight () 
{
  analogWrite ( in1 , 130);
  analogWrite ( in2 , 0);
  analogWrite ( in3 , 255);
  analogWrite ( in4 , 0);
   
}


void BackLeft () 
{
  analogWrite ( in1 , 0);
  analogWrite ( in2 , 255);
  analogWrite ( in3 , 0);
  analogWrite ( in4 , 130);
}

void BackRight () 
{
  analogWrite ( in1 , 0);
  analogWrite ( in2 , 130);
  analogWrite ( in3 , 0);
  analogWrite ( in4 , 255);
}

void Stop ()
{
  analogWrite ( in1 , 0);
  analogWrite ( in2 , 0);
  analogWrite ( in3 , 0);
  analogWrite ( in4 , 0);
}



//Main code
void setup() 
{
  Serial.begin(9600);
  pinMode( in1 , OUTPUT);
  pinMode( in2 , OUTPUT);
  pinMode( in3, OUTPUT);
  pinMode( in4 , OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{
  if ( Serial.available() > 0  )
  {
    Data = Serial.read();

    if (Data == 'F') Forward (); 
    else if (Data == 'B') Back ();
    else if (Data =='L') Left();
    else if (Data =='R') Right();
    else if (Data =='I') ForwardRight();
    else if (Data =='G') ForwardLeft();
    else if (Data =='H') BackLeft();
    else if (Data =='J') BackRight();
    else if (Data =='S') Stop();

    //................. ULTRASONIC SENSOR..by Hadeel...
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
   
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // the travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance in cm 
    distance= duration*0.034/2;

    if (distance <= 20 ){
      Stop(); 
      delay(100);
      Back();
      delay(500);
      Stop(); 
      delay(100); 
    }
 }
}
