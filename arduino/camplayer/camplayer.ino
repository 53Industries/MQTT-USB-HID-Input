/* 	Example for camplayer for Raspberry Pi

	https://www.rpi-camplayer.com/ Camplayer Main Page
	https://www.rpi-camplayer.com/docs/control/ Control Information
	
*/
	
#include "HID-Project.h"

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
}

void loop() {
    recvWithStartEndMarkers();
    //showNewData();
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
        } else if (strcmp(receivedChars, "cam3") == 0) {
			Keyboard.press(KEY_3);
			Keyboard.release(KEY_3);
        } else if (strcmp(receivedChars, "cam4") == 0) {
			Keyboard.press(KEY_4);
			Keyboard.release(KEY_4);
        } else if (strcmp(receivedChars, "cam5") == 0) {
			Keyboard.press(KEY_5);
			Keyboard.release(KEY_5);
        } else if (strcmp(receivedChars, "cam6") == 0) {
			Keyboard.press(KEY_6);
			Keyboard.release(KEY_6);
        } else if (strcmp(receivedChars, "cam7") == 0) {
			Keyboard.press(KEY_7);
			Keyboard.release(KEY_7);
        } else if (strcmp(receivedChars, "cam8") == 0) {
			Keyboard.press(KEY_8);
			Keyboard.release(KEY_8);
        } else if (strcmp(receivedChars, "cam9") == 0) {
			Keyboard.press(KEY_9);
			Keyboard.release(KEY_9);
        } else if (strcmp(receivedChars, "qdow") == 0) {
			Keyboard.press(KEY_DOWN);
			Keyboard.release(KEY_DOWN);
        } else if (strcmp(receivedChars, "qup") == 0) {
			Keyboard.press(KEY_UP);
			Keyboard.release(KEY_UP);
        } else if (strcmp(receivedChars, "clef") == 0) {
			Keyboard.press(KEY_LEFT);
			Keyboard.release(KEY_LEFT);
        } else if (strcmp(receivedChars, "crig") == 0) {
			Keyboard.press(KEY_RIGHT);
			Keyboard.release(KEY_RIGHT);
        } else if (strcmp(receivedChars, "back") == 0) {
			Keyboard.press(KEY_ESC);
			Keyboard.release(KEY_ESC);
        } else if (strcmp(receivedChars, "paus") == 0) {
			Keyboard.press(KEYPAD_SPACE);
			Keyboard.release(KEYPAD_SPACE);
        } else if (strcmp(receivedChars, "grid") == 0) {
			Keyboard.press(KEY_ENTER);
			Keyboard.release(KEY_ENTER);
        } else if (strcmp(receivedChars, "quit") == 0) {
			Keyboard.press(KEY_Q);
			Keyboard.release(KEY_Q);
        }
	}
}

