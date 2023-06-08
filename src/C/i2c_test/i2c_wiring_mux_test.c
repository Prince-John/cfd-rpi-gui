#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>

#define Device_Address 0x70
#define MUX_CH01 0b00000001
#define MUX_CH02 0b00000010


int fd;

void ms_delay(int val){
    int i,j;
    for(i=0;i<=val;i++)
        for(j=0;j<1200;j++);
}


int main() {

    fd = wiringPiI2CSetup(Device_Address);
    printf("fd is  %d \n",fd);
    wiringPiI2CWrite (fd, MUX_CH01);
    printf("writing to mux %s",MUX_CH01);
    ms_delay(50);



}
