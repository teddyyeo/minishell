#include"../minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_mslist list;

	list.env.envp = envp;
	printf("arg num: %d\n", argc);
	export(&list, &argv[1]);
	printf("\n\n\n\n\n");
	export(&list, NULL);
	printf("\n\n\n\n\n");
	env(list.env.envp);

}
