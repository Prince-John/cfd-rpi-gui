#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <stdio.h>

//----- OPEN THE I2C BUS -----

int file_i2c;
int length;
unsigned char buffer[60] = {0};

void start_i2c(){
	
	char *filename = (char*)"/dev/i2c-1";
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check errno to see what went wrong
		printf("Failed to open the i2c bus");
		
		return;
	}
	printf("%d",file_i2c);	
}

int main(int argc, char* argv[]){
	
	start_i2c();

}
