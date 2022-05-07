// listing 5.5
// Aleatoric Music Generator

void setup() {
  Serial.begin(31250);  //set up serial output with MIDI baud rate
  // use Analog 0 to seed the random number generator
  randomSeed(analogRead(0));
}

void loop() {
  // select random parameters:
  byte note=random(20, 100);
  int duration=random(10, 1000);
  byte velocity=random(40, 127);

  //Play the note with the given parameters:
  playMIDINote(1, note, velocity);
  delay(duration);

  //Turn MIDI note off
  playMIDINote(1, note, 0);
  delay(10);
}

void playMIDINote(byte channel, byte note, byte velocity)
{
  byte noteOnStatus=0x90 + (channel - 1); //midi channels

  //send notes to MIDI output
  Serial.write(noteOnStatus);
  Serial.write(note);
  Serial.write(velocity);
}
