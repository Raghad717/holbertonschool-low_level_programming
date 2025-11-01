#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generate_password - Generates a random password
 * @password: Buffer to store password
 * @length: Length of password
 */
void generate_password(char *password, int length)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charset_size = sizeof(charset) - 1;
    int i;
    
    for (i = 0; i < length; i++)
    {
        password[i] = charset[rand() % charset_size];
    }
    password[length] = '\0';
}

/**
 * main - Generates random valid passwords for 101-crackme
 * Return: Always 0
 */
int main(void)
{
    int i;
    char password[100];
    
    srand(time(NULL));
    
    for (i = 0; i < 10; i++)  // Try 10 different passwords
    {
        int len = rand() % 20 + 5;  // Random length 5-24
        generate_password(password, len);
        printf("%s\n", password);
    }
    
    return (0);
}
