#include <stdio.h>
#define SYSFS_USR3 "/sys/class/leds/beaglebone:green:usr3"

void write_to_LED(char filename[], char value[]);


int main(int agrc, char* argv[])
{
	FILE *fp1, *fp2, *fp3, *fp4;
	if(strcmp(argv[1], "on") == 0){
		write_to_LED("/trigger", "none");
		write_to_LED("/brightness", "1");
	}
	else if(strcmp(argv[1], "off") == 0)
		write_to_LED("/brightness", "0");
	else if(strcmp(argv[1], "flash") == 0){
		write_to_LED("/trigger", "timer");
		write_to_LED("/delay_on", "50");
		write_to_LED("/delay_off", "50");
	}
	else if(strcmp(argv[1], NULL) == 0){
		printf("Usage is \n");
		printf("./led2 on|off|flash\n");
		return 0;
	}
}

void write_to_LED(char file[], char value[]){
	FILE* fp;
	char pathname[100];
	sprintf(pathname, SYSFS_USR3 "%s", file);
	fp = fopen(pathname, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}
