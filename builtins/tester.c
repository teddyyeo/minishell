#include"../minishell.h"

int main(int argc, char **argv, char **envp)
{
	printf("arg num: %d\n", argc);
	export(&argv[1], envp);
	printf("\n\n\n\n\n");
	env(envp);
	pwd();
}
