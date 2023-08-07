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
	ssize_t desc;
	ssize_t rd;
	ssize_t wr;

	desc = open(filename, O_RDONLY);
	if (desc == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	rd = read(desc, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rd);

	free(buffer);
	close(desc);
	return (wr);
}
