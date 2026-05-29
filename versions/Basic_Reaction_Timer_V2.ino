// Version 3: 5-round reaction time game
// Adds best time tracking and stops after 5 rounds

int ledPin = 13;
int buttonPin = 8;
int roundCount = 0;
double bestTime = 999.0;
void  setup()
{
Serial.begin(9600);
pinMode (ledPin, OUTPUT);
pinMode (buttonPin, INPUT_PULLUP);
randomSeed(analogRead(A0));  //Helps better randomize wait times
}


void  loop()
{
  if (roundCount >= 5){
    Serial.println("Game Over!");
    Serial.print("Best Time: "); //Ends Game after 5 rounds and prints best time
    Serial.print(bestTime, 3);
    Serial.print(" s");
    while(true){

    }
  }
Serial.print("Round ");
Serial.print(roundCount + 1); //Begins new round
Serial.println(" of 5");
digitalWrite(ledPin, LOW);
int waitTime = random(1000, 5000);
unsigned long waitStartTime = millis(); 
Serial.println("Wait for the LED...");
while (millis() - waitStartTime < waitTime) {
  if (digitalRead(buttonPin) == LOW) {
    Serial.println("False Start!");  //Detects False Start
    roundCount++;
    delay(3000);
    return;
  }
}
digitalWrite(ledPin, HIGH);
Serial.println("GO!");
unsigned long int startTime = millis();
while (digitalRead(buttonPin) == HIGH) {  //Runs while loop while button is not pressed

}
unsigned long int reactionTime = millis() - startTime;
double reactionSeconds = reactionTime / 1000.0;

digitalWrite(ledPin, LOW);
Serial.print("Reaction Time: ");
Serial.print(reactionSeconds, 3);
Serial.println(" s");
if (reactionSeconds < bestTime) {
  Serial.println("New best time!");  //Reassigns best time if the reaction time is less than the global variable best time
  bestTime = reactionSeconds;
}
delay(10000);
roundCount++;
}
