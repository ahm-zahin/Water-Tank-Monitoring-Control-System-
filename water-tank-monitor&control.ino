
/*getting high signal from these level pins means water/liquid 
is present at that particular level */

const int level1=7;       // high level
const int level2=6;       // mid level
const int level3=5;       // low level

const int buzzPin=10;
const int motorPin = 3;
const int ledPin=2;


void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(level1, INPUT);
  pinMode(level2, INPUT);
  pinMode(level3, INPUT);
}

void loop()
{
  int highLevel= digitalRead(level1);
  int midLevel= digitalRead(level2);
  int lowLevel= digitalRead(level3);
  
  if (lowLevel==HIGH && midLevel==HIGH && highLevel==HIGH) {
    //water/liquid on normal level
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, LOW);
  }
  
  else if (lowLevel==HIGH && midLevel==HIGH && highLevel==LOW) {
    //water/liquid on high-mid level
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, digitalRead(ledPin)^1);  //blinking
    digitalWrite(buzzPin, LOW); 
    delay(200);
  }
  
  else if (lowLevel==HIGH && midLevel==LOW && highLevel==LOW) {
    //water/liquid on mid-low level
    digitalWrite(buzzPin, digitalRead(buzzPin)^1); //blinking
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, digitalRead(ledPin)^1);  //blinking
    delay(200);
  }
  
  else if (lowLevel==LOW && midLevel==LOW && highLevel==LOW) {
    //water/liquid on low level or empty
    digitalWrite(buzzPin, HIGH);
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, HIGH);
  }

  delay(500); // Wait for 500 ms
}