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
void loop ()
{
  //circle shape
digitalWrite ( in1 , HIGH);

  digitalWrite ( in2 , LOW);

  digitalWrite ( in3 , HIGH);

  digitalWrite ( in4 , LOW);

  analogWrite(ENA,200);

  analogWrite(ENB,70);

}

