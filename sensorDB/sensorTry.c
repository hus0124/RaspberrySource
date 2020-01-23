#include <stdio.h>
#include <mysql.h>
#include <wiringPi.h>
#include "DHT11.h"
#include "PhotoRegi.h"

int main(void){
    
    if(wiringPiSetup()==-1){
        return 1;
    }

    while(1){
        double humidvalue = read_dht11_dat();
        delay(2000);
        int lightnum = lightCheck();
        delay(2000);
        printf("\n");

        MYSQL *connector;
        char query[1024];
        
        connector = mysql_init(NULL);

        if(!mysql_real_connect(connector, "192.168.3.17", "java", "java",  // ip 주소 입력, id password, 
                            "javadb", 3306, NULL, 0))// DB 이름, 포트번호
            {
                printf("DB connect Fail");
            }
        else {
            printf("DB connect Success");
        }

        sprintf(query, "insert into tbl_sensor values(%.2f, %d)",humidvalue, lightnum);

        int result = mysql_query(connector,query);
        printf("\n%d",result);
        printf("\n%f",humidvalue);
        printf("\n%d\n",lightnum);
    }

    return (0);
}