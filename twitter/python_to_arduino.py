# Author: Nicholas Bester
# Title: Twitter Stream connection
# Description: Tracks a string using the Twitter Streaming API
# Send commands using PySerial to an Arduino
# Version: 1.0

# imports
import time  
from time import sleep  
from TwitterAPI import TwitterAPI  
import struct  
import os  
from serial import Serial

# Pretty console colours
class bcolors:  
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

# Variables
availableArduino = True # Debugging without an Arduino  
testSerial = False # Debugging without Twitter connection  
arduinoPort = '/dev/ttyUSB0' # USB port address for the Arduino
arduinoBaud = '9600' # Baud for serial communication
arduinoWaitTime = 0.001 # The length of time Python wait before attemping to issue commands to the Arduino
stringToTrack = "@potus44" # Change this to the search term you wish to track from Twitter

# Access requirements for Twitter API connection
access_token = 'CODE'
access_token_secret = 'CODE'
consumer_key = 'CODE'
consumer_secret = 'CODE'

# Clearing the screen for aesthetic display of console statements
os.system('cls' if os.name == 'nt' else 'clear')

print bcolors.WARNING + "Initialising Twitter Stream Application" + bcolors.ENDC  
print bcolors.OKGREEN + "Initialisation OK!" + bcolors.ENDC  
print bcolors.WARNING + 'Initialising Arduino Board through Serial' + bcolors.ENDC

# Arduino serial communication
if availableArduino:  
    ser = Serial(arduinoPort, arduinoBaud, timeout=3)

# Gives the Arduino board time to initialise
sleep(arduinoWaitTime)

# Testing serial send to Arduino (ensure available Arduino is True)
if testSerial:  
    print "On"
    ser.write(bytes(1))
    sleep(arduinoWaitTime)
    print "Off"
    ser.write(bytes(0))
    sleep(arduinoWaitTime)
else:  
    print bcolors.OKGREEN + "Initialisation OK!" + bcolors.ENDC
    print bcolors.WARNING + 'Initialising Twitter Stream API Authorisation' + bcolors.ENDC

    # Setting up a connection to Twitter using the Twitter API
    api = TwitterAPI(consumer_key, consumer_secret, access_token, access_token_secret)

    print bcolors.OKGREEN + "Initialisation OK!" + bcolors.ENDC
    print bcolors.OKBLUE + 'Twitter Stream Request running' + bcolors.ENDC

    # A request object which opens a stream to Twitter tracking the hashtag in question
    r = api.request('statuses/filter', {'track':stringToTrack})

    # Checks if text within the stream item is populated and issues a command to the Arduino
    for item in r.get_iterator():
        if 'text' in item:
            print item['user']['screen_name'].encode('utf-8') + ' tweeted: ' + item['text'].encode('utf-8')# Print screen name and the tweet text

            # It is possible to check the tweets for further commands using regular expressions to send multiple commands to the Arduino but thats not illustrated in this code. 

            if availableArduino:
                print "Arduino turning on the LED"
                ser.write(bytes(1)) # The command is a simple byte intepretation of the integer 1
                sleep(arduinoWaitTime) # Wait before sending next command
                ser.write(bytes(0))
                sleep(arduinoWaitTime) # Wait before sending next command
