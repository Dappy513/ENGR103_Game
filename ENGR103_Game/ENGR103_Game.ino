#include <Adafruit_CircuitPlayground.h>

const int initSpeed = 250; //initial speed that the colors rotate in ms per LED
const int initLevel = 1; //starting level
const int levelScale = 10; //amount that the speed increases by in ms
volatile int levelNum = initLevel; //indicator of current level
volatile int LEDspeed = initSpeed; //current level speed

const int buttonA = 4;
const int buttonB = 5;
const int switchPin = 7;
volatile int k = 0;
const int notes[] = {262,294,330,349,392,440,494,523,650,750,850,950,1050,1150,1250,1350,1450};

bool switchState = 0;
volatile bool A_flag = false;
volatile bool B_flag = false;
volatile bool switchFlag = false;
volatile bool stopFlag = 0;
volatile bool resetFlag = 0;
volatile bool gameOver = 0;
volatile bool pauseFlag = 0;

int something;

void setup() 
{
  CircuitPlayground.begin();
  attachInterrupt(digitalPinToInterrupt(buttonA), pause, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonB), reset, RISING);
  attachInterrupt(digitalPinToInterrupt(switchPin), on_off, CHANGE);
  switchState = digitalRead(switchPin);
}

void loop() {
  CircuitPlayground.setPixelColor(7, 255, 0, 0);
  if(switchFlag)     //switch turns the game on or off
  {
    Serial.println("Interrupt");
    delay(5);
    switchState = digitalRead(switchPin);
    Serial.println(switchState);
    switchFlag = 0;
  }
  if(switchState == 1)
  {
    for(int k = 0; k < 10; k++)
    {
      int pin_num = k;
      int pin_two = k+1;
      int pin_three = k-1;
      if(gameOver == 1)
      {
        CircuitPlayground.playTone(400, 300);
        if(resetFlag)
        {
          CircuitPlayground.playTone(1400, 150);
          levelNum = initLevel;
          LEDspeed = initSpeed;
          gameOver = 0;
          resetFlag = !resetFlag;
        }
      }
      CircuitPlayground.setPixelColor(pin_num, 0, 0, 255);
      CircuitPlayground.setPixelColor(pin_two, 0, 0, 255);
      CircuitPlayground.setPixelColor(pin_three, 0, 0, 255);
      delay(LEDspeed);
      CircuitPlayground.setPixelColor(pin_num, 0, 0, 0);
      CircuitPlayground.setPixelColor(pin_two, 0, 0, 0);
      CircuitPlayground.setPixelColor(pin_three, 0, 0, 0);  

      if (pauseFlag == 1){
        pauseFlag = 0;
        stop(k);
      }
    pauseFlag = 0;
    }
  }
  else if(switchState == 0);
  {
    for(int i = 0; i < 10; i++)
    {
      CircuitPlayground.setPixelColor(i, 0, 0, 0);
    }
  }
}

void pause(){
  pauseFlag = 1;
}
void stop( int k)
{
  pauseFlag = 0;
  int LEDspot = k;
  Serial.println(k);
  if(LEDspot == 6 || LEDspot == 7 || LEDspot == 8)
  {
    CircuitPlayground.playTone(notes[levelNum], 500);
    LEDspeed = 0.8*LEDspeed + 1;
    levelNum++;
  }
  else
  {
    gameOver = 1;
  }
}

void reset()
{
  resetFlag = !resetFlag;
}

void on_off()
{
  switchFlag = 1;
}
