//motor left
int in1 = 7; 
int in2 = 6;
int ena1=9;
//motor right
int in3 = 5; 
int in4 = 4;
int ena2=10;

//encoder
int enCL=3;
int enCR=2;

int motorSpeed=60;
int carDirection;

 long countL = 0;
signed long countR = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
  pinMode(enCL,INPUT);
  pinMode(enCR,INPUT);
  attachInterrupt(digitalPinToInterrupt(enCL),cntl,CHANGE);
  attachInterrupt(digitalPinToInterrupt(enCR),cntr,CHANGE);
  analogWrite(ena1, motorSpeed);
  analogWrite(ena2, motorSpeed);
  carDirection=HIGH;
}

void cntl(){
  countL++;
  
}

void cntr(){
  countR++;
}

void loop() {
  Serial.println(countL);
  //Serial.print("\t" +countR);
  if(countR >= 400){
    //stop
    digitalWrite(in1,1);
    digitalWrite(in2,1);
    digitalWrite(in3,1);
    digitalWrite(in4,1);
    delay(2000);
  
    carDirection = !carDirection;
    countL = 0;
    countR = 0;
  }
  digitalWrite(in1,!carDirection);
  digitalWrite(in2,carDirection);
  digitalWrite(in3,!carDirection);
  digitalWrite(in4,carDirection);
  analogWrite(ena1, 40);
  analogWrite(ena2, 40);
}
