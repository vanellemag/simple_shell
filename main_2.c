#include "main.h"
#define SIZE_BUFFER 150
int suit(char **arg_list, char *p);
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
	/*pid_t process;*/

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
		suit(arg_list, p);
	}
	return (0);
}
