// Version 2: Reaction timer with false start detection
// Random LED delay, checks for early button press, measures reaction time in seconds


int ledPin = 13;
int buttonPin = 8;
int roundCount = 0;
void  setup()
{
Serial.begin(9600);
pinMode (ledPin, OUTPUT);
pinMode (buttonPin, INPUT_PULLUP);
randomSeed(analogRead(A0));
}


void  loop()
{
Serial.println("New Round!");
digitalWrite(ledPin, LOW);
int waitTime = random(1000, 5000);
unsigned long waitStartTime = millis();
Serial.println("Get ready...");
while (millis() - waitStartTime < waitTime) {
  if (digitalRead(buttonPin) == LOW) {
    Serial.println("False Start!");
    delay(3000);
    return;
  }
}
digitalWrite(ledPin, HIGH);
Serial.println("GO!");
unsigned long int startTime = millis();
while (digitalRead(buttonPin) == HIGH) {

}
unsigned long int reactionTime = millis() - startTime;
double reactionSeconds = reactionTime / 1000.0;
digitalWrite(ledPin, LOW);
Serial.print("Reaction Time: ");
Serial.print(reactionSeconds, 3);
Serial.println(" s");
delay(10000);
roundCount++;
}
