#include <stdlib.h>
#include "main.h"

/**
 * read_textfile- File read & printed to STDOUT
 * @filename: Name of the file to read
 * @letters: Num of letters to read & print
 * Return: Actual number of letters read and printed
 * 0 if filename == NULL or when function fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bf;
	ssize_t fd, w, rid;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	bf = malloc(sizeof(char) * letters);
	rid = read(fd, bf, letters);
	w = write(STDOUT_FILENO, bf, rid);

	free(bf);
	close(fd);
	return (w);
}
