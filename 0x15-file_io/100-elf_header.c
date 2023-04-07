#include <stdio.h>

/**
 * main - The main entry point for the program
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 * Return: 1 on success, error code on failure
 */
int main(int argc, char *argv[])
{
	/**
	 * Print the number of arguments and the pointer to array of arguments
	 */
	printf("argc: %d, argv: %p\n", argc, (void *)*argv);

	return (1);
}
