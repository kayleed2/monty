#include "monty.h"

/**
 * main - Interprets Monty ByteCodes files
 * @ac: Arg count
 * @argv: Argument passed in
 *
 * Return: 0 on success, exit status on failure
 */

int main(int ac, char *argv[])
{
	FILE *file;
	ssize_t read;
	char *str = NULL;
	size_t len = 0;
	int i, n;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if ((file = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; (read = getline(&str, &len, file)) != -1; i++)
	{
		for (n = 0; str[n] != '\n'; n++)
		{
			if (str[n] == 'w')
			{
				printf("We are at a w: %s\n", str);
				break;
			}
		}
	}
}
