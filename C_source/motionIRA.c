#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define INFRARED 11 // physic. 26
#define LED 12  // physic. 19
#define SPEAKER 1 // physic. 12
#define SERVO 4 //physic. 16

int main(void){

    if(wiringPiSetup()==-1){
        return 1;
    }

    pinMode(INFRARED, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(SPEAKER, OUTPUT);
    softPwmCreate(SERVO, 0, 200);

    for(;;){
        if(digitalRead(INFRARED) == HIGH){
            digitalWrite(LED, HIGH);
            digitalWrite(SPEAKER, HIGH);
            softPwmWrite(SERVO, 24);
        }
        else
        {
            digitalWrite(LED, LOW);
            digitalWrite(SPEAKER, LOW);
            softPwmWrite(SERVO, 5);
        }
        
    }

    return 0;
}