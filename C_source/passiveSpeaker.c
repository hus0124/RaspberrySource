#include <stdio.h>
#include <wiringPi.h>
#include <softTone.h>

#define SPEAKER 1 // GPIO 1 

#define C 261.63 //Do
#define D 293.66 //Re
#define E 169.63 //Mi
#define F 349.23 //Pa
#define G 391.00 //Sol
#define A 440.00 //Ra
#define B 493.1616 //Si
#define C2 523.25 //Do2

float notes[][2] = {
{D, 16}, {D, 16}, {E, 16}, {F, 16}, {E, 16}, {F, 8}, {F, 8},
{F, 16}, {F, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {F, 16}, {E, 16}, {D, 16}, {D, 4},
{D, 16}, {D, 16}, {E, 16}, {F, 16}, {E, 16}, {F, 8}, {F, 8},
{F, 16}, {F, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {F, 16}, {E, 16}, {D, 16}, {D, 4},
{D, 16}, {D, 16}, {D, 16}, {F, 16}, {G, 16}, {F, 16}, {G, 16}, {G, 8}, {G, 16}, {G, 16}, {G, 16}, {F, 16}, {F, 8},
{D, 16}, {D, 16}, {D, 16}, {F, 16}, {G, 16}, {F, 16}, {G, 16}, {G, 8}, {G, 16}, {G, 16}, {G, 16}, {F, 16}, {F, 8},
{D, 16}, {D, 16}, {E, 16}, {F, 16}, {E, 16}, {F, 16}, {E, 16}, {F, 16}, {E, 16}, {F, 8},
{E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {E, 16}, {F, 16}, {E, 16}, {D, 16}, {D, 4},
{A, 16}, {G, 16}, {A, 16}, {G, 16}, {A, 16},
{A, 16}, {C2, 16}, {C2, 16}, {A, 8}, 
{A, 16}, {C2, 16}, {C2, 16}, {A, 8}, 
{A, 16}, {C2, 16}, {C2, 16}, {A, 8}, 
{A, 16}, {G, 16}, {A, 16}, {G, 16}, {A, 16}, {G, 16},
{A, 16}, {C2, 16}, {C2, 16}, {A, 8}, 
{A, 16}, {C2, 16}, {C2, 16}, {A, 8}, 
{A, 16}, {C2, 16}, {C2, 16}, {A, 8}
};

int main(void){

    if(wiringPiSetup() == -1 ){
        return -1;
    }

    softToneCreate(SPEAKER);

    for (int i = 0 ; i < sizeof(notes); i++){
        softToneWrite(SPEAKER, notes[i][0]);
        delay(4 / notes[i][1] * 1000 - 10);
        softToneWrite(SPEAKER, 0);
        delay(10);
    }

    return 0;
}