#include "PJ_RPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <mysql.h>
#include <stdbool.h>

bool Input_Value_Changed(bool *newVal, bool *oldVal);

int main()
{
	
	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "root", "", NULL, 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	if (mysql_query(con, "CREATE DATABASE IF NOT EXISTS labo1GD;"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	if (mysql_query(con, "USE labo1GD;"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	if (mysql_query(con, "CREATE TABLE IF NOT EXISTS inputChanges( time VARCHAR(128), gpio VARCHAR(2), value INT );"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	if(map_peripheral(&gpio) == -1) 
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
    }
	
	INP_GPIO(17);
	char poort17 [2] = "17";
	bool io_17_new, io_17_old = GPIO_READ(17);

	while(1)
	{
		io_17_new = GPIO_READ(17);
		if(Input_Value_Changed(&io_17_new, &io_17_old))
		{
		printf("NEW VALUE GPIO 17 = %d\n",io_17_new);

			struct tm *timeinfo ;
			time_t rawtime ;
			char strResponse [128];

			rawtime = time (NULL) ;
			timeinfo = localtime(&rawtime) ;  
			strftime(strResponse,128,"%H:%M:%S %d-%b-%Y",timeinfo);
			
			char queryString [128];
			sprintf(queryString,"INSERT INTO inputChanges (time, gpio, value) VALUES('%s','%s','%d');",strResponse,poort17,io_17_new);

			if (mysql_query(con, queryString))
			{
				fprintf(stderr, "%s\n", mysql_error(con));
				mysql_close(con);
				exit(1);
			}
		}
		
	}

	return 0;	

}

bool Input_Value_Changed(bool *newVal, bool *oldVal)
{
	if(*newVal != *oldVal)
	{
		*oldVal = *newVal;
		return 1;
	}
	return 0;
}