# ENGR103_Game
Engineering+ 103 Final Project

## Author
Jasper Delasanta

### Game Description
GAME DESCRIPTION/RULES:
Classic Arcade Game
GOAL:
Stop the spinning lights right on the red LED
3 Green LEDs will spin in a circle around the CPX board
They will keep spinning until there is an interrupt from button A
Once button A is clicked, the LEDs will stop spinning
If the LEDs are overlapped with the red pin(red pin is covered by the green)
Queue sound to signal success and proceed to next level
Sound will beep # of times for # level
Next level will be faster than the previous
else(the LEDs do not overlap)
Queue sound to signal game over and halt all LEDs
Use button B to reset the game

INPUTS:
Switch toggle(0/1):
  Attach interrupt to slide switch
  Slide switch activates and deactivates the game
Button A(0/1):
  This is the main game switch
  Attach interrupt to the button
  Pressing the button stops the lights and initiates the between level
Button B(0/1):
  Attach interrupt
  When pressed this button will restart the game to level 1
OUTPUTS:
 LED Array:
  Range(0,255):
  Brightness does not matter for this so it will be a set value
  Lights turn on in order starting at pin 0
  The lights turn on at a rate determined by the level
Speaker:
  Range roughly(20,20000)
  Threshold(1760)
  Beyond this the speaker sounds awful
  Plays between levels to indicate the difficulty of the level
