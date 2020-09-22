#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num;

  printf("enter Number : ");
  scanf("%d", &num);

  if (num % 2 == 0) // If the remainder is 0 when divided by 2
  {
	printf("An even number\n");
  }
  else if (num % 2 == 1) // When the remainder is 1
  {
	printf("An odd number\n");
  }

  system("pause");

  return 0;
}