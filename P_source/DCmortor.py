import RPi.GPIO as GPIO
import time

FAN_IA = 23 #physic 16
FAN_IB = 24 #physic 18

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(FAN_IA, GPIO.OUT)
GPIO.setup(FAN_IB, GPIO.OUT)

def LeftRotate() :
    GPIO.output(FAN_IA, True)
    GPIO.output(FAN_IB, False)
    time.sleep(4)

def RightRotate() :
    GPIO.output(FAN_IB, True)
    GPIO.output(FAN_IA, False)
    time.sleep(4)

def WaitRotate() :
    GPIO.output(FAN_IA, False)
    GPIO.output(FAN_IB, False)
    time.sleep(2)


if __name__ == "__main__" :
    try :
        while True :
            LeftRotate()
            WaitRotate()
            RightRotate()
            WaitRotate()

    except :
        GPIO.cleanup()
        print("end")
