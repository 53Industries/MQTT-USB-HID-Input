# MQTT-USB-HID-Input
Arduino Leonardo HID Input with MQTT Control

Project was inspired from the need to control camplayer for raspberry pi, from home assistant.
Since camplayer runs in the termial the methods of input with python I tried would not work. An active
X Server was required or the key press would not be picked up from camplayer. 

Using a Arduino Leonardo and a python script MQTT mesages are recieved and sent to Arduino which then sends
HID Input commands back to the connected computer.

Should work on any os with python support.

- MQTT MSG to sent inside of '<' '>' for serial decoding.
- Can be run as a service on linux using example service file

Home Assistant custom button card example
```
type: custom:button-card
tap_action:
  action: call-service
  service: mqtt.publish
  service_data:
    topic: <TOPIC GOES HERE>
    payload: <PAYLOAD GOES HERE>
```	

# Python
Python Version
- 2.7.9+
- 3.6+
	
Libraries
- https://pypi.org/project/paho-mqtt/
- https://pypi.org/project/pyserial/
	
Update the python script to match system and server settings
- arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1) (Update port and baudrate)
- client.subscribe("camdisplay/office/keyboard") (Topic the scirpt will listen on)
- client.connect("127.0.0.1", 1883, 60) (MQTT Server Settings)

# Arduino
Supported Boards
- https://github.com/NicoHood/HID
	
Keyboard Key Definitions 
- https://github.com/NicoHood/HID/blob/master/src/KeyboardLayouts/ImprovedKeylayouts.h
- https://github.com/NicoHood/HID/tree/master/src/HID-APIs
	
