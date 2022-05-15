/*
  ___     __ ______   ____  __ __    ___          
 /   \   /  ]      | /    ||  |  |  /  _]         
|     | /  /|      ||  o  ||  |  | /  [_          
|  O  |/  / |_|  |_||     ||  |  ||    _]         
|     /   \_  |  |  |  _  ||  :  ||   [_          
|     \     | |  |  |  |  | \   / |     |         
 \___/ \____| |__|  |__|__|  \_/  |_____|         
                                                  
 ____   __ __  ______  ______   ___   ____   _____
|    \ |  |  ||      ||      | /   \ |    \ / ___/
|  o  )|  |  ||      ||      ||     ||  _  (   \_ 
|     ||  |  ||_|  |_||_|  |_||  O  ||  |  |\__  |
|  O  ||  :  |  |  |    |  |  |     ||  |  |/  \ |
|     ||     |  |  |    |  |  |     ||  |  |\    |
|_____| \__,_|  |__|    |__|   \___/ |__|__| \___|
                                                  
 */

/* V1.02 added MIDI octaveselected[] array to help add to midi keyboard code. Tip: instead
 *  of octaveSelected[0][0] use octaveSelected[octButtonPushCounter][0]
 * V1.01 Changed LED resister value to 270 Ohm...  a little bit clearer now
   V1
   What is it? 2 Octave buttons to be added to the MIDI keyboard.  An LED is used to show octave via brightness
   implement; Serial print - Done // LED Done // LED Brightness - Done // Debounce - Done // Link to MIDI keyboard
   Buttons use 10k resistors to ground, LED uses 270 Ohm.
*/
const int  octUpButton = 2;       // Octave Up pushbutton
const int  octDwnButton = 3;      // Octave Down pushbutton
const int octLED = 5;             // LED on pin 5 (~pwm pin)
const int octLED_Brightness[] = {0, 20, 65, 120, 255}; // brightness for 0,1,2,3,4 octaves
int octButtonPushCounter = 2;     // counter for the number of button presses, 2 to start in middle octave
int octUpButtonState = 0;         // current state Up button
int octDwnButtonState = 0;        // current state of Down button
int octLastButtonState = 0;       // previous state of the button

/*
    MIDI Note numbers:
    octave  C   C#  D   D#  E   F   F#  G   G#  A   A#  B
        1   36  37  38  39  40  41  42  43  44  45  46  47
        2   48  49  50  51  52  53  54  55  56  57  58  59
        3   60  61  62  63  64  65  66  67  68  69  70  71
        4   72  73  74  75  76  77  78  79  80  81  82  83
        5   84  85  86  87  88  89  90  91  92  93  94  95
*/
const int octaveSelected[][12] = {
  {36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47},  // Octave 0
  {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59},   // Octave 1
  {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71},   // Octave 2
  {72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83},   // Octave 3
  {84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95}    // Octave 4
};

/*
const int octaveSelected0[] = {36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};  // Octave 0
const int octaveSelected1[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};  // Octave 1
const int octaveSelected2[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71};  // Octave 2
const int octaveSelected3[] = {72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83};  // Octave 3
const int octaveSelected4[] = {84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95};  // Octave 4

int currentOctave[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71};
*/


void setup() {
   pinMode(octUpButton, INPUT);   // initialize the button pin as a input:
   pinMode(octDwnButton, INPUT);
   pinMode(octLED, OUTPUT);       // Set the LED pin as an output
   analogWrite(octLED, octLED_Brightness[1]);    // Start LED brightness in middle
   Serial.begin(9600);            // For monitoring... delete all instances later
 }
 
void loop() {
   octUpButtonState = digitalRead(octUpButton);       // read the pushbutton up input pin:  
   if (octUpButtonState != octLastButtonState) {      // compare the buttonState to its previous state
     if (octUpButtonState == HIGH)                    // if the state has changed, increment the counter  
     {
      if (octButtonPushCounter == 0){                 // ********  Octave 1  *******
        octButtonPushCounter++;
        octaveSelected[1][0];
        delay(250);
        analogWrite(octLED, octLED_Brightness[1]);    // change LED brightness UP
        Serial.print("   + button pressed  ");
        Serial.print(octButtonPushCounter);
        Serial.print("    Octave Selected: ");
        Serial.print(octaveSelected[1][0]);
        Serial.print('\n');
      } else if (octButtonPushCounter == 1){          // ********  Octave 2  *******
          octButtonPushCounter++;
          octaveSelected[2][0];
          delay(250);
          analogWrite(octLED, octLED_Brightness[2]);  // change LED brightness UP
          Serial.print("   + button pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print("    Octave Selected: ");
          Serial.print(octaveSelected[2][0]);
          Serial.print('\n');
      } else if (octButtonPushCounter == 2){          // ********  Octave 3  *******
          octButtonPushCounter++;
          octaveSelected[3][0];
          delay(250);
          analogWrite(octLED, octLED_Brightness[3]);  // change LED brightness UP
          Serial.print("   + button pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print("    Octave Selected: ");
          Serial.print(octaveSelected[3][0]);
          Serial.print('\n');
      } else if (octButtonPushCounter == 3){          // ********  Octave 4  *******
          octButtonPushCounter++;
          octaveSelected[4][0];
          delay(250);
          analogWrite(octLED, octLED_Brightness[4]);  // change LED brightness UP
          Serial.print("   + button pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print("    Octave Selected: ");
          Serial.print(octaveSelected[4][0]);
          Serial.print('\n');
      }   
     }
   }  
   octLastButtonState = octUpButtonState;             // save the current state as the last state, for next time through the loop  
   
   octDwnButtonState = digitalRead(octDwnButton);     // read the pushbutton down input pin:
   if (octDwnButtonState != octLastButtonState) {     // compare the buttonState to its previous state
     if (octDwnButtonState == HIGH)                   // if the state has changed, decrement the counter
     {
      if (octButtonPushCounter == 4){                 // ********  Octave 3  *******
      octButtonPushCounter--;
      octaveSelected[3][0];
      delay(250);
      analogWrite(octLED, octLED_Brightness[3]);      // change LED brightness DOWN
      Serial.print("   - Button Pressed  ");
      Serial.print(octButtonPushCounter);
      Serial.print("    Octave Selected: ");
      Serial.print(octaveSelected[0][0]);
      Serial.print('\n');     
      } else if (octButtonPushCounter == 3){          // ********  Octave 2  *******
          octButtonPushCounter--;
          octaveSelected[2][0];
          delay(250);
          analogWrite(octLED, octLED_Brightness[2]);  // change LED brightness DOWN
          Serial.print("   - Button Pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print("    Octave Selected: ");
          Serial.print(octaveSelected[0][0]);
          Serial.print('\n');  
      } else if (octButtonPushCounter == 2){          // ********  Octave 1  *******
          octButtonPushCounter--;
          octaveSelected[1][0];
          delay(250);
          analogWrite(octLED, octLED_Brightness[1]);  // change LED brightness DOWN
          Serial.print("   - Button Pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print("    Octave Selected: ");
          Serial.print(octaveSelected[0][0]);
          Serial.print('\n');  
      } else if (octButtonPushCounter == 1){          // ********  Octave 0  *******
          octButtonPushCounter--;
          octaveSelected[0][0];
          delay(250);
          analogWrite(octLED, octLED_Brightness[0]);  // change LED brightness DOWN
          Serial.print("   - Button Pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print("    Octave Selected: ");
          Serial.print(octaveSelected[0][0]);
          Serial.print('\n'); 
      }
     }           
   }
   octLastButtonState = octDwnButtonState;    
}