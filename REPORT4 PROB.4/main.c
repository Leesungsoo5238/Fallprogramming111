#include <stdio.h>

int main(void)
{

  int a, b, sum = 0;
  int n;

  printf("enter the two integer : ");
  scanf("%d%d", &a, &b);

  if(a <= b)
	for (n = a; n <= b; n++) // n�� a�� ���� ������ �����Ͽ� b���� �۰ų� ���� �� ���� �ϳ� �� Ŀ���� �ݺ�
	{
	  sum = sum + n; // sum���� n�� ���� ���� sum�� �����Ѵ�.
	}
  else // a > b
	for (n = b; n <= a; n++)
	{
	  sum = sum + n;
	}
  printf("sum = %d\n", sum);
	return 0;
}