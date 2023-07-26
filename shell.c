#include "shell.h"

void handle_signal(int sig);
/**
 * main - ...
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: enviroment
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t buf_size = 0;
	char **array_command = NULL;
	void (*func)();
	int j, flag = 1, fd = 0, inter_flag = 0;
	int statue;
	char **array_lines = NULL;

	signal(SIGINT, handle_signal);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[0]);
	}
	while (flag)
	{
		j = 0;
		if (isatty(fd))
		{
			write(STDOUT_FILENO, "$ ", 2);
			inter_flag = 1;
		}
		flag = _getline(&line, &buf_size, fd);
		if (flag == EOF)
		{
			if (fd == 0 && inter_flag)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (_strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		array_lines = get_array_command(line, ";");
		while (array_lines[j])
		{
			array_command = get_array_command(array_lines[j], " ");
			func = get_fun(array_command[0]);
			statue = array_command[1] ? _atoi(array_command[1]) : 0;
			if (func != NULL)
			{
				arg_t args;

				if (_strcmp(array_command[0], "exit") == 0)
				{
					free(array_command[0]);
					free(array_command);
					free_strarr(array_lines);
					free(line);
				}
				args.env = env;
				args.statue = statue;
				args.array_command = array_command;
				func(args);
			}
			else
				fork_execute(array_command, env);
			j++;
		}
		free(array_command[0]);
		free(array_command);
		free_strarr(array_lines);
		free(line);
	}
	return (0);
}
/**
 * handle_signal - handle ctrl + c
 * @sig: signal to handle
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
		printf("\n$ ");
	fflush(stdout);
}
