#include "PJ_RPI.h"
#include <stdio.h>
//#include <stdlib.h>
#include <sys/time.h>
//#include <mysql.h>
#include <stdbool.h>

int main()
{
	if(map_peripheral(&gpio) == -1) 
	{
       	 	printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
        	return -1;
    }

	INP_GPIO(17);

	struct tm *timeinfo ;
	time_t rawtime ;
	char strResponse [128];
	bool io_17;

	while(1)
	{
		io_17 = GPIO_READ(17);
		printf("Input GPIO 17 = %d\n",io_17);

		rawtime = time (NULL) ;
		timeinfo = localtime(&rawtime) ;  
		strftime(strResponse,128,"%H:%M:%S %d-%b-%Y",timeinfo);  

		printf ("%s\n", strResponse);
	}

	return 0;	

}
