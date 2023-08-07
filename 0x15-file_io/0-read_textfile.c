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
	ssize_t file_descr;
	ssize_t bytes_r;
	ssize_t bytes_wr;

	file_descr = open(filename, O_RDONLY);
	if (file_descr == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	bytes_r = read(file_descr, buffer, letters);
	bytes_wr = write(STDOUT_FILENO, buffer, bytes_r);

	free(buffer);
	close(file_descr);
	return (bytes_wr);
}
