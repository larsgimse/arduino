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


availableArduino = True  
testSerial = False  
arduinoPort = '/dev/ttyUSB0' 
arduinoBaud = '9600' 
arduinoWaitTime = 0.001 
stringToTrack = '#testing1234'
stringToTrack_sub = '#testing5678'
t = 1

from auth_romforlek import (
    consumer_key,
    consumer_secret,
    access_token,
    access_token_secret
)

print 'Initialising Twitter Stream Application' 
print 'Initialisation OK!'
print 'Initialising Arduino Board through Serial'

if availableArduino:  
    ser = Serial(arduinoPort, arduinoBaud, timeout=3)

sleep(arduinoWaitTime)

if testSerial:  
    print "On"
    ser.write(bytes(1))
    sleep(arduinoWaitTime)
    print "Off"
    ser.write(bytes(0))
    sleep(arduinoWaitTime)
else:  
    print 'Initialisation OK!'
    print 'Initialising Twitter Stream API Authorisation'

    api = TwitterAPI(consumer_key, consumer_secret, access_token, access_token_secret)

    print 'Initialisation OK!'
    print 'Twitter Stream Request running'
    print '----'
    print 'Ready for tweets >>'

    r = api.request('statuses/filter', {'track':stringToTrack})

    for item in r.get_iterator():
        if 'text' in item:
            print item['user']['screen_name'].encode('utf-8') + ' tweeted: ' + item['text'].encode('utf-8')
            tweet = item['text'].encode('utf-8')
            if stringToTrack_sub in tweet.split():   
#            if availableArduino:
                print '----'
                print 'Arduino turning on the LED: ',t
                print '----'
                ser.write(bytes(1))
                sleep(arduinoWaitTime)
                ser.write(bytes(0))
                sleep(arduinoWaitTime)
                t = t + 1
