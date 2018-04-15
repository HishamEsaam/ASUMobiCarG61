const int in1 = 4;
const int in2 = 7;
const int in3 = 9;
const int in4 = 10;
const int ENA=5;
const int ENB=6;
int speedCar=100 ;
int speed_Coeff=4;
char Data ;
const int trigPin = 2;
const int echoPin = 3;
long duration;
int distance;
int Ls = 13; //left sensor
int Rs = 12; // right sensor
//.......................functions...by Hisham......... 
void Forward ()
{
  digitalWrite ( in1 , HIGH);
  digitalWrite ( in2 ,LOW);
  digitalWrite ( in3 ,HIGH);
  digitalWrite ( in4 , LOW);
  analogWrite(ENA,speedCar);
  analogWrite(ENB,speedCar);
}

void Back () 
{
  digitalWrite ( in1 ,LOW);
  digitalWrite ( in2 , HIGH);
  digitalWrite ( in3 , LOW);
  digitalWrite ( in4 , HIGH);
  analogWrite(ENA,speedCar);
  analogWrite(ENB,speedCar);
}

void Left () 
{
  digitalWrite ( in1 , HIGH);
  digitalWrite ( in2 , LOW);
  digitalWrite ( in3 , LOW);
  digitalWrite  ( in4 ,HIGH);
  analogWrite(ENA,speedCar);
  analogWrite(ENB,speedCar); 
}
void Right () 
{
  digitalWrite ( in1 , LOW);
  digitalWrite ( in2 ,HIGH);
  digitalWrite ( in3 , HIGH);
  digitalWrite ( in4 , LOW);
  analogWrite(ENA,speedCar);
  analogWrite(ENB,speedCar);
}

void ForwardLeft ()
{
  digitalWrite ( in1 , HIGH);
  digitalWrite ( in2 , LOW);
  digitalWrite ( in3 , HIGH);
  digitalWrite ( in4 , LOW);
  analogWrite(ENA,speedCar/speed_Coeff);
  analogWrite(ENB,speedCar/speed_Coeff);
}

void ForwardRight () 
{
  digitalWrite ( in1 , HIGH);
  digitalWrite ( in2 , LOW);
  digitalWrite ( in3 , HIGH);
  digitalWrite ( in4 , LOW);
  analogWrite(ENA,speedCar/speed_Coeff);
  analogWrite(ENB,speedCar/speed_Coeff);
}


void BackLeft () 
{
  digitalWrite ( in1 , LOW);
  digitalWrite( in2 , HIGH);
  digitalWrite( in3 , LOW);
  digitalWrite( in4 , HIGH);
  analogWrite(ENA,speedCar/speed_Coeff);
  analogWrite(ENB,speedCar/speed_Coeff);
}

void BackRight () 
{
  digitalWrite( in1 , LOW);
  digitalWrite( in2 , HIGH);
  digitalWrite( in3 , LOW);
  digitalWrite( in4 , HIGH);
  analogWrite(ENA,speedCar/speed_Coeff);
  analogWrite(ENB,speedCar/speed_Coeff);
}

void Stop ()
{
  digitalWrite( in1 , LOW);
  digitalWrite( in2 , LOW);
  digitalWrite( in3 , LOW);
  digitalWrite( in4 , LOW);
  analogWrite(ENA,speedCar);
  analogWrite(ENB,speedCar);
  
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
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(Ls, INPUT);
  pinMode(Rs, INPUT);
}

void loop() 
{
  if ( Serial.available() > 0  )
  {
    Data = Serial.read();
if (Data =='0')speedCar = 70;
if (Data =='1')speedCar = 100;
if (Data =='2')speedCar = 120;
if (Data =='3')speedCar = 135;
if (Data =='4')speedCar = 150;
if (Data =='5')speedCar = 175;
if (Data =='6')speedCar = 190;
if (Data =='7')speedCar = 205;
if (Data =='8')speedCar = 220;
if (Data =='9')speedCar = 235;
if (Data =='q')speedCar = 255;
    if (Data == 'F') Forward (); 
    else if (Data == 'B') Back ();
    else if (Data =='L') Left();
    else if (Data =='R') Right();
    else if (Data =='I') ForwardRight();
    else if (Data =='G') ForwardLeft();
    else if (Data =='H') BackLeft();
    else if (Data =='J') BackRight();
    else if (Data =='S') Stop();
    else if (Data =='N')
      {
        while(1)
        {
      if( ( digitalRead(Ls)== HIGH) && (digitalRead(Rs) == HIGH) )   //move forward
      {   
         Forward ();
         delay(20);
         Stop();
         delay(10);
      }
    if((digitalRead(Ls) == HIGH) && !(digitalRead(Rs)== HIGH) )     // Turn right
      {
          Right();
          delay(30);
          Stop();
          delay(10);
      }
    if( ! (digitalRead(Ls)== HIGH) && ( digitalRead(Rs)== HIGH))     // turn left
      {
          Left();
          delay(30);
          Stop();
          delay(10); 
      }
    if(!(digitalRead(Ls) == HIGH) && !(digitalRead(Rs)== HIGH))     // stop
      { 
          Stop();
          break;
      }
      }
      }
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
