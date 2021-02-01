#include <stdio.h>

int main(void)
{
  int x;
  int y;
  int total;

  //prompt user for x value and store
  printf("Enter an integer for X: ");
  scanf("%d", &x);

  //prompt user for y value and store
  printf("Enter an integer for Y: ");
  scanf("%d", &y);

  //calculate and display total
  total = x + y;
  printf("The total of X and Y is: %d\n", total);
  return 0;
}
