#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// Uncomment the following line to enable the whammy feature
#define ENABLE_WHAMMY
#ifdef ENABLE_WHAMMY
    // Define the pin for the whammy feature
    #define WHAMMY_PIN 9
#endif

// Analog pins
#define TILT 10

// Uncomment the following line to enable the six-fret configuration
// #define IS_SIX_FRET
#ifndef IS_SIX_FRET
    // Color frets for six-fret configuration
    #define GREEN 2
    #define RED 3
    #define YELLOW 4
    #define BLUE 5
    #define ORANGE 6
#endif

#ifdef IS_SIX_FRET
    #define BLACK_1 2
    #define BLACK_2 3
    #define BLACK_3 4
    #define WHITE_1 5
    #define WHITE_2 6
    #define WHITE_3 7
#endif

// Strum
#define STRUM_UP 7
#define STRUM_DOWN 8

// Menu buttons
#define START 21
#define SELECT 20
#define SUPER_BUTTON 19

// Uncomment the following line to enable the D-pad buttons
#define ENABLE_DPAD
#ifdef ENABLE_DPAD
    // D-pad buttons
    #define D_UP 18
    #define D_DOWN 15
    #define D_LEFT 14
    #define D_RIGHT 16
#endif

#endif
