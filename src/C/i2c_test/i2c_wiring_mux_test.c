#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>

#define Device_Address 0x70
#define MUX_CH0 0b00000001
#define MUX_CH1 0b00000010
#define MUX_CH2 0b00000100

int fd;

void ms_delay(int val){
    int i,j;
    for(i=0;i<=val;i++)
        for(j=0;j<1200;j++);
}


int main(int argc, char **argv) {

    fd = wiringPiI2CSetup(Device_Address);
    printf("fd is  %d \n",fd);
    ms_delay(50);
    ms_delay(50);
    wiringPiI2CWrite (fd, MUX_CH01);
    printf("writing to mux %d",MUX_CH01);
    ms_delay(50);



}
