#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXTIMING 85
#define DHTPIN 7

int dht11_dat[5] = {0,0,0,0,0};


int read_dht11_dat(){
    
    int laststate = HIGH;
    int counter = 0;
    int j = 0, i;
    float f;
    double humid;
    double celcius;

    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

    pinMode(DHTPIN, OUTPUT);
    digitalWrite(DHTPIN, LOW);
    delay(18);
    digitalWrite(DHTPIN, HIGH);
    pinMode(DHTPIN, INPUT);
    delayMicroseconds(40);
    

    for(i=0; i<MAXTIMING; i++){
        counter = 0;

        while(digitalRead(DHTPIN)==laststate){
            counter++;
            delayMicroseconds(1);

            if(counter == 255){
                break;
            }
        }

        laststate = digitalRead(DHTPIN);

        if(counter == 255){
            break;
        }    

        if((i>=4)&&(i%2==0)){
            dht11_dat[j/8] <<= 1;

            if(counter>50)
                dht11_dat[j/8] |= 1;
            j++;
            
        }
    }
        if((j>=40)&&(dht11_dat[4])==(dht11_dat[0]+dht11_dat[1]+dht11_dat[2]+dht11_dat[3]&0xFF)){
            f=dht11_dat[2] * 9./5. + 32;

            printf("Humidity = %d.%d %% Temperature = %d.%d C (%.1f F)\n", dht11_dat[0],dht11_dat[1], dht11_dat[2], dht11_dat[3], f);
    
        }
        else {
            printf("Data not good, skip\n");
        }
        
        humid = dht11_dat[0] + (double)dht11_dat[1]/10;
        celcius = dht11_dat[2] + (double)dht11_dat[3]/10;

        
        return humid;
}

