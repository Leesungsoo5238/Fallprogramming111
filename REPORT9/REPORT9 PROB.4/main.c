#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
  int i, len;
  int chk[255] = { 0 };
  char str[91]; // 90���� �̳��� ���ڸ� �Է�
  gets(str);
  len = strlen(str);
  for (i = 0; i < len; i++)
  {
	chk[str[i]]++;
  }

  for (i = 'a'; i <= 'z'; i++)
  {
	if (chk[i] > 0)
	  printf("%c:%d\n", i, chk[i]); // �Էµ� ���� Ƚ���� 0���� ū�� �˻��� �Է��� ���ڸ� ���
  }
}