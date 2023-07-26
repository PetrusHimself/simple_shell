#include "shell.h"

void free_function(char **array_path, char *catpath, char *l);
/**
 * fork_execute - make a fork and excute a command
 * @command_array: command array that will be excuted
 * @env: enviroment variable
 * Return: 0 on success and 1 in fail
 */
int fork_execute(char **command_array, char **env)
{
	pid_t id;
	int statue, access_id, i = 0;
	char *path = get_path(env), *catpath = malloc(_strlen(command_array[0]) + 1);
	char **array_path = get_array_command(path, ":");

	free(path);
	_strcpy(catpath, command_array[0]);
	while (array_path[i] != NULL)
	{
		if (i != 0)
		{
			catpath = malloc(_strlen(array_path[i]) + _strlen(command_array[0]) + 2);
			if (catpath == NULL)
				return (-1);
			_strcpy(catpath, array_path[i]);
			_strcat(catpath, "/");
			_strcat(catpath, command_array[0]);
		}
		access_id = access(catpath, X_OK);
		if (access_id != 0)
			free(catpath);
		if (access_id == 0)
		{
			id = fork();
			if (id == 0)
			{
				execve(catpath, command_array, env);
				break;
			}
			else
			{
				wait(&statue);
				free_function(array_path, catpath, l);
				return (0);
			}
		}
		i++;
	}
	if (access_id != 0)
		perror("ERROR");
	free(l);
	free(array_path);
	return (1);
}

/**
 * free_function - free all strings
 * @array_path:...
 * @catpath:...
 * @l:...
 */
void free_function(char **array_path, char *catpath, char *l)
{
	free(catpath);
	free(array_path);
	free(l);
}
