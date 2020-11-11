#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a, b;

  printf("please enter two integers : ");
  scanf("%d%d", &a, &b);
  if (a > b)
  {
	if ((a % b == 0))
	  printf("%d is divisor of %d.", b, a);
	else
	  printf("not divisor.");
  }
  else // a < b
  {
	if ((b % a) == 0)
	  printf("%d is divisor of %d", a, b);
	else
	  printf("not divisor.");
  }
  system("pause");

  return 0;
}