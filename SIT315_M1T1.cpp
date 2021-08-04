int LED = 13;
int PIR = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT); 
  digitalWrite(LED,LOW);
  digitalWrite(PIR,LOW);
  Serial.println("Ready");
  
}

void loop()
{
  if (digitalRead(PIR) == HIGH)
  {
  	digitalWrite(LED, HIGH);
    Serial.println("Motion: HIGH");
    delay(1000);
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("Motion: LOW");
    delay(1000);
  }
}