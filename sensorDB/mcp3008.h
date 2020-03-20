#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#define SPI_CHANNEL 0 // \CS/SHDN핀을 CE0에 연결한 경우 0으로, CE1에 연결한 경우 1로 설정
#define SPI_SPEED 1000000

int mcplightnum;

int read_mcp3008_adc(unsigned char adcChannel) // adcChannel 은 센서 연결할 CH 번호 위치
{
	unsigned char buff[3];
	int adcValue=0;
	
	buff[0]=0x01;
	buff[1]=((adcChannel | 0x08)<<4);
	buff[2]=0x00;
	
	wiringPiSPIDataRW(SPI_CHANNEL,buff,3);
	
	buff[1]=0x3 & buff[1];
	adcValue=(buff[1]<<8)|buff[2];
	
	return adcValue;
}

//int read_mcp3008_adc(unsigned char adcChannel);

int read_mcp3008(){

	int adcValue=0;
	if(wiringPiSPISetup(SPI_CHANNEL,SPI_SPEED)==-1){
		printf("SPI ERROR");
		return 1;
	}

	
		adcValue=read_mcp3008_adc(1); // CH1 번 채널에 센서 연결
		mcplightnum = adcValue;
		printf("%d\n",adcValue);
		delay(1000); 
	

}


