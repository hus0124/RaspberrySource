import RPi.GPIO as GPIO

TiltPin = 40
Bpin = 36
Rpin = 38

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setwarnings(False)
    GPIO.setup(Bpin, GPIO.OUT)
    GPIO.setup(Rpin, GPIO.OUT)
    GPIO.setup(TiltPin, GPIO.IN, pull_up_down = GPIO.PUD_UP)
    GPIO.add_event_detect(TiltPin, GPIO.BOTH, callback = detect, bouncetime=200)
    print('tiltSensor.py on now')

def Led(x) :
    if x == 0 :
        GPIO.output(Bpin, 1)    
        GPIO.output(Rpin, 0)
    if x == 1 :
        GPIO.output(Bpin, 0)
        GPIO.output(Rpin, 1)

def Print(x) :
    if x == 0 :
        print('    ***********')
        print('    *  Tilt!  *')
        print('    ***********')
    if x == 1 :
        print('Rpin on')    

def detect(chn) :
    Led(GPIO.input(TiltPin))
    Print(GPIO.input(TiltPin))

def loop() :
    while True :
        pass

def destroy() :
    GPIO.output(Bpin, GPIO.HIGH)
    GPIO.output(Rpin, GPIO.HIGH)
    GPIO.cleanup()

if __name__ == '__main__' :
    setup()

    try :
        loop()
    except KeyboardInterrupt :
        destroy()    