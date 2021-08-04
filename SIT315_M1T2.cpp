int LED = 13;
int PIR = 2;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);  
  pinMode(PIR, INPUT);
  digitalWrite(PIR, LOW);
  digitalWrite(LED, LOW);
  Serial.println("Ready");
  Serial.println("LED off");
  attachInterrupt(digitalPinToInterrupt(PIR), motion, CHANGE);
  
}

void loop()
{
  Serial.print("Motion: ");
  Serial.println(String(digitalRead(PIR)));
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