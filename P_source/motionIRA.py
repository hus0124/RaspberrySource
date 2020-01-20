import RPi.GPIO as GPIO


INFRARED = 7
LED = 10
SPEAKER = 18
SERVO = 23

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(INFRARED, GPIO.IN)
GPIO.setup(LED, GPIO.OUT)
GPIO.setup(SPEAKER, GPIO.OUT)
GPIO.setup(SERVO, GPIO.OUT)
p=GPIO.PWM(SERVO, 50)
p.start(0)

try :
    while True :
        if GPIO.input(INFRARED) == 1:
            GPIO.output(LED, True)
            GPIO.output(SPEAKER, True)
            p.ChangeDutyCycle(12.5)
            
        else :
            GPIO.output(LED, False)
            GPIO.output(SPEAKER, False)
            p.ChangeDutyCycle(2.5)

except :
    GPIO.cleanup()
    print("end")
                
