"# midiNoteOn" 

MIDI note on

![Arduino Midi Keyboard new version](newKeys.jpg)

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