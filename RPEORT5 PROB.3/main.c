#include <stdio.h>

int rand2() // ���� �߻� �Լ��� �����Ѵ�.
{
  int r = rand() % 2; // 0���� 1������ ������ �����Ѵ�.
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
	if(n == rand2()) // �Է��� ���� ���� ���� ���ٸ�
	{
	  printf("true.\n"); // �´�
	}
	else
	{
	  printf("false.\n"); // Ʋ����
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