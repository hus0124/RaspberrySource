import RPi.GPIO as GPIO
import time

LED1 = 18
LED2 = 17
LED3 = 27
LED4 = 22
LED5 = 23

LED = [LED1, LED2, LED3, LED4, LED5]
delay = 0.1

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

for i in LED :
    GPIO.setup(i, GPIO.OUT)
    
try :
    while True :
        for i in LED :
            GPIO.output(i, True)
            time.sleep(delay)
            GPIO.output(i, False)
            delay -= 0.001
            if delay <= 0:
                delay = 0.1
except :
    GPIO.cleanup()
    print("end")
        
