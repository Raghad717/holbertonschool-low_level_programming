#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>

/* Task 0 */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1 */
int create_file(const char *filename, char *text_content);

#endif /* MAIN_H */

