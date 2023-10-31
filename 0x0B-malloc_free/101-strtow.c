#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
    int i, count = 0;

    for (i = 0; str[i]; i++)
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            count++;
    }

    return (count);
}

/**
 * _strdup - Duplicates a string in memory.
 * @str: The input string.
 *
 * Return: A pointer to the newly allocated string.
 */
char *_strdup(char *str)
{
    char *duplicate;
    int i, len = 0;

    if (str == NULL)
        return (NULL);

    while (str[len])
        len++;

    duplicate = malloc(sizeof(char) * (len + 1));

    if (duplicate == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        duplicate[i] = str[i];

    return (duplicate);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words).
 */
char **strtow(char *str)
{
    char **words;
    int i, j, k, len, word_count = 0;

    if (str == NULL || str[0] == '\0')
        return (NULL);

    word_count = count_words(str);
    if (word_count == 0)
        return (NULL);

    words = malloc(sizeof(char *) * (word_count + 1));
    if (words == NULL)
        return (NULL);

    for (i = 0, k = 0; i < word_count; i++)
    {
        while (str[k] == ' ')
            k++;

        len = 0;
        while (str[k + len] != ' ' && str[k + len] != '\0')
            len++;

        words[i] = _strdup(&str[k]);
        if (words[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(words[j]);
            free(words);
            return (NULL);
        }
        k += len;
    }
    words[i] = NULL;

    return (words);
}
