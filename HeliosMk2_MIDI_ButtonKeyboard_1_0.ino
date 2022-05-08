//           _     _ _                   _                         _  
// _ __ ___ (_) __| (_)   /\ /\___ _   _| |__   ___   __ _ _ __ __| | 
//| '_ ` _ \| |/ _` | |  / //_/ _ \ | | | '_ \ / _ \ / _` | '__/ _` | 
//| | | | | | | (_| | | / __ \  __/ |_| | |_) | (_) | (_| | | | (_| | 
//|_| |_| |_|_|\__,_|_| \/  \/\___|\__, |_.__/ \___/ \__,_|_|  \__,_| 
//                                 |___/                            
/*  Helios MK2 MIDI button Keyboard
 *  08/05/2022
 *  V1.0 Basic Keyboard working
 *
 *  To DO:
 *  Add - Octave Buttons
 *  Add - Arp
 *  Optimise code
 * 
    Remember: Analog pins as digital - you can't use A6 0r A7

    Much of the inspiration of this code comes from this article;
    https://create.arduino.cc/projecthub/gleberruyer/midi-wood-keyboard-88053e

    Button setup from this article:
    https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button

    Ascii text from: http://patorjk.com/ using 'Ogre' font

    MIDI Note numbers:
    octave  C   C#  D   D#  E   F   F#  G   G#  A   A#  B
        1   36  37  38  39  40  41  42  43  44  45  46  47
        2   48  49  50  51  52  53  54  55  56  57  58  59
        3   60  61  62  63  64  65  66  67  68  69  70  71
        4   72  73  74  75  76  77  78  79  80  81  82  83
        5   84  85  86  87  88  89  90  91  92  93  94  95
*/

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

int button1_LowC_pin = 2;    // Low C digital pin 2
int button2_Csharp_pin = 3;  // C#  - digital pin 3
int button3_D_pin = 4;       // D   - digital pin 4
int button4_Dsharp_pin = 5;  // D#  - digital pin 5
int button5_E_pin = 6;       // E   - digital pin 6
int button6_F_pin = 7;       // F   - digital pin 7
int button7_Fsharp_pin = 8;  // F#  - digital pin 8
int button8_G_pin = 9;       // G   - digital pin 9
int button9_Gsharp_pin = 10; // G#  - digital pin 10
int button10_A_pin = 11;     // A   - digital pin 11
int button11_Asharp_pin = 12; // A# - digital pin 12
int button12_B_pin = 13;      // B  - digital pin 12
int button13_C_pin = A0;      // C  - analogue pin A0
int midiChannel = 1;

void setup() {
  MIDI.begin ();
  pinMode(button1_LowC_pin, INPUT);
  pinMode(button2_Csharp_pin, INPUT);
  pinMode(button3_D_pin, INPUT);
  pinMode(button4_Dsharp_pin, INPUT);
  pinMode(button5_E_pin, INPUT);
  pinMode(button6_F_pin, INPUT);
  pinMode(button7_Fsharp_pin, INPUT);
  pinMode(button8_G_pin, INPUT);
  pinMode(button9_Gsharp_pin, INPUT);
  pinMode(button10_A_pin, INPUT);
  pinMode(button11_Asharp_pin, INPUT);
  pinMode(button12_B_pin, INPUT);
  pinMode(button13_C_pin, INPUT);
  Serial.begin(31250);
}

void loop() {
                                 
  static bool button1_LowC_valueOld = LOW;
  static bool button2_Csharp_valueOld = LOW;
  static bool button3_D_valueOld = LOW;
  static bool button4_Dsharp_valueOld = LOW;
  static bool button5_E_valueOld = LOW;
  static bool button6_F_valueOld = LOW;
  static bool button7_Fsharp_valueOld = LOW;
  static bool button8_G_valueOld = LOW;
  static bool button9_Gsharp_valueOld = LOW;
  static bool button10_A_valueOld = LOW;
  static bool button11_Asharp_valueOld = LOW;
  static bool button12_B_valueOld = LOW;
  static bool button13_C_valueOld = LOW;
  
  bool button1_LowC_valueNew = digitalRead(button1_LowC_pin);
  bool button2_Csharp_valueNew = digitalRead(button2_Csharp_pin);
  bool button3_D_valueNew = digitalRead(button3_D_pin);
  bool button4_Dsharp_valueNew = digitalRead(button4_Dsharp_pin);
  bool button5_E_valueNew = digitalRead(button5_E_pin);
  bool button6_F_valueNew = digitalRead(button6_F_pin);
  bool button7_Fsharp_valueNew = digitalRead(button7_Fsharp_pin);
  bool button8_G_valueNew = digitalRead(button8_G_pin);
  bool button9_Gsharp_valueNew = digitalRead(button9_Gsharp_pin);
  bool button10_A_valueNew = digitalRead(button10_A_pin);
  bool button11_Asharp_valueNew = digitalRead(button11_Asharp_pin);
  bool button12_B_valueNew = digitalRead(button12_B_pin);
  bool button13_C_valueNew = digitalRead(button13_C_pin);
  
      ////////////////// Low C //////////////    
    if (button1_LowC_valueNew != button1_LowC_valueOld){
      if (button1_LowC_valueNew == HIGH){
      MIDI.sendNoteOn(48, 127, midiChannel); // "Note low C On"
      delay(60);
      } else {
      MIDI.sendNoteOff(48, 0, midiChannel); // "Note low C off"
      delay(60);
      }  
      button1_LowC_valueOld = button1_LowC_valueNew;
    }
    
      ////////////////// C Sharp //////////////    
    if (button2_Csharp_valueNew != button2_Csharp_valueOld){ 
      if (button2_Csharp_valueNew == HIGH){  
      MIDI.sendNoteOn(49, 127, 1); //  "Note C sharp On"
      } else {
      MIDI.sendNoteOff(49, 0, 1); //"Note C Sharp Off"
      }
      button2_Csharp_valueOld = button2_Csharp_valueNew;
    }

      ////////////////// D //////////////    
    if (button3_D_valueNew != button3_D_valueOld){ 
      if (button3_D_valueNew == HIGH){  
      MIDI.sendNoteOn(50, 127, 1); //  "Note D On"
      } else {
      MIDI.sendNoteOff(50, 0, 1); //"Note D Off"
      }
      button3_D_valueOld = button3_D_valueNew;
    }

       ////////////////// D sharp //////////////    
    if (button4_Dsharp_valueNew != button4_Dsharp_valueOld){ 
      if (button4_Dsharp_valueNew == HIGH){  
      MIDI.sendNoteOn(51, 127, 1); //  "Note D# On"
      } else {
      MIDI.sendNoteOff(51, 0, 1); //"Note D# Off"
      }
      button4_Dsharp_valueOld = button4_Dsharp_valueNew;
    }

       ////////////////// E //////////////    
    if (button5_E_valueNew != button5_E_valueOld){ 
      if (button5_E_valueNew == HIGH){  
      MIDI.sendNoteOn(52, 127, 1); //  "Note E On"
      } else {
      MIDI.sendNoteOff(52, 0, 1); //"Note E Off"
      }
      button5_E_valueOld = button5_E_valueNew;
    }

       ////////////////// F //////////////    
    if (button6_F_valueNew != button6_F_valueOld){ 
      if (button6_F_valueNew == HIGH){  
      MIDI.sendNoteOn(53, 127, 1); //  "Note F On"
      } else {
      MIDI.sendNoteOff(53, 0, 1); //"Note F Off"
      }
      button6_F_valueOld = button6_F_valueNew;
    }

      ////////////////// F# //////////////    
    if (button7_Fsharp_valueNew != button7_Fsharp_valueOld){ 
      if (button7_Fsharp_valueNew == HIGH){  
      MIDI.sendNoteOn(54, 127, 1); //  "Note F# On"
      } else {
      MIDI.sendNoteOff(54, 0, 1); //"Note F# Off"
      }
      button7_Fsharp_valueOld = button7_Fsharp_valueNew;
    }

       ////////////////// G //////////////    
    if (button8_G_valueNew != button8_G_valueOld){ 
      if (button8_G_valueNew == HIGH){  
      MIDI.sendNoteOn(55, 127, 1); //  "Note G On"
      } else {
      MIDI.sendNoteOff(55, 0, 1); //"Note G Off"
      }
      button8_G_valueOld = button8_G_valueNew;
    }

      ////////////////// G# //////////////    
    if (button9_Gsharp_valueNew != button9_Gsharp_valueOld){ 
      if (button9_Gsharp_valueNew == HIGH){  
      MIDI.sendNoteOn(56, 127, 1); //  "Note G# On"
      } else {
      MIDI.sendNoteOff(56, 0, 1); //"Note G# Off"
      }
      button9_Gsharp_valueOld = button9_Gsharp_valueNew;
    }

      ////////////////// A //////////////    
    if (button10_A_valueNew != button10_A_valueOld){ 
      if (button10_A_valueNew == HIGH){  
      MIDI.sendNoteOn(57, 127, 1); //  "Note A On"
      } else {
      MIDI.sendNoteOff(57, 0, 1); //"Note A Off"
      }
      button10_A_valueOld = button10_A_valueNew;
    }

      ////////////////// A# //////////////    
    if (button11_Asharp_valueNew != button11_Asharp_valueOld){ 
      if (button11_Asharp_valueNew == HIGH){  
      MIDI.sendNoteOn(58, 127, 1); //  "Note A# On"
      } else {
      MIDI.sendNoteOff(58, 0, 1); //"Note A# Off"
      }
      button11_Asharp_valueOld = button11_Asharp_valueNew;
    }

      ////////////////// B //////////////    
    if (button12_B_valueNew != button12_B_valueOld){ 
      if (button12_B_valueNew == HIGH){  
      MIDI.sendNoteOn(59, 127, 1); //  "Note B On"
      } else {
      MIDI.sendNoteOff(59, 0, 1); //"Note B Off"
      }
      button12_B_valueOld = button12_B_valueNew;
    }

      ////////////////// C //////////////    
    if (button13_C_valueNew != button13_C_valueOld){ 
      if (button13_C_valueNew == HIGH){  
      MIDI.sendNoteOn(60, 127, 1); //  "Note C On"
      } else {
      MIDI.sendNoteOff(60, 0, 1); //"Note F Off"
      }
      button13_C_valueOld = button13_C_valueNew;
    }
    
}