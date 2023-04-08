#include "main.h"

/**
 * flip_bits - counts the number of bits that must be flipped to convert
 *             one number to another.
 * @num1: one of the numbers
 * @num2: the other number
 *
 * Return: the number of bits that must be flipped
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	/** XOR both numbers to get bit differences */
	unsigned long int bit_diff = num1 ^ num2;
	/** initialize the bit count to zero */
	unsigned int count = 0;

	while (bit_diff)
	{
		if (bit_diff & 1) /** if the rightmost bit is 1, increment the count */
			count++;

		bit_diff >>= 1; /* shift the bit difference to the right */
	}

	return (count);
}

