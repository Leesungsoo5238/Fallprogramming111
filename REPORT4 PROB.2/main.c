#include <stdio.h>
int main(void)
{
  int num;
  int i, j;
  int pn; // prime number
  int cnt = 0; // Initialize to zero
  printf("Enter an integer greater than or equal to 2 : ");
	scanf("%d", &num);
  for (i = 2; i <= num; i++)
  {
	pn = 1; // � ���� �Ҽ���� �����ϰ� �����Ѵٴ� �ǹ�
	for (j = 2; j < i; j++) //
	{
	  if ((i % j) == 0)
	  {
		pn = 0;
		break;
	  }
	}
	if (pn == 1)
	{
	  printf("%5d", i);
	  cnt++;
	  if ((cnt % 5) == 0)
	  {
		printf("\n");
	  }
	}
  }
  return 0;
}