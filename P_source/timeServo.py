import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
SERVO = 18
GPIO.setup(SERVO, GPIO.OUT)
SERVO_PWM = GPIO.PWM(SERVO, 50)
SERVO_PWM.start(0)

alarm_S = "08:00:00"

while True:
    i = 1
    cur_time = time.ctime()

    ddmmss=cur_time.split(' ')[-2]

    if ddmmss == alarm_S:

        while(i<2) :
            SERVO_PWM.ChangeDutyCycle(10)
            time.sleep(1)
            SERVO_PWM.ChangeDutyCycle(5)
            time.sleep(1)
            i = i + 1

SERVO_PWM.stop()
GPIO.cleanup()
