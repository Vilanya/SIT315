// https://www.electrosoftcloud.com/en/pcint-interrupts-on-arduino/
// https://www.youtube.com/watch?v=2kr5A350H7E
// 
const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;

int led1 = 10; 
int led3 = 12; 
int led2 = 11;

int PIR1 = 5; 
int PIR2 = 6; 
int PIR3 = 7; 

int state1 = LOW;
int state2 = LOW;
int state3 = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  //digitalWrite(led1, HIGH);
  //Serial.println("Tried to turn LED1 on");
  //digitalWrite(led1, LOW);
  Serial.println("Ready");
  
  PCICR |= B00000100;
  PCMSK2 |= B11100000; 
  
  TCCR1B &= ~(1 << WGM13);
  TCCR1B |= (1 << WGM12);
  
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);
  
  TCNT1= t1_load;
  OCR1A= t1_comp;
  
  TIMSK1 = (1 << OCIE1A);
  
  sei();
}

void loop()
{
  delay(1000);
}

ISR(PCINT2_vect)
{
  state1 = digitalRead(PIR1);
  state2 = digitalRead(PIR2);
  state3 = digitalRead(PIR3);
  
} 

void trigger(){
  if(state1 == HIGH)
  {
    Serial.println("PIR1:HIGH");
    digitalWrite(led1,HIGH);
  }
  digitalWrite(led1,LOW);
  
  if(state2 == HIGH)
  {
    Serial.println("PIR2:HIGH");
    digitalWrite(led2,HIGH); 
  }
  digitalWrite(led2,LOW);
  
  if(state3 == HIGH)
  {
    Serial.println("PIR3:HIGH");
    digitalWrite(led3,HIGH);
  }
  digitalWrite(led3,LOW);
}

ISR(TIMER1_COMPA_vect)
{
  trigger();
}


