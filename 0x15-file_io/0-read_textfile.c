#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- File read & printed to STDOUT
 * @filename: Name of the file to read
 * @letters: Num of letters to read & print
 * Return: Actual number of letters read and printed
 * 0 if filename == NULL or when function fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	int f_d;
	ssize_t write_, read_;

	if (!filename)
	{
		return (0);
	}

	f_d = open(filename, O_RDONLY);
	if (d == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		close(f_d);
		return (0);

	read_ = read(f_d, buffer, letters);
	if (read_ < 0)
	{
		free(buffer);
		close(f_d);
		return (0);
	}

	write_ = write(STDOUT_FILENO, buffer, read_);
	if (write_ < 0)
	{
		free(buffer);
		close(f_d);
		return (0);
	}
	free(buffer);
	close(f_d);
	return (write_);
}
