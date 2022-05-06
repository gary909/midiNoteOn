//From the book Arduino For Musicians
//Listing 5_4:  Basic MIDI output

void setup() {
  Serial.begin(31250);  //set up serial output with MIDI baud rate
}

void loop() {
  // Play a chromatic scale starting on middle C (60)
  for(int note = 60; note < 60; note++) {
    //play a note
    playMIDINote(1, note, 100);
    //pause
    delay(60);

    //Turn note off (velocity = 0)
    playMIDINote(1, note, 0);
    //pause
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