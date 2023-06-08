#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>

#define Device_Address 0x70
#define MUX_CH01 0b00000001
#define MUX_CH02 0b00000010


int fd;

int main() {

    fd = wiringPiI2CSetup(Device_Address);

    wiringPiI2CWrite(fd, MUX_CH01);

}
