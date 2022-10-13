#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <mysql.h>
#include <stdbool.h>
#include <gpiod.h>
//Uitbreiding
bool Input_Value_Changed(bool *newVal, bool *oldVal);

int main()
{
	
	MYSQL *con = mysql_init(NULL);

	const char *chipname = "gpiochip0";
	struct gpiod_chip *chip;
	struct gpiod_line *gpio_pin_17;
	struct gpiod_line *gpio_pin_18;

	chip = gpiod_chip_open_by_name(chipname);

	gpio_pin_17 = gpiod_chip_get_line(chip, 17);
	gpio_pin_18 = gpiod_chip_get_line(chip, 18);

	gpiod_line_request_input(gpio_pin_17, "Labo1GD");
	gpiod_line_request_input(gpio_pin_18, "Labo1GD");

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

	if (mysql_query(con, "CREATE TABLE IF NOT EXISTS inputChanges( time TIMESTAMP DEFAULT CURRENT_TIMESTAMP, gpio VARCHAR(3), value INT );"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	
	char poort17 [3] = "17";
	char poort18 [3] = "18";
	bool io_17_new, io_17_old = gpiod_line_get_value(gpio_pin_17);
	bool io_18_new, io_18_old = gpiod_line_get_value(gpio_pin_18);

	while(1)
	{
		io_17_new = gpiod_line_get_value(gpio_pin_17);
		io_18_new = gpiod_line_get_value(gpio_pin_18);

		if(Input_Value_Changed(&io_17_new, &io_17_old))
		{
			printf("NEW VALUE GPIO %s = %d\n",poort17,io_17_new);
			
			char queryString [128];
			sprintf(queryString,"INSERT INTO inputChanges (gpio, value) VALUES('%s','%d');",poort17,io_17_new);

			if (mysql_query(con, queryString))
			{
				fprintf(stderr, "%s\n", mysql_error(con));
				mysql_close(con);
				exit(1);
			}
			sleep(1);
		}
		if(Input_Value_Changed(&io_18_new, &io_18_old))
		{
			printf("NEW VALUE GPIO %s = %d\n",poort18,io_18_new);
			
			char queryString [128];
			sprintf(queryString,"INSERT INTO inputChanges (gpio, value) VALUES('%s','%d');",poort18,io_18_new);

			if (mysql_query(con, queryString))
			{
				fprintf(stderr, "%s\n", mysql_error(con));
				mysql_close(con);
				exit(1);
			}
			sleep(1);
		}
	}
	gpiod_line_release(gpio_pin_17);
	gpiod_line_release(gpio_pin_18);
	gpiod_chip_close(chip);
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