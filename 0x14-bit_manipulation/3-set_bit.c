#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index to 1
 * @num: a pointer to the number to modify
 * @index: the index of the bit to set to 1
 *
 * Return: 1 on success, or -1 on failure
 */
int set_bit(unsigned long int *num, unsigned int index)
{
	/** check if index is out of range */
	if (index >= 8 * sizeof(unsigned long int))
		return (-1);

	*num |= (1 << index); /** set the bit at the given index to 1 */
	return (1);
}

