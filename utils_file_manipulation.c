#include "monty.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * file_exists - Checks if file exist
 * @path: Path to file
 *
 * Return: 0 if exist, -1 otherwise
 */
int file_exists(char *path)
{
	struct stat sb;

	if (path == NULL)
		return (-1);

	return (stat(path, &sb));
}

/**
 * open_file - Opens a file when provided with path
 * @path: String path to the file
 *
 * Return: The int file descriptor
 */
int open_file(char *path)
{
	int fd;

	/* Check if path exists */
	if (file_exists(path) == -1)
		return (-1);

	fd = open(path, O_RDONLY);

	return (fd);
}

/**
 * read_bytes - Reads bytes from a file descriptor into a character array.
 * @fd: File descriptor from which to read.
 * @data: Pointer to a character array to store the read data.
 *
 * Description: Reads bytes from a file descriptor into the provided buffer.
 * Allocates memory for the buffer. Exits the program on read failure.
 *
 * Return: Number of bytes read on success, exits on failure.
 */
ssize_t read_bytes(int fd, char **data)
{
	struct stat st;
	ssize_t file_size, bytes_read;

	if (fstat(fd, &st) == -1)
		return (-1);

	file_size = st.st_size;

	*data = malloc(file_size + 1);
	if (!*data)
		return (-1);

	bytes_read = read(fd, *data, file_size);
	if (bytes_read == -1)
	{
		close(fd);
		free(*data);
		return (-1);
	}

	(*data)[bytes_read] = '\0';

	return (bytes_read);
}
