#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @num: the number to get the bit from
 * @index: the index of the bit to get
 *
 * Return: the value of the bit (0 or 1) or -1 if an error occurs
 */
int get_bit(unsigned long int num, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		/** check if index is out of range */
		return (-1);

	return (num >> index & 1);
	/** return the value of the bit at the given index */
}

