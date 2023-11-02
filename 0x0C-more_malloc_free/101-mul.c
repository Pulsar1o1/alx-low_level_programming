#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int is_digit(char *str);
int str_len(char *str);
int *multiply(char *num1, char *num2);
void print_result(int *result, int len);

/**
 * main - multiplies two positive numbers
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    int *result;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    result = multiply(argv[1], argv[2]);
    if (result == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    print_result(result, str_len(argv[1]) + str_len(argv[2]));
    free(result);

    return (0);
}

/**
 * is_digit - checks if a string is a valid digit
 * @str: the string to check
 *
 * Return: 1 if true, 0 if false
 */
int is_digit(char *str)
{
    if (*str == '-')
        str++;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

/**
 * str_len - calculates the length of a string
 * @str: the string
 *
 * Return: the length of the string
 */
int str_len(char *str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return (len);
}

/**
 * multiply - multiplies two large numbers represented as strings
 * @num1: the first number as a string
 * @num2: the second number as a string
 *
 * Return: an array of integers representing the result
 */
int *multiply(char *num1, char *num2)
{
    int len1 = str_len(num1);
    int len2 = str_len(num2);
    int len_result = len1 + len2;
    int *result = malloc(sizeof(int) * len_result);
    int i, j, n1, n2, prod, carry;

    if (result == NULL)
        return (NULL);

    for (i = 0; i < len_result; i++)
        result[i] = 0;

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            prod = n1 * n2 + result[i + j + 1] + carry;
            carry = prod / 10;
            result[i + j + 1] = prod % 10;
        }
        result[i + j + 1] = carry;
    }
    return (result);
}

/**
 * print_result - prints the result array as a number
 * @result: the array of integers representing the result
 * @len: the length of the result array
 */
void print_result(int *result, int len)
{
    int i = 0;
    while (i < len && result[i] == 0)
        i++;

    if (i == len)
        putchar('0');
    else
    {
        while (i < len)
        {
            putchar(result[i] + '0');
            i++;
        }
    }
    putchar('\n');
}
