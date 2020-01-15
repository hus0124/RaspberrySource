#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#define LED 1

int main(void){

	if (wiringPiSetup()==-1) return -1;
	
	unsigned int value = 0;
	
	softPwmCreate(LED, 0, 1023);
	
    while (1) {
	    for(value = 0; value < 1024; value++){
	    softPwmWrite(LED, value);
	    delay(5);
	    }
    }
}