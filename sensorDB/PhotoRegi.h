#include <stdio.h>
#include <time.h>

#define LIGHT 0

int lightnum;

int timestamp(void){
    time_t time_now;
    struct tm*tm;
    time(&time_now);
    tm = localtime(&time_now);
    return (printf("%d-%02d-%02d %02d:%02d:%02d", 
    tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
    tm->tm_hour, tm->tm_min, tm->tm_sec));    
}

int lightCheck(){
    if(wiringPiSetup()==-1){
        exit (1);
    }
   
    pinMode(LIGHT, INPUT);

    timestamp();

    if(digitalRead(LIGHT)==HIGH){   // HIGH이면 전압 높음. 어두운 상황.
        printf(" Dark");
    }
    else
    {
        printf(" Light");   //LOW이면 전압 낮음. 밝은 상황.
    }

    lightnum = digitalRead(LIGHT);

    return lightnum;

}