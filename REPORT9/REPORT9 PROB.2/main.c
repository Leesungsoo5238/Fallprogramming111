#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
  int ch;
  int len, max = 0;

  while (1)
  {
	len = 0;
	ch = getchar();// ���ڸ� �Է��Ѵ�
	if (ch == -1)
	  break;

	while (ch != '\n') // ������ �ƴϸ� ��� �Է�
	{
	  len++;
	  ch = getchar();
	}
	printf("Length : %d\n", len);
	if (len > max)
	  max = len;
	printf("\n");
  }
  printf("The most longest word length : %d\n", max);
  return 0;
}