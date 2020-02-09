import spidev, time
import RPi.GPIO as GPIO
import dht11Module as DHT11
from db_utils import *

spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz=1350000

def analog_read(channel):
    r = spi.xfer2([1, (8+channel) << 4,0])
    adc_out = ((r[1]&3)<<8)+r[2]
    return adc_out

while True :
    reading = analog_read(1) # mcp3008 1번 채널에 조도 센서
    voltage = reading * 3.3/1024
    print("Reading=%d\tVoltage=%f"%(reading, voltage))
    degree, humid = DHT11.dht11() # dht11 센서 모듈 import, 리턴값 t, h 두 개 받아오기 
    time.sleep(10)
    
