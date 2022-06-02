import paho.mqtt.client as mqtt
import serial
import time

# Update to match com port and baud rate
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    # Topic to listen to on for actions
    client.subscribe("camdisplay/livingroom/keyboard")

def on_message(client, userdata, msg):
    print("MQTT: "+msg.topic+" "+str(msg.payload))
    send = msg.payload.decode("utf-8")
    arduino.write(msg.payload)

def write_read(x):
    arduino.write(x)
    time.sleep(0.05)
    data = arduino.readline()
    print(data)
    print("Arduino End")
    
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

# Update to match server settings
client.connect("192.168.30.11", 1883, 60)

while True:
    serialData = arduino.readline()[:-2]
    if serialData:
        print("Arduino: "+str(serialData))
    client.loop_start()

