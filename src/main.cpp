#include <XInput.h>
#include "Configuration.h"

void setup() {
  // Start the XInput function
  XInput.begin();

  // Initialize the Arduino Pins

  #ifndef IS_SIX_FRET
    pinMode(GREEN, INPUT);
    pinMode(RED, INPUT);
    pinMode(YELLOW, INPUT);
    pinMode(BLUE, INPUT);
    pinMode(ORANGE, INPUT);
  #else
    pinMode(BLACK_1, INPUT);
    pinMode(BLACK_2, INPUT);
    pinMode(BLACK_3, INPUT);
    pinMode(WHITE_1, INPUT);
    pinMode(WHITE_2, INPUT);
    pinMode(WHITE_3, INPUT);
  #endif

  #ifdef ENABLE_STRUM
    pinMode(STRUM_UP, INPUT);
    pinMode(STRUM_DOWN, INPUT);
  #endif

  #ifdef NAV_BUTTONS
    pinMode(START, INPUT);
    pinMode(SELECT, INPUT);
  #endif

  #ifdef SUPER_BUTTON
    pinMode(SUPER_BUTTON, INPUT);
  #endif

  #ifdef ENABLE_DPAD
    pinMode(D_UP, INPUT);
    pinMode(D_DOWN, INPUT);
    pinMode(D_LEFT, INPUT);
    pinMode(D_RIGHT, INPUT);
  #endif

}

// Function to get get the digital button presses
void processDigitalButtons(){

  // Coloured Frets
  #ifndef IS_SIX_FRET

    XInput.press(!digitalRead(GREEN) ? BUTTON_A : 0);
    XInput.press(!digitalRead(RED) ? BUTTON_B : 0);
    XInput.press(!digitalRead(YELLOW) ? BUTTON_Y : 0);
    XInput.press(!digitalRead(BLUE) ? BUTTON_X : 0);
    XInput.press(!digitalRead(ORANGE) ? BUTTON_LB : 0);

  #else

    XInput.press(!digitalRead(BLACK_1) ? BUTTON_A : 0);
    XInput.press(!digitalRead(BLACK_2) ? BUTTON_B : 0);
    XInput.press(!digitalRead(BLACK_3) ? BUTTON_Y : 0);
    XInput.press(!digitalRead(WHITE_1) ? BUTTON_X : 0);
    XInput.press(!digitalRead(WHITE_2) ? BUTTON_LB : 0);
    XInput.press(!digitalRead(WHITE_3) ? BUTTON_RB : 0);

  #endif

  // Strum buttons
  #ifdef ENABLE_STRUM

    // Strum Buttons
    XInput.press(!digitalRead(STRUM_DOWN) ? DPAD_DOWN : 0);
    XInput.press(!digitalRead(STRUM_UP) ? DPAD_UP : 0);

  #endif

  // Navigation buttons (start/select)
  #ifdef NAV_BUTTONS

    XInput.press(!digitalRead(START) ? BUTTON_START : 0);
    XInput.press(!digitalRead(SELECT) ? BUTTON_SELECT : 0);

  #endif

  // DPAD
  #ifdef ENABLE_DPAD
  
    XInput.press(!digitalRead(D_UP) ? DPAD_UP : 0);
    XInput.press(!digitalRead(D_DOWN) ? DPAD_DOWN : 0);
    XInput.press(!digitalRead(D_LEFT) ? DPAD_LEFT : 0);
    XInput.press(!digitalRead(D_RIGHT) ? DPAD_RIGHT : 0);

  #endif

}

/*void processAnalogAxis(){
  XInput.setJoystickY(JOY_RIGHT, analogRead(WHAMMY_PIN), false);
}*/

void loop(){

  XInput.releaseAll();

  processDigitalButtons();
  //processAnalogAxis();

}