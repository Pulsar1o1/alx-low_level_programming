#include "main.h"
#include <stdlib.h>

/**
 * word_count - Count the number of words in a string.
 * @str: The string to count words in.
 *
 * Return: Number of words.
 */
int word_count(char *str)
{
	int count = 0;
	int in_word = 0; /* Flag to track if we're inside a word */

	while (*str)
	{
		if (*str == ' ')
		{
			if (in_word)
				in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		str++;
	}

	return (count);
}

/**
 * strtow - Split a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **words;
	int wc, word_len, i, j;

	if (str == NULL || *str == '\0')
		return (NULL);

	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*str)
	{
		if (*str == ' ')
		{
			str++;
			continue;
		}

		word_len = 0;
		while (str[word_len] != ' ' && str[word_len] != '\0')
			word_len++;

		words[i] = malloc((word_len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
	}

	for (j = 0; j < word_len; j++)
		words[i][j] = *str++;
	words[i][j] = '\0';
	i++;
	}
	words[i] = NULL;

	return (words);
}

