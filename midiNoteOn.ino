//From the book Arduino For Musicians
//Listing 5_1:  MIDI Note-on message

void setup() {
  // put your setup code here, to run once:
  //Establish standard MIDI baud rate
  Serial.begin(31250);
//  Serial.begin(115200);
  byte noteOnStatus = 144;  //Note-On message ch. 1
                            //(Hexadecimal = 0x90
  byte noteNumber = 60;     //Middle C
  byte velocity = 100;      //Velocity range from
                            //0-127

  //Output a MIDI note-on message:
  Serial.write(noteOnStatus);   //Send status byte
  Serial.write(noteNumber);     //Send data byte 1
  Serial.write(velocity);       //Send data byte 2
}

void loop() {
  // put your main code here, to run repeatedly:

}