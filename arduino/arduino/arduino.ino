#include "HID-Project.h"

/* 	Template Document For Arduino
	Add if statements to keyboardControl for further expantion
	Example:
		if (strcmp(receivedChars, "command") == 0) {
			Keyboard.press(KEY_INPUT);
			Keyboard.release(KEY_INPUT);
        }
		Replace "command" with mqtt string
			MQTT String sent will include '<' '>' for serial decoding
		Replace 'KEY_INPUT" with keyboard key code from hid-project
			https://github.com/NicoHood/HID/blob/master/src/KeyboardLayouts/ImprovedKeylayouts.h
			
*/

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
}

void loop() {
    recvWithStartEndMarkers();
	keyboardControl();
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void keyboardControl()
{
	if (newData == true) {
		newData = false;
		
		if (strcmp(receivedChars, "cam1") == 0) {
			Keyboard.press(KEY_1);
			Keyboard.release(KEY_1);
        } else if (strcmp(receivedChars, "cam2") == 0) {
			Keyboard.press(KEY_2);
			Keyboard.release(KEY_2);
        }
}
