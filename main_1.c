#include "main.h"
#define SIZE_BUFFER 150
/**
 * suit - code that passes the Betty checks
 */
int suit(char **arg_list, char *p)
{
	/*
	 * char buffer[SIZE_BUFFER], *tmp, *p, *arg_list[20];
	 *int compteur, increment;
	 *size_t boucle;
	 */
	int increment;
	pid_t process;
	process = fork();
	if (process == 0)
	{
		int retour = execvp(arg_list[0], arg_list);

		if (retour ==  -1)
			printf("%s\n", strerror(errno));
		exit(0);
	}
	else
	{
		wait(&process);
	}
	increment = 0;
	while (arg_list[increment] != NULL)
	{
		free(arg_list[increment]);
		increment++;
	}
	free(p);
	return (0);
}
