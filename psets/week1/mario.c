#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int height;
  int spaces;
  //TODO: validate input so letters don't crash program
  //get height from user and verify it is valid
  do
  {
    printf("Height:\n");
    scanf("%d", &height);
  }
  while(height < 1 || height > 8);

  //set spaces equal to one less than height
  spaces = height - 1;

  //print hashes with the appropriate amount of spaces first.
  //row for loop
  for (int i = 0; i < height; i++)
  {
    //spaces for loop
    for(int j = 0; j < spaces; j++)
    {
      printf(" ");
    }
    //left hash for loop
    for (int k = 0; k < height - spaces; k ++)
    {
      printf("#");
    }

    //print middle spaces
    printf("  ");

    //right hash for loop
    for (int k = 0; k < height - spaces; k ++)
    {
      printf("#");
    }

    //move to next row and decrement spaces
    printf("\n");
    spaces--;
  }

  return 0;
}
