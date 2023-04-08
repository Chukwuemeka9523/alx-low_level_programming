#include "main.h"

/**
 * binary_to_uint - converts a binary string to an unsigned integer
 * @binary: string containing the binary number
 *
 * Return: the converted number, or 0 if the conversion fails
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int result; /** the converted number */

	/** check if the string is not null */
	if (!binary)
		return (0);

	/** iterate over the string */
	for (result = 0; *binary; binary++)
	{
		if (*binary == '1')
			result = (result << 1) | 1; /** left shift by 1 and add 1 */
		else if (*binary == '0')
			result <<= 1; /** left shift by 1 */
		else
			return (0); /** invalid character */
	}

	return (result);
}

