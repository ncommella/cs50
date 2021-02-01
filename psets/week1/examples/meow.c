#include <stdio.h>

//prototypes
void meow(int time);

int main(void)
{
  meow(3);
}

void meow(int time)
{
  for (int i = 0; i < time; i++)
  {
    printf("meow\n");
  }
}
