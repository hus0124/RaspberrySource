#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include "FanModule.h"

int main(void){
    if(wiringPiSetup()==-1){
        return 1;
    }

    softPwmCreate(FAN_IA, 0, 1000);

    while(1){
        Weak();
        Medium();
        Strong();        
    }

    return 0;
}