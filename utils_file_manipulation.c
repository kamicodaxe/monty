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
		error_open_file(path);

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_open_file(path);

	return (fd);
}

/**
 * read_bytes - read bytes from file descriptor
 * @fd: integer, file descriptor
 *
 * Return: bytes_read, ssize_t
 */
ssize_t read_bytes(int fd)
{
	ssize_t bytes_read = 0;
	char buffer[1024];

	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
		close(fd);

	printf("%s", buffer);

	return (bytes_read);
}
