#include <stdio.h>
/* 
 * This program generates and prints all possible two-digit combinations
 * with digits from 0 to 9.
 */
int main(void)
{
	int x, y;

	for (x = 0; x < 9; x++)
	{
		for (y = x + 1; y <= 9; y++)
		{
			putchar(x + '0');
			putchar(y + '0');

			if (x < 8 || y < 9)
			{
				putchar(',');
				putchar(' ');
			}

			if (x == 8 && y == 9)
				putchar('\n');
		}
	}

	return (0);
}
