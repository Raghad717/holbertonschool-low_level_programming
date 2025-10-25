/**
 * rot13 - encodes a string using rot13
 * @str: string to encode
 * Return: pointer to the encoded string
 */
char *rot13(char *str)
{
	char *ptr = str;
	int i;

	while (*ptr)
	{
		i = 0;
		while (i < 52)
		{
			if (*ptr == "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[i])
			{
				*ptr = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"[i];
				break;
			}
			i++;
		}
		ptr++;
	}
	return (str);
}

