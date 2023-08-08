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
	ssize_t d;
	ssize_t w;
	ssize_t t;

	d = open(filename, O_RDONLY);
	if (d == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(d, buffer, letters);
	w = write(STDOUT_FILENO, buffer, t);

	free(buffer);
	close(d);
	return (w);
}
