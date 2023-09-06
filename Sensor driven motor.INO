int motor1 = 10 , trig = 13, echo = 11;
double time, distance;
void setup()
{
  pinMode(motor1, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(10000);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //Sends a 10microsec pulse
  time = pulseIn(echo, HIGH);
  //Gives the time from echo to go from high to low
  distance = time / 148.1;
  //Gives distance in inches
  Serial.println(distance);
  if(distance >= 5.0){
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  //Turns the motor on if nothing is at or within 5 inches of the
  //sensor and then turns the motor off if something is 
  //within 5 inches of the motor
}
