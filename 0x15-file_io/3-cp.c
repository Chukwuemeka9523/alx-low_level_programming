#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int safe_close(int fd);

/**
 * main - Copies content from one file to another
 * @argc: Number of arguments passed to the program
 * @argv: Array of pointers to arguments
 *
 * Return: 0 on success, exit with an error code on failure
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	int bytes_read = 0, end_of_file = 1, from_fd = -1, to_fd = -1, error = 0;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	to_fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (to_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		safe_close(from_fd);
		exit(99);
	}

	while (end_of_file)
	{
		end_of_file = read(from_fd, buffer, 1024);
		if (end_of_file < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			safe_close(from_fd);
			safe_close(to_fd);
			exit(98);
		}
		else if (end_of_file == 0)
			break;
		bytes_read += end_of_file;
		error = write(to_fd, buffer, end_of_file);
		if (error < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			safe_close(from_fd);
			safe_close(to_fd);
			exit(99);
		}
	}
	error = safe_close(to_fd);
	if (error < 0)
	{
		safe_close(from_fd);
		exit(100);
	}
	error = safe_close(from_fd);
	if (error < 0)
		exit(100);
	return (0);
}

/**
 * safe_close - A function that closes a file and prints an error message
 * if it fails
 * @fd: The file descriptor to close
 *
 * Return: 0 on success, -1 on failure
 */
int safe_close(int fd)
{
	int error;

	error = close(fd);
	if (error < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	return (error);
}

