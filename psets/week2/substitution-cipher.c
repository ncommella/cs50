#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void subCipher(string key);
int getpos(char c);

int main(int argc, string argv[])
{
    //check for key in cli argument
	if (argc != 2)
	{
		printf("User must provide key e.g. ./substitution KEY\n");
		return 1;
	}

    //check that key is 26 chars long and all alpha chars
    int n = strlen(argv[1]);
    if (n != 26)
    {
        printf("Key must be 26 characters long.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must only contain alphabetical characters!\n");
                return 1;
            }
        }
    }
    //put key in arg into string and pass to cipher funct.
    string key = argv[1];
    subCipher(key);
		
}

void subCipher(string key)
{
    //get plain text string from user
    string plainText = get_string("plaintext: ");


    printf("ciphertext: ");
    for (int i = 0; i < strlen(plainText); i++)
    {
        //if the character is non-alpha, just print the character as is
        if (getpos(plainText[i]) < 0)
            printf("%c", plainText[i]);

        //prints ciphered char according to key in correct case
        else if (isupper(plainText[i]))
        {
            printf("%c", toupper(key[getpos(plainText[i])]));
        }
        else
            printf("%c", tolower(key[getpos(plainText[i])]));
        
    }
    printf("\n");
}

//finds position of alpha char in 0-indexed alphabet, returns -1 for non-alpha chars
int getpos(char c)
{
    int pos;
    const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    const char* found;

    //lowers input to make it case-insensitive
    c = tolower((unsigned char)c);
    found = strchr(alphabet, c);
    pos = found - alphabet;

    //Input validation that returns -1 for invalid char
    if (!found)
        pos = -1;
    else if (pos == 26)
        pos = -1;
    return pos;
}