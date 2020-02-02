#include "sort.h"

/**
 * _strlen - return the number of char
 * @str: input string
 *
 * Description: return the number os char in a string
 * Return: len, number oh char
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * create_file - create or write file
 * @filename: input file name
 * @text_content: input string
 *
 * Description: function that create a file and write the content
 * Return: void
 */

int create_file(const char *filename, char *text_content)
{
	int len, file_o, file_w;

	if (filename == NULL)
		return (-1);

	file_o = open(filename, O_CREAT | O_TRUNC | O_WRONLY);

	if (file_o == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = _strlen(text_content);
		file_w = write(file_o, text_content, len);

		if (file_w == -1)
			return (-1);
	}

	return (1);

}
