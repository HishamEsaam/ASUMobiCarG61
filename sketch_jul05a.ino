int i = 1;
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
int Bs = 11; 
 
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
 pinMode(Bs, INPUT); 
}

void loop() 
{
  if ( Serial.available() > 0  )
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // the travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance in cm 
    distance= duration*0.034/2;
    
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

    if (Data == 'F' && distance > 30) Forward ();
    else if (Data == 'F' && distance <= 30 ){
      Stop(); 
      delay(100);
      Back();
      delay(200);
      Stop(); 
      delay(100);
      } 
    else if (Data =='B') Back ();
    else if (Data =='L') Left();
    else if (Data =='R') Right();
    else if (Data =='I') ForwardRight();
    else if (Data =='G') ForwardLeft();
    else if (Data =='H') BackLeft();
    else if (Data =='J') BackRight();
    else if (Data =='S') Stop();
    //circle shape
    else if (Data =='C')
      {
    digitalWrite ( in1 , HIGH);
    digitalWrite ( in2 , LOW);
    digitalWrite ( in3 , HIGH);
    digitalWrite ( in4 , LOW);
    analogWrite(ENA,200);
    analogWrite(ENB,70);
    delay(10000);
       }
       break;
     //infinity shape
    else if (Data =='Y')
       {
    digitalWrite ( in1 , HIGH);
    digitalWrite ( in2 , LOW);
    digitalWrite ( in3 , HIGH);
    digitalWrite ( in4 , LOW);
    analogWrite(ENA,200);
    analogWrite(ENB,50);
    delay(2800);
    Forward ();
    delay(1000);
    digitalWrite ( in1 , HIGH);
    digitalWrite ( in2 , LOW);
    digitalWrite ( in3 , HIGH);
    digitalWrite ( in4 , LOW);
    analogWrite(ENA,50);
    analogWrite(ENB,200);
    delay(2800);
    Forward ();
    delay(1000);
       }
       //rectangle shape
    else if (Data =='R')
       {
    for (i; i <=4 ; i++)
       {
    Forward ();
    delay (2150);  // time required to move 1 meters
    Left ();
    delay(890);    // time required to turn 90 degrees left
       }
    Stop();
       }
       break;
    else if (Data =='N')
      {
        while(1)
        {
      if( ( digitalRead(Ls)== HIGH) && (digitalRead(Rs) == HIGH)&& !(digitalRead(Bs)==HIGH))   //move forward
      {   
         Forward ();
         delay(15);
         Stop();
         delay(20);
      }
      if( ( digitalRead(Ls)== HIGH) && (digitalRead(Rs) == HIGH) && (digitalRead(Bs)==HIGH)  )   //move forward
      {   
         Forward ();
         delay(15);
         Stop();
         delay(20);   
      }
    if((digitalRead(Ls) == HIGH)&& (digitalRead(Bs)==HIGH) && !(digitalRead(Rs)== HIGH))     // Turn right
      {
          Right();
          delay(40);
          Stop();
          delay(40);
      }
       if((digitalRead(Ls) == HIGH)&& !(digitalRead(Bs)==HIGH) && !(digitalRead(Rs)== HIGH))     // Turn right
        {
          Forward();
          delay(15);
          Stop();
          delay(20);
      }
    if( ! (digitalRead(Ls)== HIGH) && ( digitalRead(Rs)== HIGH)&&(digitalRead(Bs)==HIGH))     // turn left
      {
          Left();
          delay(40);
          Stop();
          delay(40); 
      }

      if( ! (digitalRead(Ls)== HIGH) && ( digitalRead(Rs)== HIGH)&&!(digitalRead(Bs)==HIGH))     // turn left
      {
          Forward();
          delay(15);
          Stop();
          delay(20);
      }
      if( ! (digitalRead(Ls)== HIGH) &&!( digitalRead(Rs)== HIGH)&&(digitalRead(Bs)==HIGH))
      {
          Forward();
          delay(15);
          Stop();
          delay(20);
      }
      if(!(digitalRead(Ls)== HIGH)&&!( digitalRead(Rs)== HIGH)&&!(digitalRead(Bs)==HIGH))     
      {
          Right();
          delay(40);
          Stop();
          delay(40);
          Forward();
          delay(40);
          Stop();
      }
      }
      }
      
      if (distance <= 30 ){
      Stop(); 
      delay(100);
      Back();
      delay(200);
      Stop(); 
      delay(100); 
    }
 }
}