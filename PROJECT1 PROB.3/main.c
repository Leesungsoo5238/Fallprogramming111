#include <stdio.h>

int main(void)
{
  int y;
  printf("Please enter the year");
  scanf("%d", &y);
  if(((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) // �������� �Ǵ��ϴ� ����
	printf("%d year is leap year.\n", y);

  else
  {
	printf("%d year isn't leap year", y);
  }
  return 0;
}