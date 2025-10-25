#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 * Return: Always 0
 */
int main(void)
{
	unsigned long num = 612852475143;
	unsigned long largest_prime = 0;
	unsigned long i;

	/* Divide out all factors of 2 */
	while (num % 2 == 0)
	{
		largest_prime = 2;
		num = num / 2;
	}

	/* Check odd factors up to sqrt(num) */
	for (i = 3; i <= sqrt(num); i = i + 2)
	{
		while (num % i == 0)
		{
			largest_prime = i;
			num = num / i;
		}
	}

	/* If what remains is greater than 2, it's prime */
	if (num > 2)
		largest_prime = num;

	printf("%lu\n", largest_prime);

	return (0);
}

