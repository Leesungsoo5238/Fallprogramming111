#include <stdio.h>

int main(void)
{
  int a = 0;
  do
  {
	scanf("%d", &a);
  } while (a < 0);

  return 0;
}