#include "main.h"
#define SIZE_BUFFER 150
/**
 * main - code that passes the Betty checks
 *
 * Return: success
 */
int main(void)
{
	char buffer[SIZE_BUFFER], *tmp, *p, *arg_list[20];
	int compteur, increment;
	size_t boucle;
	pid_t process;

	while (1)
	{
		printf("#prompt$ ");
		fgets(buffer, SIZE_BUFFER, stdin);
		buffer[strlen(buffer) - 1] = '\0';
		if (strcmp("exit", buffer) == 0)
		{
			exit(0);
		}
		compteur = 0;
		for (boucle = 0; boucle < strlen(buffer); ++boucle)
		{
			if (buffer[boucle] == ' ')
				++compteur;
		}
		compteur = compteur + 2;
		p = strdup(buffer);
		tmp = strtok(p, " ");
		increment = 0;
		while (tmp != NULL)
		{
			arg_list[increment] = strdup(tmp);
			increment++;
			tmp = strtok(NULL, " ");
		}
		arg_list[increment] = NULL;
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
	}
	return (0);
}
