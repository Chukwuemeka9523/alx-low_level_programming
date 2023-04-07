#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a specified number of characters from a text file
 * and writes them to the standard output.
 * @filename: The name of the text file to be read.
 * @letters: The number of characters to be read and printed.
 * Return: The number of characters read and printed, or 0 if the
 * operation fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(file, buffer, letters);
	if (bytes_read < 0)
	{
		free(buffer);
		close(file);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);
	close(file);

	if (bytes_written < 0)
		return (0);

	return ((ssize_t) bytes_written);
}

