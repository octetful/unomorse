/*
 * MorseCode
 * 
 * This is a simple morse code transmission app
 * 
 * Built by: Siddhartha Ghosh
 * Last Updated: Jun, 2017
 */

#define SERIAL_RATE 9600

// include the library code:
#include "Lewis.h"

const int outPin = 13; // connect an LED to this pin on arduino board
const int wordRate = 20; // Words per minute rate
const int serialInPin = 2; // Fake
String data;
Lewis Morse;

void setup() {
  Serial.begin(SERIAL_RATE); // Sets the baud rate for the serial transmission
  pinMode(outPin, OUTPUT); // sets the LED port to output mode
  Morse.begin(serialInPin, outPin, wordRate, false); // no interrupt = false
  Serial.println("Send message to morse encode: ");
}

void loop() {
    if (Serial.available() > 0) {
      data = Serial.readString();
      Serial.println("RECIEVED: " + data);
      Serial.println("Beeping morse signal NOW");
      for (int i = 0; i < data.length(); i++) {
        if ( data[i] >= 32 && data[i] <=126 ) {
          Morse.write(data[i]);   
        }
      }
      Morse.flush();
    }
}
