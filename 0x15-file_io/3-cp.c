#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocate 1024 bytes for buffer
 * @file: Name of file storing characters
 *
 * Return: Return buffer
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - Function to close file descriptors
 * @fd: Descriptor to be closed
 */
void close_file(int fd)
{
	int _close;

	_close = close(fd);

	if (_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Func to copy contents to and from another file
 * @argc: The number of arguments in program
 * @argv: An array of pointers in program
 *
 * Return: On success return 0
 *
 * Description: Exit codes:
 *   97: Incorrect argument count
 *   98: Unable to read from source file
 *   99: Unable to write to destination file
 *   100: Unable to close files
 *
 */
int main(int argc, char *argv[])
{
	int from, to, _read, _write;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	_read = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || _read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		_write = write(to, buff, _read);
		if (to == -1 || _write == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		_read = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (_read > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
