#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - Creates a file and writes a string to it.
 * @filename: The name of the file to be created.
 * @text_content: The string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, length = 0;

	/** Check if the filename is NULL */
	if (filename == NULL)
		return (-1);

	/** Create a new file with read/write permission and truncate it to 0 bytes */
	file_descriptor = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (file_descriptor < 0)
		return (-1);

	/** Calculate the length of the new content string */
	while (text_content && *(text_content + length))
		length++;

	/** Write the new content to the file */
	bytes_written = write(file_descriptor, text_content, length);

	/** Close the file and check if there was an error during writing */
	close(file_descriptor);
	if (bytes_written < 0)
		return (-1);

	return (1);
}

