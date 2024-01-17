#include "lib/XInput.h"
#include "Configurations/Configuration.h"

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

  pinMode(STRUM_UP, INPUT);
  pinMode(STRUM_DOWN, INPUT);
  pinMode(START, INPUT);
  pinMode(SELECT, INPUT);
  pinMode(SUPER_BUTTON, INPUT);

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
      XInput.press(TRIGGER_LEFT);
    }
    if(digitalRead(RED) == HIGH){
      XInput.press(BUTTON_LB);
    }
    if(digitalRead(YELLOW) == HIGH){
      XInput.press(TRIGGER_RIGHT);
    }
    if(digitalRead(BLUE) == HIGH){
      XInput.press(BUTTON_RB);
    }
    if(digitalRead(ORANGE) == HIGH){
      XInput.press(BUTTON_A);
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



}