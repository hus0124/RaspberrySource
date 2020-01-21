import time

def LeftRotate(GPIO, FAN_IA, FAN_IB) :
    GPIO.output(FAN_IA, True)
    GPIO.output(FAN_IB, False)
    time.sleep(4)

def RightRotate(GPIO, FAN_IA, FAN_IB) :
    GPIO.output(FAN_IB, True)
    GPIO.output(FAN_IA, False)
    time.sleep(4)

def WaitRotate(GPIO, FAN_IA, FAN_IB) :
    GPIO.output(FAN_IA, False)
    GPIO.output(FAN_IB, False)
    time.sleep(2)
