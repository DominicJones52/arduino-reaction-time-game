# Arduino Reaction Time Game

This project is an Arduino-based reaction time game that uses an LED and pushbutton to test how quickly a user reacts after a random delay.

## Features

- Random LED delay
- Pushbutton input using `INPUT_PULLUP`
- Reaction time measured with `millis()`
- False start detection
- 5-round game mode
- Best reaction time tracking
- Average reaction time tracking
- Timeout detection for slow responses
- Serial Monitor output in seconds

## Hardware Used

- Arduino Uno
- LED
- Pushbutton
- Breadboard
- Jumper wires
- Resistor for LED

## How It Works

The game waits for a random amount of time before turning on the LED. Once the LED turns on, the player presses the button as quickly as possible. The Arduino measures the time between the LED turning on and the button press.

If the player presses the button before the LED turns on, the game detects a false start. If the player takes too long to respond, the game records a timeout.

After 5 rounds, the game displays the best reaction time and average reaction time in the Serial Monitor.

## Skills Practiced

- Arduino digital input and output
- Breadboard wiring
- `INPUT_PULLUP` button logic
- `millis()` timing
- Replacing `delay()` with non-blocking logic
- Conditional statements
- Loops
- Tracking statistics across rounds
