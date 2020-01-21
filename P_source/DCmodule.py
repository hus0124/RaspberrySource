import RPi.GPIO as GPIO
import Motor_Module as MOTOR

FAN_IA = 23 #physic 16
FAN_IB = 24 #physic 18

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(FAN_IA, GPIO.OUT)
GPIO.setup(FAN_IB, GPIO.OUT)




if __name__ == "__main__" :
    try :
        while True :
            MOTOR.LeftRotate(GPIO, FAN_IA, FAN_IB)
            MOTOR.WaitRotate(GPIO, FAN_IA, FAN_IB)
            MOTOR.RightRotate(GPIO, FAN_IA, FAN_IB)
            MOTOR.WaitRotate(GPIO, FAN_IA, FAN_IB)

    except :
        GPIO.cleanup()
        print("end")
