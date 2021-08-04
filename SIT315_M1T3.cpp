int LED = 13;
int PIR = 2;
int PIR2 = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);  
  pinMode(PIR, INPUT);
  pinMode(PIR2, INPUT);
  digitalWrite(LED, LOW);
  Serial.println("Ready");
  Serial.println("LED off");
  attachInterrupt(digitalPinToInterrupt(PIR), motion, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIR2), motion2, CHANGE);
  
}

void loop()
{
  Serial.print("Motion1: ");
  Serial.println(String(digitalRead(PIR)));
  Serial.print("Motion2: ");
  Serial.println(String(digitalRead(PIR2)));
  delay(1000);        
}

void motion()
{
  if (digitalRead(PIR) == HIGH)
  {
  	digitalWrite(LED, HIGH);
    Serial.println("LED on");
    
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("LED off");
    
  }
}

void motion2()
{
  if (digitalRead(PIR2) == HIGH)
  {
  	digitalWrite(LED, HIGH);
    Serial.println("LED on");
    
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("LED off");
    
  }
}