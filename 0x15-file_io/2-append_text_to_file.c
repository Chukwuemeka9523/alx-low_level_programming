#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - A function that appends text to the end of a file
 * @filename: The name of the file to open and append to
 * @text_content: A NULL-terminated string containing the text to append to
 * Return: On success, returns 1. On failure, returns -1
 * if the file cannot be created, written to, or write operation fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fdo, fdw, len = 0;

	/** Return -1 if filename is NULL */
	if (filename == NULL)
		return (-1);

	/** Open file in read/write mode, create if it doesn't exist, append*/
	fdo = open(filename, O_RDWR | O_APPEND);
	if (fdo < 0)
		return (-1);

	/** If text_content is NULL, close the file and return 1 */
	if (text_content == NULL)
	{
		close(fdo);
		return (1);
	}

	/** Count the number of characters in text_content */
	while (*(text_content + len))
		len++;

	/** Write the text_content to the end of the file */
	fdw = write(fdo, text_content, len);

	/** Close the file */
	close(fdo);

	/** If write was unsuccessful, return -1 */
	if (fdw < 0)
		return (-1);

	/** Return 1 on success */
	return (1);
}

