#include <stdio.h>

int main(void)
{
  int starting_pop;
  int ending_pop;
  int count_years = 0;
  int current_pop; // used so we can display starting at end

  //get starting population from user
  do
  {
    printf("Enter a starting population greater than 9:\n");
    scanf("%d", &starting_pop);
  }
  while(starting_pop < 9);

  //get ending population from user
  do
  {
    printf("Enter an ending population at least as big as your starting population:\n");
    scanf("%d", &ending_pop);
  }
  while(ending_pop < starting_pop);


  //calculate number of years using n = n + n/3 - n/4
  current_pop = starting_pop;
  while (current_pop < ending_pop) {
    current_pop = current_pop + (current_pop / 3) - (current_pop / 4);
    count_years++;
  }

  //display results and return
  printf("It will take %d years for %d llamas to become %d llamas!\n", count_years, starting_pop, ending_pop);

  return 0;
}
