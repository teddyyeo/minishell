#include <stdio.h>

void env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	env(envp);
	return (0);
}
