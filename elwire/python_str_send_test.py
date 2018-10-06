from serial import Serial
from time import sleep

arduinoPort = '/dev/tty.usbmodem1421' # USB port address for the arduino /dev/ttyACM0 or COM5 or similar
arduinoBaud = '115200' # Baud for serial communication

ser = Serial(arduinoPort, arduinoBaud, timeout=3)



while True:
    trigger = input("trigger: ")
    #ser.write(str.encode(trigger + "\n"))
    ser.write(str.encode(trigger))
    print(trigger)
    #sleep(1)
