#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

const char prompt[] = "gts>";

void help();

int main(int argc, char *argv[])
{
		
		while(1) {
				char *entry;

				entry = readline(prompt);

				if (!strcmp(entry, "help") || !strcmp(entry, "quit") ||
												!strcmp(entry, "?"))
						help();
				else if (!strcmp(entry, "exit"))
						exit(0);
		}
	
		return 0;

}

void help(void)
{
		printf("MSG - paste a gprs message from a gps tracker device to be interpreted\n");
		printf("exit - exit from the GPS Tracker Security\n");
		printf("quit - quit from the GPS Tracker Security\n");
		printf("show devices\n");
		printf("show device id ID [detail]\n");
		printf("show device id ID database\n");
		printf("show database\n");
}

