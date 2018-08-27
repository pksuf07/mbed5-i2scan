/*
 * file name  : mbed-i2cscan.cpp
 * description: I2C scanner, Arduino
 */
#include "mbed.h"

I2C	i2c(I2C_SDA, I2C_SCL);

int main() 
{
	int ack, devFound=0;
	while(1) {
		devFound=0;
		printf("\r\nI2C Bus Scanner V0.1\r\n");
		//-- table header -----------------------
		printf("   ");
		for (int i = 0; i < 16; i++) {
			printf("%3x", i);
		}

		//-- table body -------------------------
		for (int address = 0; address < 127; address++) {
			if (address % 16 == 0) {
      			printf("\r\n%02x:", address & 0xF0);
    		}
			//-- i2c.start();
      		ack=i2c.write((address<<1), "11", 1);
			//-- i2c.stop();
			if (ack == 0) { // device found
        		printf(" %02x", address);
				devFound++;
			} else {
				printf(" --");
			}
		}
		printf("\r\nTotal %d device found\r\n", devFound);
		wait(5.0);
	}
}
