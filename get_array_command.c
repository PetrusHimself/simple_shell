#include "shell.h"
void remove_newline(char *str);
/**
 * get_array_command - parse the line to array of
 * command and arguments
 * @line: line to be parsed
 * @del: delemeter to split in
 * Return: array of command
 */
char **get_array_command(char *line, char *del)
{
	char **array_command = NULL;
	char *token;
	int idx, counter = 0;

	for (idx = 0; line[idx] != '\0'; idx++)
	{
		if (line[idx] == *del)
			counter++;
	}
	counter += 2;
	array_command = malloc(sizeof(char *) * counter);
	if (!array_command)
		return (NULL);
	l = _strdup(line);
	token = strtok(l, del);
	idx = 0;
	while (token != NULL)
	{
		array_command[idx++] = token;
		token = strtok(NULL, del);
	}

	remove_newline(array_command[idx - 1]);
	array_command[idx] = NULL;
	return (array_command);
}
/**
 * remove_newline - remove \n from the end of the string
 * @str: the string
 */
void remove_newline(char *str)
{
	int len = _strlen(str);

	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}
