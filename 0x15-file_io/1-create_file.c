#include "main.h"

/**
 * create_file - Function to create a file
 * @filename: The file to be created
 * @text_content: String to write to the file
 *
 * Return: -1 if NULL, truncate if file exists
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, _write, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	_write = write(fd, text_content, length);

	if (fd == -1 || _write == -1)
		return (-1);

	close(fd);

	return (1);
}
