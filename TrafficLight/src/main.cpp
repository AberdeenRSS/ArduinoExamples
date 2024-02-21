#include <Arduino.h>

const int BUTTON_PIN = 3;

const int RED_LED = 4;
const int YELLOW_LED = 5;
const int GREEN_LED = 6;

const int YELLOW_PHASE_TIME = 1000;

bool isGreen = false;

void switchToRed();
void switchToGreen();

void setup()
{
  pinMode(BUTTON_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(RED_LED, HIGH);
}

void loop()
{

  if (digitalRead(BUTTON_PIN) == LOW)
    return;

  if (isGreen)
  {
    switchToRed();
    return;
  }

  switchToGreen();
}

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
