/* 	Example for camplayer for Raspberry Pi with IR support

	https://www.rpi-camplayer.com/ Camplayer Main Page
	https://www.rpi-camplayer.com/docs/control/ Control Information
	(Samsung Remote)
*/
#include "HID-Project.h"
#include <IRremote.hpp>
#define IR_RECEIVE_PIN          10

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
      IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
    recvWithStartEndMarkers();
	keyboardControlMQTT();
	if (IrReceiver.decode()) {
		 //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      //IrReceiver.printIRResultShort(&Serial);
		keyboardControlIR();
	}
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

void keyboardControlMQTT()
{
	if (newData == true) {
		newData = false;
		
		if (strcmp(receivedChars, "cam1") == 0) {
			keyboardControl(1);
        } else if (strcmp(receivedChars, "cam2") == 0) {
			keyboardControl(2);
        } else if (strcmp(receivedChars, "cam3") == 0) {
			keyboardControl(3);
        } else if (strcmp(receivedChars, "cam4") == 0) {
			keyboardControl(4);
        } else if (strcmp(receivedChars, "cam5") == 0) {
			keyboardControl(5);
        } else if (strcmp(receivedChars, "cam6") == 0) {
			keyboardControl(6);
        } else if (strcmp(receivedChars, "cam7") == 0) {
			keyboardControl(7);
        } else if (strcmp(receivedChars, "cam8") == 0) {
			keyboardControl(8);
        } else if (strcmp(receivedChars, "cam9") == 0) {
			keyboardControl(9);
        } else if (strcmp(receivedChars, "qdow") == 0) {
			keyboardControl(10);
        } else if (strcmp(receivedChars, "qup") == 0) {
			keyboardControl(11);;
        } else if (strcmp(receivedChars, "clef") == 0) {
			keyboardControl(12);
        } else if (strcmp(receivedChars, "crig") == 0) {
			keyboardControl(13);
        } else if (strcmp(receivedChars, "back") == 0) {
			keyboardControl(14);
        } else if (strcmp(receivedChars, "paus") == 0) {
			keyboardControl(15);
        } else if (strcmp(receivedChars, "grid") == 0) {
			keyboardControl(16);
        } else if (strcmp(receivedChars, "quit") == 0) {
			keyboardControl(17);
        }
	}
}

void keyboardControlIR()
{
	if (IrReceiver.decodedIRData.command == 0x4) {
		keyboardControl(1);
	} else if (IrReceiver.decodedIRData.command == 0x5) {
		keyboardControl(2);
	} else if (IrReceiver.decodedIRData.command == 0x6) {
		keyboardControl(3);
	} else if (IrReceiver.decodedIRData.command == 0x8) {
		keyboardControl(4);
	} else if (IrReceiver.decodedIRData.command == 0x9) {
		keyboardControl(5);;
	} else if (IrReceiver.decodedIRData.command == 0xA) {
		keyboardControl(6);
	} else if (IrReceiver.decodedIRData.command == 0xC) {
		keyboardControl(7);
	} else if (IrReceiver.decodedIRData.command == 0xD) {
		keyboardControl(8);
	} else if (IrReceiver.decodedIRData.command == 0xE) {
		keyboardControl(9);
	} else if (IrReceiver.decodedIRData.command == 0x61) {
		keyboardControl(10);
	} else if (IrReceiver.decodedIRData.command == 0x60) {
		keyboardControl(11);
	} else if (IrReceiver.decodedIRData.command == 0x65) {
		keyboardControl(12);
	} else if (IrReceiver.decodedIRData.command == 0x62) {
		keyboardControl(13);
	} else if (IrReceiver.decodedIRData.command == 0x58) {
		keyboardControl(14);
	} else if (IrReceiver.decodedIRData.command == 0x6B) {
		keyboardControl(15);
	} else if (IrReceiver.decodedIRData.command == 0x2D) {
		keyboardControl(16);
	} else if (IrReceiver.decodedIRData.command == 0x68) {
		keyboardControl(17);
	}
 delay(100);
 IrReceiver.resume();
}

void keyboardControl(int key)
{
	if (key == 1) {
		Keyboard.press(KEY_1);
		release();
		Serial.println("Key Pressed 1");
	} else if (key == 2) {
		Keyboard.press(KEY_2);
		release();
		Serial.println("Key Pressed 2");
	} else if (key == 3) {
		Keyboard.press(KEY_3);
		release();
		Serial.println("Key Pressed 3");
	} else if (key == 4) {
		Keyboard.press(KEY_4);
		release();
		Serial.println("Key Pressed 4");
	} else if (key == 5) {
		Keyboard.press(KEY_5);
		release();
		Serial.println("Key Pressed 5");
	} else if (key == 6) {
		Keyboard.press(KEY_6);
		release();
		Serial.println("Key Pressed 6");
	} else if (key == 7) {
		Keyboard.press(KEY_7);
		release();
		Serial.println("Key Pressed 7");
	} else if (key == 8) {
		Keyboard.press(KEY_8);
		release();
		Serial.println("Key Pressed 8");
	} else if (key == 9) {
		Keyboard.press(KEY_9);
		release();
		Serial.println("Key Pressed 9");
	} else if (key == 10) {
		Keyboard.press(KEY_DOWN);
		release();
		Serial.println("Key Pressed DOWN");
	} else if (key == 11) {
		Keyboard.press(KEY_UP);
		release();
		Serial.println("Key Pressed UP");
	} else if (key == 12) {
		Keyboard.press(KEY_LEFT);
		release();
		Serial.println("Key Pressed LEFT");
	} else if (key == 13) {
		Keyboard.press(KEY_RIGHT);
		release();
		Serial.println("Key Pressed RIGHT");
	} else if (key == 14) {
		Keyboard.press(KEY_ESC);
		release();
		Serial.println("Key Pressed ESC");
	} else if (key == 15) {
		Keyboard.press(KEY_SPACE);
		release();
		Serial.println("Key Pressed SPACE");
	} else if (key == 16) {
		Keyboard.press(KEY_Q);
		release();
		Serial.println("Key Pressed Quit");
	} else if (key == 17) {
		Keyboard.press(KEY_ENTER);
		release();
		Serial.println("Key Pressed ENTER");
	}
}

void release()
{
	delay(15);
	Keyboard.releaseAll();
}
