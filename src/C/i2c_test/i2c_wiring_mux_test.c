#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>

#define Device_Address 0x70
#define MUX_CH0 0b00000001
#define MUX_CH1 0b00000010
#define MUX_CH2 0b00000100
#define MUX_CH3 0b00001000
#define MUX_CH4 0b00010000
#define MUX_CH5 0b00100000
#define MUX_CH6 0b01000000
#define MUX_CH7 0b10000000

int fd;
int fd1;
int verbose =1;

void ms_delay(int val){
    int i,j;
    for(i=0;i<=val;i++)
        for(j=0;j<1200;j++);
}

void set_mux_channel(int fd, int channel){

    switch (channel) {

        case 0:
            wiringPiI2CWrite (fd, MUX_CH0);
            break;
        case 1:
            wiringPiI2CWrite (fd, MUX_CH1);
            break;
        case 2:
            wiringPiI2CWrite (fd, MUX_CH2);
            break;
        case 3:
            wiringPiI2CWrite (fd, MUX_CH3);
            break;
        case 4:
            wiringPiI2CWrite (fd, MUX_CH4);
            break;
        case 5:
            wiringPiI2CWrite (fd, MUX_CH5);
            break;
        case 6:
            wiringPiI2CWrite (fd, MUX_CH6);
            break;
        case 7:
            wiringPiI2CWrite (fd, MUX_CH7);
            break;
        default:
            wiringPiI2CWrite (fd, MUX_CH0);
            if(verbose == 1){
                printf("%d is not a valid selection.\n", channel);
            }
            break;
    }
    if(verbose == 1){
        printf("Setting i2c mux to channel %d \n", channel);
    }
    ms_delay(10);
}



int main(int argc, char **argv) {

    fd = wiringPiI2CSetup(Device_Address);
    fd1 = wiringPiI2CSetup(Device_Address+3);

    printf("Re-setting MUX to default channel 0\n*********************************\nEnter a MUX channel 0-7\n");

    char input_str[2];
    char *ptr;
    int channel;
    while (1){

        fgets (input_str, 2, stdin);

        printf("%s is the output of fgets",input_str);
        channel= strtol(input_str, &ptr, 10);
        printf("%d is the output of strtol", channel);
        set_mux_channel(fd, channel);
        printf("DEBUG STATEMENT ************************");
        ms_delay(10);
    }

    return 0;


}
