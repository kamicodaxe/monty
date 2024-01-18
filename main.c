#include "monty.h"

int main(int argc, char **argv)
{
	char *m_file_path = NULL;
	int fd;

	if (argc != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	m_file_path = *(argv + 1); /* Access next string in array */

	/* Open monty file path */
	fd = open_file(m_file_path);
	read_bytes(fd);

	return (0);
}
