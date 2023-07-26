#include "shell.h"

void print_string(char *str, int start, int len);
void print_line_env(arg_t args, char *str);

/**
 * handle_echo - hande three cases of echo ("", $$, $?)
 * @args: ...
 */
void handle_echo(arg_t args)
{
	char *line = args.array_command[1];

	if (line[0] == '\"' || line[0] == '\'')
		print_string(line, 1, (_strlen(line) - 1));
	else if (line[0] == '$' && (line[1] >= 'A' && line[1] <= 'Z'))
	{
		char *str = _strdup(line);

		str++;
		print_line_env(args, str);
	}
	else if (_strncmp(line, "$$", 2) == 0)
	{
		pid_t pid = getpid();

		printf("%d\n", pid);
	}
	else if (_strncmp(line, "$?", 2) == 0)
	{
		int wstatus;
		int status_code = WEXITSTATUS(wstatus);

		printf("%d\n", status_code);
	}
	else
		printf("%s\n", line);
}

/**
 * print_string - print string without quots
 * @str: string
 * @start: start print
 * @len:length
 * Return:void
 */
void print_string(char *str, int start, int len)
{
	int i;

	for (i = start; i < len; i++)
		putchar(str[i]);
	putchar('\n');
}

/**
 * print_line_env - search in env and print line
 * @str: string
 * @args: struct
 * Return:void
 */
void print_line_env(arg_t args, char *str)
{
	int i, len = _strlen(str);

	for (i = 0; args.env[i] != NULL; i++)
	{
		if (_strncmp(str, args.env[i], len) == 0)
		{
			print_string(args.env[i], _strlen(str) + 1, _strlen(args.env[i]));
			break;
		}

	}
}
