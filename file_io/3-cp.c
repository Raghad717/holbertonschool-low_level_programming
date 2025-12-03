#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exits with codes 97-100 on errors
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t r_bytes, w_bytes;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        if (close(fd_from) == -1)
            dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(99);
    }

    while ((r_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        w_bytes = write(fd_to, buffer, r_bytes);
        if (w_bytes != r_bytes)
        {
            dprintf(STDERR_FILENO, "Error: Can't_

