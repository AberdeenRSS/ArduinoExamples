#include <Arduino.h>

// Set up pin three to be an input (button connected to these)
const int BUTTON_PIN = 3;

// Set up 4, 5, 6 as an output (LEDs connected to these)
const int RED_LED = 4;
const int YELLOW_LED = 5;
const int GREEN_LED = 6;

/**
 * The time in ms the traffic light will remain with
 * the yellow light on
*/
const int YELLOW_PHASE_TIME = 1000;

/**
 * Variable to store the current state of the traffic light
*/
bool isGreen = false;

/**
 * Switch the traffic light from green to red
*/
void switchToRed()
{
  isGreen = false;

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  delay(YELLOW_PHASE_TIME);

  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

/**
 * Switch teh traffic light from red to green
*/
void switchToGreen()
{
  isGreen = true;

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  delay(YELLOW_PHASE_TIME);

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
}

void setup()
{
  pinMode(BUTTON_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(RED_LED, HIGH); // Set the traffic light to red initially as isGreen is set to false
}

void loop()
{

  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW)
    return; // If not do nothing

  // If the button is pressed and the light is
  // currently green switch it to red
  if (isGreen)
  {
    switchToRed();
    return;
  }

  // If the button is pressed and the light is
  // currently green switch it to green
  switchToGreen();
}