#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

int spi_channel = 0; // \CS/SHDN핀을 CE0에 연결한 경우 0으로, CE1에 연결한 경우 1로 설정
int spi_speed = 1000000;
int adc_channel = 1;

wiringPiSetup();

if (wiringPiSPISetup(spi_channel, spi_speed) == -1)
    return -1;

unsigned char buffer[3];
int adc_value = 0;

void read_mcp3008(){
    buffer[0] = 1;
    buffer[1] = (8 + adc_channel) << 4;
    buffer[2] = 0;

    wiringPiSPIDataRW(spi_channel, buffer, 3);

    adc_value = ((buffer[1]&3) << 8) + buffer[2];
    printf("ADC value: %4d Voltage: %f\n", adc_value, 3.3*adc_value/1024);

    delay(1000);
}
