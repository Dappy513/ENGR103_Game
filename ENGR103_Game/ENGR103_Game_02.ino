#include <Adafruit_CircuitPlayground.h>

const int initLevel = 1; //starting level
const int levelScale = 10; //amount that the speed increases by in ms
volatile int levelNum = initLevel; //indicator of current level
const int initSpeed = 250; //initial speed that the colors rotate in ms per LED
volatile int LEDspeed = initSpeed; //current level speed
const int buttonA = 4;
const int buttonB = 5;
const int switchPin = 7;
volatile int k = 0;

bool switchState = 0;
volatile bool A_flag = false;
volatile bool B_flag = false;
volatile bool switchFlag = false;
volatile bool stopFlag = 0;

void setup() 
{
  CircuitPlayground.begin();
  attachInterrupt(digitalPinToInterrupt(buttonA), stop, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonB), reset, RISING);
  attachInterrupt(digitalPinToInterrupt(switchPin), on_off, CHANGE);
}

void loop() {
  CircuitPlayground.setPixelColor(7, 255, 0, 0);
  if(switchFlag)     //switch turns the game on or off
  {
    delay(5);
    switchState = digitalRead(switchPin);
    switchFlag = !switchFlag;
  }
  if(switchState)
  {
    for(int k = 0; k < 10; k++)
    {
      int pin_num = k;
      int pin_two = k+1;
      int pin_three = k-1;
      if(stopFlag = 1)
      {
        CircuitPlayground.playTone(700, 150);
        LEDspeed = LEDspeed - levelNum*levelScale;
        levelNum++;
      }
      CircuitPlayground.setPixelColor(pin_num, 0, 0, 255);
      CircuitPlayground.setPixelColor(pin_two, 0, 0, 255);
      CircuitPlayground.setPixelColor(pin_three, 0, 0, 255);
      delay(LEDspeed);
      CircuitPlayground.setPixelColor(pin_num, 0, 0, 0);
      CircuitPlayground.setPixelColor(pin_two, 0, 0, 0);
      CircuitPlayground.setPixelColor(pin_three, 0, 0, 0);  
    }
  }

}

void stop()
{
  int LEDspot = k;
  if(LEDspot = 7 || LEDspot = 8 || LEDspot = 6)
  {
    stopFlag = 1;
  }
}

void reset()
{

}

void on_off()
{
  switchFlag = !switchFlag;
}
