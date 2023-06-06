#include <Adafruit_CircuitPlayground.h>

volatile int modeControl = 0;
volatile int flip = 0;
const int buttonA = 4;
const int buttonB = 5;
const int switchPin = 7;

bool switchState = 0;
volatile bool A_flag = false;
volatile bool B_flag = false;
volatile bool switchFlag = false;

void setup() 
{
  CircuitPlayground.begin();
  randomSeed(analogRead(0)); // Seed the random, randomly
  attachInterrupt(digitalPinToInterrupt(buttonA), stop, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonB), reset, RISING);
  attachInterrupt(digitalPinToInterrupt(switchPin), on_off, CHANGE);
}

void loop() {
  if(switchFlag)
  {
    delay(5);
    switchState = digitalRead(switchPin);
    switchFlag = !switchFlag;
  }
  if(switchState)
  {

  }


}

void bounce(int flashTime)
{
  for(int k = 0; k < 5; k++)
  {
    int pin_num = k;
    int pin_two = 9-k;
    CircuitPlayground.setPixelColor(pin_num, 0, 0, 255);
    CircuitPlayground.setPixelColor(pin_two, 255, 0, 0);
    delay(flashTime/2);
    CircuitPlayground.setPixelColor(pin_num, 0, 0, 0);
    CircuitPlayground.setPixelColor(pin_two, 0, 0, 0);
    delay(flashTime/2);
    k++;
  }
    for(int k = 5; k > 0; k--)
  {
    int pin_num = k;
    int pin_two = 9-k;
    CircuitPlayground.setPixelColor(pin_num, 0, 0, 255);
    CircuitPlayground.setPixelColor(pin_two, 255, 0, 0);
    delay(flashTime/2);
    CircuitPlayground.setPixelColor(pin_num, 0, 0, 0);
    CircuitPlayground.setPixelColor(pin_two, 0, 0, 0);
    delay(flashTime/2);
    k--;
  }
}

void stop()
{
  modeControl++;
  if(modeControl > 4)
  {
    modeControl = 0;
  }
}

void reset()
{
  modeControl--;
  if(modeControl < 0)
  {
    modeControl = 4;
  }
}

void on_off()
{
  switchFlag = !switchFlag;
}