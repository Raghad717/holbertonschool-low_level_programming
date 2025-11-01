#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number string
 * @n2: Second number string  
 * @r: Buffer to store result
 * @size_r: Buffer size
 *
 * Return: Pointer to result or 0 if error
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, carry = 0, sum, i, j, k;
    
    /* Get lengths of both numbers */
    while (n1[len1]) len1++;
    while (n2[len2]) len2++;
    
    /* Check if result can fit in buffer */
    if (len1 + 2 > size_r && len2 + 2 > size_r)
        return (0);
    
    i = len1 - 1;
    j = len2 - 1;
    k = 0;
    
    /* Add digits from right to left */
    while (i >= 0 || j >= 0 || carry)
    {
        if (k >= size_r - 1)
            return (0);
            
        sum = carry;
        if (i >= 0)
            sum += n1[i--] - '0';
        if (j >= 0)
            sum += n2[j--] - '0';
            
        carry = sum / 10;
        r[k++] = (sum % 10) + '0';
    }
    
    r[k] = '\0';
    
    /* Reverse the result string */
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        char temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
    
    return (r);
}
