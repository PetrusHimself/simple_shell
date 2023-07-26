#include "shell.h"

/**
 * get_path - get path from environment
 * @env: environment from main
 * Return:path
 */

char *get_path(char **env)
{
	int i = 0, len;
	char *PATH, *sp_start = "path:";

	while (_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i] == NULL)
		return (NULL);
	len = _strlen(env[i]);
	PATH = malloc(sizeof(char) * (len + 1));
	if (!PATH)
		return (NULL);
	_strcpy(PATH, sp_start);
	_strcat(PATH, env[i] + 5);
	return (PATH);
}
