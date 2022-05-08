/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  9;      // the number of the LED pin
const int ledPin =  13;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(31250);  //set up serial output with MIDI baud rate
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    for(int note = 60; note < 60 + 12 ; note++) {
    //play a note
    playMIDINote(1, note, 100);
    //pause
    delay(60);

    //Turn note off (velocity = 0)
    playMIDINote(1, note, 0);
    //pause
    delay(60);
  }
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    playMIDINote(1, 60, 0);
    delay(60);
  }
}

void playMIDINote(byte channel, byte note, byte velocity) {
  byte noteOnStatus=0x90 + (channel-1); // MIDI channels
  // 1-16 are really 0-15
  //send notes to MIDI output:
  Serial.write(noteOnStatus);
  Serial.write(note);
  Serial.write(velocity);  
}