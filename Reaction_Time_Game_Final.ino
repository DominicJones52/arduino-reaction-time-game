// Version 7: Reaction game with start and replay buttons
// Adds start screen, replay option, resetGame function, LCD display, buzzer, and final stats
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int ledPin = 13;
int buttonPin = 8;
int startButtonPin = 6;
int replayButtonPin = 7;
int buzzerPin = 9;
int roundCount = 0;
double bestTime = 999.0;
double averageSum = 0.00;
int successfulRounds = 0;

void resetGame ()
{
  roundCount = 0;
  bestTime = 999.0;
  averageSum = 0.00;
  successfulRounds = 0;
  

}
void gameOverBuzzer() 
{

   tone(buzzerPin, 800, 200);
    delay(250);
    tone(buzzerPin, 1000, 200);
    delay(250);
    tone(buzzerPin, 1200, 300);

}





void  setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP);
  pinMode (startButtonPin, INPUT_PULLUP);
  pinMode (replayButtonPin, INPUT_PULLUP);
  pinMode (buzzerPin, OUTPUT);
  randomSeed(analogRead(A0));  //Helps better randomize wait times
}


void  loop()
{
  if (roundCount == 0) {
    digitalWrite(ledPin , LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Reaction Game");
    lcd.setCursor(0,1);
    lcd.print("Press to start");

  while (digitalRead(startButtonPin) == HIGH) {
    
    
  }
  }
 
  if (roundCount >= 5){
   
   if (successfulRounds > 0) {
    digitalWrite(ledPin, LOW);
    double average = averageSum / successfulRounds;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over!");
    delay(1000);
    

    //Serial.println("Game Over!");
    
    gameOverBuzzer();
    
    lcd.clear();                //Ends Game after 5 rounds and prints best time
    lcd.print("Best Time:");
    lcd.print(bestTime, 3);
    lcd.print("s");
    lcd.setCursor(0, 1);
    lcd.print("Avg:");
    lcd.print(average, 3);
    lcd.print("s");

    delay(5000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Play again?");

    /*Serial.print("Best Time: "); 
    Serial.print(bestTime, 3);
    Serial.println(" s");
    Serial.print("Average Reaction Time: ");
    Serial.print(average, 3);
    Serial.println(" s"); */

    while(digitalRead(replayButtonPin) == HIGH){   //Reset Game Mechanic
    }
    resetGame();
    delay(300);
    return;

   } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over!");

    gameOverBuzzer();

    delay(1000);

    lcd.clear();
    lcd.print("Best Time: N/A");
    lcd.setCursor(0, 1);
    lcd.print("Avg: N/A");

    delay(5000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Play again?");
    
   /* Serial.println("Game Over!");
    Serial.println("Best Time: no successful rounds"); 
    Serial.println("Average Reaction Time: no successful rounds"); */
    while(digitalRead(replayButtonPin) == HIGH){   //Reset Game Mechanic for all unsuccessful rounds
      

    }
    resetGame();
    delay(300);
    return;

   }
  }
  lcd.clear();          //Begins new round
  lcd.setCursor(0, 0);
  lcd.print("Round ");
  lcd.print(roundCount + 1);
  lcd.print(" of 5");
  lcd.setCursor(0, 1);
  /*Serial.print("Round ");
  Serial.print(roundCount + 1); 
  Serial.println(" of 5");
  digitalWrite(ledPin, LOW); */

  int waitTime = random(1000, 5000);
  unsigned long waitStartTime = millis(); 
  lcd.print("Wait for the LED");
  // Serial.println("Wait for the LED...");
  while (millis() - waitStartTime < waitTime) {
    if (digitalRead(buttonPin) == LOW) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Too soon!");
      lcd.setCursor(0, 1);
      lcd.print("False start");

      // Serial.println("False Start!");  //Detects False Start

      tone(buzzerPin, 200, 500);

      roundCount++;
      delay(3000);
      return;
  }
}
  digitalWrite(ledPin, HIGH);

  tone(buzzerPin, 1000, 150);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GO!");

  //Serial.println("GO!");
  unsigned long  startTime = millis();

  while (digitalRead(buttonPin) == HIGH) {  //Runs while loop while button is not pressed
    unsigned long  timePassed = millis() - startTime;
    if (timePassed > 3000) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Too slow!");
      lcd.setCursor(0, 1);
      lcd.print("Timeout");
  
     // Serial.println("Too slow!");  //Detects delayed reaction greater than 3 seconds
      tone(buzzerPin, 300, 500);
      roundCount++;
      delay(3000);
      return;
  
  }

}
  unsigned long  reactionTime = millis() - startTime;
  double reactionSeconds = reactionTime / 1000.0;

  averageSum = reactionSeconds + averageSum; //Adds reaction time from each round to average out at the end

  digitalWrite(ledPin, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(reactionSeconds, 3);
  lcd.print(" s");

  /*Serial.print("Reaction Time: ");
  Serial.print(reactionSeconds, 3);
  Serial.println(" s"); */
  if (reactionSeconds < bestTime) {
    lcd.setCursor(0,1);
    lcd.print("New best time!");
    //Serial.println("New best time!");  //Reassigns best time if the reaction time is less than the global variable best time
    bestTime = reactionSeconds;
}
  delay(4000);
  successfulRounds++;
  roundCount++;

}
