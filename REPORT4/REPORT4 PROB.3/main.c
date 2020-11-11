#include <stdio.h>

int main(void)
{
  int a = 0;
  int row = 0;
  int i, j;

  printf("enter the two integer : ");
  scanf("%d%d", &a, &row);

  for (i = 0; i < a; i++)
  {
	for (j = 0; j < row; j++)
	{
	  printf("*");
	}
	printf("\n");
  }

  return 0;
}