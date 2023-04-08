#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 1 if little endian, 0 if big endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	/** get a pointer to the least significant byte */
	char *byte_ptr = (char *) &num;

	if (*byte_ptr)
		/**
		 * if the value of the first byte is non-zero, the system is little endian
		 */
		return (1);
	else /** otherwise, the system is big endian */
		return (0);
}
