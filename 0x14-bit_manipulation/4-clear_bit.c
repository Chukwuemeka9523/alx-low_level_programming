#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @num: a pointer to the number to modify
 * @index: the index of the bit to set to 0
 *
 * Return: 1 on success, or -1 on failure
 */
int clear_bit(unsigned long int *num, unsigned int index)
{
	/** check if index is out of range */
	if (index >= 8 * sizeof(unsigned long int))
		return (-1);

	/** check if the bit at the given index is already 1 */
	if (*num & 1UL << index)
		*num ^= 1UL << index; /** set the bit at the given index to 0 */

	return (1);
}

