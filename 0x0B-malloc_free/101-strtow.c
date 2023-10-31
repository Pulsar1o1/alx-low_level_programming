#include "main.h"
#include <stdlib.h>

/**
 * word_count - Counts the number of words in a string.
 * @str: The input string.
 * Return: The number of words.
 */
int word_count(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (*str == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}

	return (count);
}

/**
 * free_grid - Frees a 2D grid.
 * @grid: The grid to be freed.
 * @height: The height of the grid.
 */
void free_grid(char **grid, int height)
{
	while (height >= 0)
	{
		free(grid[height]);
		height--;
	}
	free(grid);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 * Return: A pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	int i, j, k, words, len;
	char **word_array;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = word_count(str);
	if (words == 0)
		return (NULL);

	word_array = malloc((words + 1) * sizeof(char *));
	if (word_array == NULL)
		return (NULL);

	i = 0;
	while (*str && i < words)
	{
		if (*str == ' ')
		{
			str++;
		}
		else
		{
			len = 0;
			while (str[len] != ' ' && str[len] != '\0')
				len++;

			word_array[i] = malloc(len + 1);
			if (word_array[i] == NULL)
			{
				free_grid(word_array, i - 1);
				return (NULL);
			}

			for (j = 0, k = 0; k < len; j++, k++)
				word_array[i][j] = str[k];

			word_array[i][j] = '\0';
			str += len;
			i++;
		}
	}

	word_array[i] = NULL;
	return (word_array);
}

