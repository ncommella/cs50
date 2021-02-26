#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int letterCount = 0;
	int wordCount = 1;

	string s = get_string("Text: ");
	printf("\nOutput: ");
	for (int i = 0; i < strlen(s); i++)
	{
		printf("%c", s[i]);
		if (isalpha(s[i]))
			letterCount++;
		else if (s[i] == ' ')
			wordCount++;
	}
	printf("\nLetter count: %d\nWord count: %d\n", letterCount, wordCount);
}

void colemanLiau(string s)
{
	for (int i = 0;)
}