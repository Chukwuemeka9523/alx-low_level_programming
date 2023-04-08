#include "main.h"

/**
 * print_binary - prints the binary representation of an unsigned long int
 * @n: the number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask; /** bit mask */
	int flag = 0; /** flag to indicate if first 1 has been printed */

	if (n == 0) /** edge case of num being 0 */
		_putchar('0');

	for (mask = 1UL << 63; mask > 0; mask >>= 1)
		/** iterate through the bits in num */
	{
		if (n & mask) /** if the current bit is 1 */
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
			/** if the current bit is 0 and a 1 has been printed before */
			_putchar('0');
	}
}

