// Version 4: 5-round reaction time game with timeout feature and average time
// Adds average time tracking and a timeout if the reaction is slower than 3 seconds

int ledPin = 13;
int buttonPin = 8;
int roundCount = 0;
double bestTime = 999.0;
double averageSum = 0.00;
double average = averageSum / 5;
void  setup()
{
Serial.begin(9600);
pinMode (ledPin, OUTPUT);
pinMode (buttonPin, INPUT_PULLUP);
randomSeed(analogRead(A0));  //Helps better randomize wait times
}


void  loop()
{
  digitalWrite(ledPin , LOW);
 
  if (roundCount >= 5){
   double average = averageSum / 5;
    Serial.println("Game Over!");
    Serial.print("Best Time: "); //Ends Game after 5 rounds and prints best time
    Serial.print(bestTime, 3);
    Serial.println(" s");
    Serial.print("Average Reaction Time: ");
    Serial.print(average, 3);
    Serial.println(" s");
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
unsigned long int timePassed = millis() - startTime;
if (timePassed > 3000) {
  Serial.println("Too slow!");  //Detects delayed reaction greater than 3 seconds
    roundCount++;
    delay(3000);
    return;
  
  }

}
unsigned long int reactionTime = millis() - startTime;
double reactionSeconds = reactionTime / 1000.0;

averageSum = reactionSeconds + averageSum; //Adds reaction time from each round to average out at the end

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
