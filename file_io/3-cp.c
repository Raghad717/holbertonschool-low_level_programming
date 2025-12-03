#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints error message and exits with specified code
 * @code: exit code
 * @msg: error message
 * @arg: argument for the message
 * @fd: file descriptor (if applicable)
 */
void error_exit(int code, const char *msg, const char *arg, int fd)
{
	if (fd != -1)
		dprintf(STDERR_FILENO, msg, arg, fd);
	else
		dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd - closes a file descriptor and handles errors
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies content from one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source filename for error messages
 * @file_to: destination filename for error messages
 */
void copy_file(int fd_from, int fd_to, const char *file_from, const char *file_to)
{
	ssize_t r_bytes, w_bytes;
	char buffer[BUFFER_SIZE];

	while ((r_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			error_exit(99, "Error: Can't write to %s\n", file_to, -1);
		}
	}

	if (r_bytes == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", file_from, -1);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: arguments array
 *
 * Return: 0 on success, exits with codes 97, 98, 99, or 100 on errors
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	int flags = O_WRONLY | O_CREAT | O_TRUNC;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "", -1);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1], -1);

	fd_to = open(argv[2], flags, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		error_exit(99, "Error: Can't write to %s\n", argv[2], -1);
	}

	copy_file(fd_from, fd_to, argv[1], argv[2]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
