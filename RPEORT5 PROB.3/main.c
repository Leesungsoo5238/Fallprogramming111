#include <stdio.h>

int rand2() // 난수 발생 함수를 정의한다.
{
  int r = rand() % 2; // 0부터 1까지의 난수를 생성한다.
  return r;
}
int main()
{
  int n;
  char c;
  while (1)
  {
	printf("enter the front/back(1/0)");
	scanf("%d", &n);
	if(n == rand2()) // 입력한 값이 난수 값과 같다면
	{
	  printf("true.\n"); // 맞다
	}
	else
	{
	  printf("false.\n"); // 틀리다
	}
	printf("Do you want continue? (y/n)");
	scanf("%c", &c);
	if (c == 'n')
	{
	  break;
	}
  }
  return 0;
}