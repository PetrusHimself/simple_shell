#include "shell.h"
/**
 * _hexit - exit the program with a specific statue
 * @args: ...
 */
void _hexit(arg_t args)
{
	exit(args.statue);
}
/**
 * print_env - print the enviroment var
 * @args: ...
 */
void print_env(arg_t args)
{
	int i;

	for (i = 0; args.env[i]; i++)
		printf("%s\n", args.env[i]);
}
