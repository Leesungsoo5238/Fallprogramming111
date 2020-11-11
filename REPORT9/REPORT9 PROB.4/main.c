#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
  int i, len;
  int chk[255] = { 0 };
  char str[91]; // 90글자 이내의 글자만 입력
  gets(str);
  len = strlen(str);
  for (i = 0; i < len; i++)
  {
	chk[str[i]]++;
  }

  for (i = 'a'; i <= 'z'; i++)
  {
	if (chk[i] > 0)
	  printf("%c:%d\n", i, chk[i]); // 입력된 문자 횟수가 0보다 큰지 검사해 입력한 문자만 출력
  }
}