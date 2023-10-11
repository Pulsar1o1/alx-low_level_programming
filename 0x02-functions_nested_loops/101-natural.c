#include <stdio.h>

/**
 * main - program that computes and prints the sum of all the multiples of 3 or 5 below 1024
 *
 * Description: check for all natural numbers in range of
 * 3 and 5 and sum them
 * Return: 0
 */

int main(void)
{

	int i, sum;

	for (i = 0; i < 1024; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			sum += i;
		}
	}
	printf("%d\n", sum);

	return (0);
}
