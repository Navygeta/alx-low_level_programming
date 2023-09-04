#include <stdlib.h>
#include "main.h"

/**
 * read_textfile- Reads txt file & prints to STDOUT
 * @filename: Name of the file to read
 * @letters: Chars to read from & print from file
 * Return: Actual number of letters read and printed
 * 0 if filename == NULL or when function fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *read_buf;
	ssize_t fd, wr_chars, red_chars;

	fd = open(filename, O_RDONLY);
	if (fd == -1 && filename == NULL)
		return (0);
	read_buf = malloc(sizeof(char) * letters);
	red_chars = read(fd, read_buf, letters);
	wr_chars = write(STDOUT_FILENO, read_buf, red_chars);

	free(read_buf);
	close(fd);
	return (wr_chars);
}
