#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINTIME_LEN 20

char* int_to_binstr(int num, int bits_wanted)
{
	char *bin_string = malloc(bits_wanted);
	int i;

	for(i = 0; i < bits_wanted; i++) {
		bin_string[(bits_wanted - 1) - i] = (char) (int)'0' + ((num >> i) & 1);
	}
	return bin_string;
}

char* get_bintime() 
{
	char *bintime;
	bintime = malloc(BINTIME_LEN);
	time_t rawtime;
	
	rawtime = time(NULL);
	struct tm *timeinfo = localtime(&rawtime);

	sprintf(bintime, "%s:%s:%s\n", int_to_binstr(timeinfo->tm_hour, 6), 
			int_to_binstr(timeinfo->tm_min, 6), 
			int_to_binstr(timeinfo->tm_sec, 6));
	return bintime;
}

int main()
{
	printf("%s\n", get_bintime());
	return 0;
}
