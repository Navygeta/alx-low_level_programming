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
	int descriptor;
	ssize_t wr, rid;

	if (!filename)
	{
		return (0);
	}

	descriptor = open(filename, O_RDONLY);
	if (descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		close(descriptor);
		return (0);

	rid = read(descriptor, buffer, letters);
	if (rid < 0)
	{
		free(buffer);
		close(descriptor);
		return (0);
	}

	wr = write(STDOUT_FILENO, buffer, rid);
	if (wr < 0)
	{
		free(buffer);
		close(descriptor);
		return (0);
	}
	free(buffer);
	close(descriptor);
	return (wr);
}
