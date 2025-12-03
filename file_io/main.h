#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>

/* Task 0: read a text file and print it to standard output */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1: create a file and write text_content to it */
int create_file(const char *filename, char *text_content);

/* Task 2: append text at the end of a file */
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */

