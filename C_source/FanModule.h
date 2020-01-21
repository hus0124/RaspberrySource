#include <stdio.h>

// wpi 4 physic 16
#define FAN_IA 4

static void Weak(){
    softPwmWrite(FAN_IA, 666);
    printf("미풍\n");
    delay(5000);
}

static void Medium(){
    softPwmWrite(FAN_IA, 333);
    printf("약풍\n");
    delay(5000);
}

static void Strong(){
    softPwmWrite(FAN_IA, 0);
    printf("강풍\n");
    delay(5000);
}