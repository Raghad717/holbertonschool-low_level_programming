#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme
 * Return: Always 0
 */
int main(void)
{
    int i, j;
    char password[100];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charset_size = sizeof(charset) - 1;
    
    srand(time(NULL));
    
    /* Generate multiple passwords with different strategies */
    
    /* Strategy 1: Simple random passwords */
    for (i = 0; i < 5; i++)
    {
        int len = rand() % 15 + 8;
        for (j = 0; j < len; j++)
        {
            password[j] = charset[rand() % charset_size];
        }
        password[len] = '\0';
        printf("%s\n", password);
    }
    
    /* Strategy 2: Try common patterns */
    printf("password123\n");
    printf("admin123\n"); 
    printf("test123\n");
    printf("holberton\n");
    printf("school123\n");
    
    return (0);
}
