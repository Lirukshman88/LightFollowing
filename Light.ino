//Initializes the motor controls and photoresistor
int enableleft = 5;
int enableright= 10;
int motorleft = 6;
int motorleft2 = 7;
int motorright = 3;
int motorright2 = 4;
int sensor1 = A1; 
int sensor2 = A2; 
int sensor3 = A3;
 
void setup() {
//Setup pinMode for motors and photoresistors
  pinMode (10, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop() {
//Receives readings from photoresistors
  digitalWrite(9, HIGH);
  int sensor1pin = analogRead(sensor1);
  int sensor2pin = analogRead(sensor2);
  int sensor3pin = analogRead(sensor3);
  Serial.print("sensor1:");
  Serial.println(sensor1pin);
  Serial.print("sensor2:");
  Serial.println(sensor2pin);
  Serial.print("sensor3:");
  Serial.println(sensor3pin);

//Check to see which photoresistor has the most light and turns the motor towards it
if(sensor2pin < 1000)
{
    analogWrite(5, 255);
    analogWrite(10, 255);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH); 
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
}
else if(sensor1pin < 1000)
{
    analogWrite(5, 255);
    analogWrite(10, 255);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
}
else if(sensor3pin < 1000)
{
    analogWrite(5, 255);
    analogWrite(10, 255);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);   
}
else 
{
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);  
}
} 
    
  
