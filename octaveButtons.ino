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

/* V1.01 Changed LED resister value to 270 Ohm...  a little bit clearer now
   V1
   What is it? 2 Octave buttons to be added to the MIDI keyboard.  An LED is used to show octave via brightness
   implement; Serial print - Done // LED Done // LED Brightness - Done // Debounce - Done // Link to MIDI keyboard
   Buttons use 10k resistors to ground, LED uses 270 Ohm.
*/
const int  octUpButton = 2;       // Octave Up pushbutton
const int  octDwnButton = 3;      // Octave Down pushbutton
const int octLED = 5;             // LED on pin 5 (~pwm pin)
int octLED_Brightness[] = {0, 20, 65, 120, 255}; // brightness for 0,1,2,3,4 octaves
int octButtonPushCounter = 2;     // counter for the number of button presses, 2 to start in middle octave
int octUpButtonState = 0;         // current state Up button
int octDwnButtonState = 0;        // current state of Down button
int octLastButtonState = 0;       // previous state of the button

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
        delay(250);
        analogWrite(octLED, octLED_Brightness[1]);    // change LED brightness UP
        Serial.print("   + button pressed  ");
        Serial.print(octButtonPushCounter);
        Serial.print('\n');
      } else if (octButtonPushCounter == 1){          // ********  Octave 2  *******
          octButtonPushCounter++;
          delay(250);
          analogWrite(octLED, octLED_Brightness[2]);  // change LED brightness UP
          Serial.print("   + button pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print('\n');
      } else if (octButtonPushCounter == 2){          // ********  Octave 3  *******
          octButtonPushCounter++;
          delay(250);
          analogWrite(octLED, octLED_Brightness[3]);  // change LED brightness UP
          Serial.print("   + button pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print('\n');
      } else if (octButtonPushCounter == 3){          // ********  Octave 4  *******
          octButtonPushCounter++;
          delay(250);
          analogWrite(octLED, octLED_Brightness[4]);  // change LED brightness UP
          Serial.print("   + button pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print('\n');
      }   
     }
   }  
   octLastButtonState = octUpButtonState;             // save the current state as the last state, for next time through the loop  
   
   octDwnButtonState = digitalRead(octDwnButton);     // read the pushbutton down input pin:
   if (octDwnButtonState != octLastButtonState) {     // compare the buttonState to its previous state
     if (octDwnButtonState == HIGH)                   // if the state has changed, decrement the counter
     {
      if (octButtonPushCounter == 4){                 // ********  Octave 4  *******
      octButtonPushCounter--;
      delay(250);
      analogWrite(octLED, octLED_Brightness[3]);      // change LED brightness DOWN
      Serial.print("   - Button Pressed  ");
      Serial.print(octButtonPushCounter);
      Serial.print('\n');     
      } else if (octButtonPushCounter == 3){          // ********  Octave 3  *******
          octButtonPushCounter--;
          delay(250);
          analogWrite(octLED, octLED_Brightness[2]);  // change LED brightness DOWN
          Serial.print("   - Button Pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print('\n');  
      } else if (octButtonPushCounter == 2){          // ********  Octave 1  *******
          octButtonPushCounter--;
          delay(250);
          analogWrite(octLED, octLED_Brightness[1]);  // change LED brightness DOWN
          Serial.print("   - Button Pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print('\n');  
      } else if (octButtonPushCounter == 1){          // ********  Octave 0  *******
          octButtonPushCounter--;
          delay(250);
          analogWrite(octLED, octLED_Brightness[0]);  // change LED brightness DOWN
          Serial.print("   - Button Pressed  ");
          Serial.print(octButtonPushCounter);
          Serial.print('\n'); 
      }
     }           
   }
   octLastButtonState = octDwnButtonState;    
}