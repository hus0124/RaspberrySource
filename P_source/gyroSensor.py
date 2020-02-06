import time, smbus

def ScaleValue(val) :
    if val >= 32768 :
        val = val - 65536
    return val

def Read_X_Accel() :
    h=bus.read_byte_data(mpu6050_addr, 0x3B)
# read_byte_data (slave_addr、 reg_addr)
    l=bus.read_byte_data(mpu6050_addr, 0x3C)
    x=ScaleValue((h<<8)|l)
    return x

def Read_Y_Accel(): # y축 가속도 센싱값 읽음
    h=bus.read_byte_data(mpu6050_addr, 0x3D)
    l=bus.read_byte_data(mpu6050_addr, 0x3E)
    y=ScaleValue((h<<8)|l)
    return y

def Read_Z_Accel(): # z축 가속도 센싱값 읽음
    h=bus.read_byte_data(mpu6050_addr, 0x3F)
    l=bus.read_byte_data(mpu6050_addr, 0x40)
    z=ScaleValue((h<<8)|l)
    return z

bus = smbus.SMBus(1)
mpu6050_addr = 0X68 # MPU6050 칩의 고유주소

bus.write_byte_data(mpu6050_addr, 0x6B, 0)
# write_byte_data (slave_addr、 reg_addr,data)

while 1:
    x = Read_X_Accel()
    y = Read_Y_Accel()
    z = Read_Z_Accel()

    print(x,y,z)
    time.sleep(0.5)

