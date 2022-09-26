#include "PJ_RPI.h"
#include <stdio.h>
//#include <stdlib.h>
#include <sys/time.h>
//#include <mysql.h>

int main()
{
	// if(map_peripheral(&gpio) == -1) 
	// {
    //    	 	printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
    //     	return -1;
    // }

	// Define gpio 17 as input
	//INP_GPIO(17);
	struct tm *timeinfo ;
	time_t rawtime ;
	char strResponse [128] ;

	while(1)
	{
		rawtime = time (NULL) ;
		timeinfo = localtime(&rawtime) ;  
		strftime(strResponse,128,"%H:%M:%S %d-%b-%Y",timeinfo);  

		printf ("%s\n", strResponse) ;
	}

	return 0;	

}
