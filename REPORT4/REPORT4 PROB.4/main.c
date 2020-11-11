#include <stdio.h>

int main(void)
{

  int a, b, sum = 0;
  int n;

  printf("enter the two integer : ");
  scanf("%d%d", &a, &b);

  if(a <= b)
	for (n = a; n <= b; n++) // n이 a와 같은 값으로 시작하여 b보다 작거나 같을 때 까지 하나 씩 커지며 반복
	{
	  sum = sum + n; // sum값에 n을 더해 좌항 sum에 저장한다.
	}
  else // a > b
	for (n = b; n <= a; n++)
	{
	  sum = sum + n;
	}
  printf("sum = %d\n", sum);
	return 0;
}