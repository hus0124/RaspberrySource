#include <wiringPi.h>
#include <stdio.h>

#define FAN_IA 4    // wpi 4 physic 16
#define FAN_IB 5    // wpi 5 physic 18

//left 4 rotate
static void Left_4_Second(){
    digitalWrite(FAN_IA, HIGH);
    digitalWrite(FAN_IB, LOW);
    delay(4000);
}

//right 4 rotate
static void Right_4_Second(){
    digitalWrite(FAN_IA, LOW);
    digitalWrite(FAN_IB, HIGH);
    delay(4000);
}

// 2 second ready
static void Wait_2_Second(){
    digitalWrite(FAN_IB, LOW);
    digitalWrite(FAN_IA, LOW);
    delay(2000);
}

int main(void){
    if (wiringPiSetup() == -1){
        return 1;
    }

    pinMode(FAN_IA, OUTPUT);
    pinMode(FAN_IB, OUTPUT);

    //loop

    while(1){
        Left_4_Second();
        Wait_2_Second();
        Right_4_Second();
        Wait_2_Second();
    }

    return 0;
}