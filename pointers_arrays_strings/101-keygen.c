#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme
 * Return: Always 0
 */
int main(void)
{
    char password[20];
    int i;
    
    srand(time(NULL));
    
    /* Generate exactly one password */
    for (i = 0; i < 10; i++)
    {
        password[i] = 'A' + (rand() % 26);
    }
    password[10] = '\0';
    
    printf("%s", password);
    return (0);
}
