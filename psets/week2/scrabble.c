#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int getpos(char c);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2)
        printf("Tie!\n");
    else if (score1 > score2)
        printf("Player 1 wins!\n");
    else
        printf("Player 2 wins!\n");
}

//for each letter in word, find position, and if valid add to total
int compute_score(string word)
{
    int total = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        //checks if the position is -1, which adds 0 to the total for an invalid character, or a valid number that indicates the corresponding index in POINTS to add to total
        if (getpos(word[i]) < 0)
            total += 0;
        else
        {
            total += POINTS[getpos(word[i])];
        }
    }
    return total;
}

// finds the position of a character in 0-indexed alphabet
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