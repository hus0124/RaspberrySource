import time
import Adafruit_DHT
sensor = Adafruit_DHT.DHT11
pin = 4

def dht11() :
    try :
        while True :
            h, t = Adafruit_DHT.read_retry(sensor, pin)

            if h is not None and t is not None :
                print("Temperature = {0:0.1f}*C Humidity = {1:0.1f}%".format(t,h))
                return t, h
            else :
                print("Read Error")
            time.sleep(1)

    except KeyboardInterrupt:
        print("Terminated by Keyboard")

    finally :
        print("End of Program")