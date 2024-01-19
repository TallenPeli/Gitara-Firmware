#include <XInput.h>
#include "Configuration.h"

void setup() {
  // Start the XInput function
  XInput.begin();
  XInput.setAutoSend(false);

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

  pinMode(STRUM_UP, INPUT);
  pinMode(STRUM_DOWN, INPUT);

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

void loop(){

  // Coloured Frets
  #ifndef IS_SIX_FRET
    if(digitalRead(GREEN) == HIGH){
      XInput.press(BUTTON_A);
    }
    if(digitalRead(RED) == HIGH){
      XInput.press(BUTTON_B);
    }
    if(digitalRead(YELLOW) == HIGH){
      XInput.press(BUTTON_Y);
    }
    if(digitalRead(BLUE) == HIGH){
      XInput.press(BUTTON_X);
    }
    if(digitalRead(ORANGE) == HIGH){
      XInput.press(BUTTON_LB);
    }
  #endif

  // Strum Buttons
  if(digitalRead(STRUM_DOWN) == HIGH){
    XInput.press(DPAD_DOWN);
  }
  if(digitalRead(STRUM_UP) == HIGH){
    XInput.press(DPAD_UP);
  }

  #ifdef NAV_BUTTONS
    // Start and Select
    if(digitalRead(START) == HIGH){
      XInput.press(BUTTON_START);
    }
    if(digitalRead(SELECT) == HIGH){
      XInput.press(BUTTON_BACK);
    }
  #endif

  // DPAD
  #ifdef ENABLE_DPAD    
    if(digitalRead(D_UP) == HIGH){
      XInput.press(DPAD_UP);
    }
    if(digitalRead(D_DOWN) == HIGH){
      XInput.press(DPAD_DOWN);
    }
    if(digitalRead(D_LEFT) == HIGH){
      XInput.press(DPAD_LEFT);
    }
    if(digitalRead(D_RIGHT) == HIGH){
      XInput.press(DPAD_RIGHT);
    }
  #endif

  XInput.send();
}