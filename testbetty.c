#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * main - code that passes the Betty checks
 *
 * Return: success
 */
int main(void)
{
	char beffer[50];

	printf("Our first test about command interpreter\n");
	printf("Enter \"Exit\" for exiter\n");
	while (1)
	{
		printf("prompt : ");
		scanf("%s", beffer);
		if (strcmp("exit", beffer) == 0)
		{
			exit(0);
		}
		else
		{
			printf("Unknown command..\n");
		}
	}
}
