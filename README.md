# Arduino Reaction Time Game

This project is an Arduino-based reaction time game that uses an LED, pushbutton, buzzer, and LCD display to test how quickly a user reacts after a random delay.

The game waits for a random amount of time, turns on an LED, plays a buzzer sound, and starts timing the user's reaction. The user presses a button as quickly as possible, and the reaction time is displayed on the LCD screen. The game also includes false start detection, timeout detection, best time tracking, average reaction time, start/replay buttons, and final game statistics.

## Features

- Random LED delay
- Pushbutton input using `INPUT_PULLUP`
- Reaction time measured with `millis()`
- Reaction time displayed in seconds
- False start detection
- Timeout detection for slow responses
- 5-round game mode
- Best reaction time tracking
- Average reaction time tracking
- LCD display output
- Buzzer feedback
- Start button
- Replay option after game over
- Final game statistics

## Hardware Used

- Arduino Uno
- LCD1602 display
- Potentiometer for LCD contrast
- LED
- Pushbutton for reaction input
- Pushbutton for start/replay
- Passive or active buzzer
- Breadboard
- Jumper wires
- Resistor for LED
- Resistor for LCD backlight if needed

## Wiring Setup

### Full Wiring Setup

Replace this image with a clear photo of the full final circuit:

![Full Wiring Setup](images/full-wiring-setup.jpg)

### LCD Wiring Close-Up

Replace this image with a closer photo of the LCD wiring:

![LCD Wiring Close-Up](images/lcd-wiring-closeup.jpg)

### Button and Buzzer Wiring Close-Up

Replace this image with a closer photo of the buttons, LED, and buzzer wiring:

![Button and Buzzer Wiring Close-Up](images/button-buzzer-wiring.jpg)

## Pin Connections

| Component | Arduino Pin / Connection |
|---|---|
| LED | Digital pin 13 |
| Reaction button | Digital pin 8 and GND |
| Buzzer | Digital pin 9 and GND |
| LCD RS | Digital pin 12 |
| LCD E | Digital pin 11 |
| LCD D4 | Digital pin 5 |
| LCD D5 | Digital pin 4 |
| LCD D6 | Digital pin 3 |
| LCD D7 | Digital pin 2 |
| LCD VSS | GND |
| LCD VDD | 5V |
| LCD VO | Middle pin of potentiometer |
| LCD RW | GND |
| LCD A | 5V through resistor if needed |
| LCD K | GND |
| Potentiometer outside pins | 5V and GND |

## How It Works

The game begins on a start screen and waits for the user to press the start button. Each round starts with the LED off and the LCD showing the current round number.

The Arduino waits for a random amount of time before turning on the LED. During this waiting period, the code checks whether the player presses the reaction button too early. If the button is pressed before the LED turns on, the game records a false start.

Once the LED turns on, the Arduino starts timing with `millis()`. The player presses the reaction button as quickly as possible, and the reaction time is calculated by subtracting the start time from the current time.

If the player takes too long to press the button, the game records a timeout. After 5 rounds, the game displays the best reaction time and average reaction time. The player can then press the replay button to reset the game and play again.

## Skills Practiced

- Arduino digital input and output
- Breadboard wiring
- LCD1602 display wiring
- Potentiometer contrast control
- Button logic with `INPUT_PULLUP`
- Buzzer control using `tone()`
- Timing with `millis()`
- Replacing `delay()` with non-blocking timing logic
- Conditional statements
- Loops
- Functions such as `resetGame()`
- Tracking game statistics across rounds
- Organizing and documenting a hardware project on GitHub

## Versions

- Version 1: Basic reaction timer with LED and button input
- Version 2: Added false start detection using `millis()`
- Version 3: Added 5-round game mode and best time tracking
- Version 4: Added average reaction time, timeout detection, and final game statistics
- Version 5: Added buzzer feedback
- Version 6: Added LCD display output
- Version 7: Added start screen, replay option, and reset function

## Future Improvements

- Add cleaner button debouncing
- Add EEPROM storage to save the best score after power-off
- Build a custom enclosure for the circuit
- Improve the wiring layout for a cleaner final build
