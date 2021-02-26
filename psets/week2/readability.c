#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int colemanLiau(string s);

int main(void)
{
	//get string and send to colemanLiau funct for grade calc
	string s = get_string("Text: ");
	int grade = colemanLiau(s);

	//display appropriate grade
	if (grade < 1)
		printf("\nBefore Grade 1\n");
	else if (grade >= 16)
		printf("\nGrade 16+\n");
	else
		printf("\nGrade %d\n", grade);
}

int colemanLiau(string s)
{
	int letterCount = 0;
	int wordCount = 1;
	int sentenceCount = 0;

	//iterate through string and count letters, words, and sentences
	for (int i = 0; i < strlen(s); i++)
	{
		if (isalpha(s[i]))
			letterCount++;
		else if (s[i] == ' ')
			wordCount++;
		else if (s[i] == '.' || s[i] == '!' || s[i] == '?')
			sentenceCount++;
	}

	//calculate per 100 word constant for L and S calculations
	float perHundred = 100.0 / wordCount;

	//calculate Coleman-Liau index
	float index = 0.0588 * (letterCount * perHundred) - 0.296 * (sentenceCount * perHundred) - 15.8;

	//round to nearest int for grade determination
	return round(index);
}