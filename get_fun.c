#include "shell.h"

/**
 * get_fun -map a char to the function
 * @str: string that will be mapped
 * Return: a function pointer to the selected function
 * or NULL if no match
 */
void (*get_fun(char *str))()
{
	int i;
	fun_t fun[] = {
		{"env", print_env}, {"exit", _hexit},
		{"echo", handle_echo}, {NULL, NULL}
	};

	i = 0;
	while (fun[i].cmd)
	{
		if (_strcmp(fun[i].cmd, str) == 0)
			return (fun[i].funptr);
		i++;
	}
	return (NULL);
}
