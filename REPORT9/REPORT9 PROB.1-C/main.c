#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[80];
  char res_str[80];
  char* star = "*********";
  int len;

  printf("Enter the word : ");
  scanf("%s", str);
  len = strlen(str);
  
  if (len <= 5)
  {
	strcpy(res_str, str);
  }
  else
  {
	strncpy(res_str, str, 5);
	res_str[5] = '\0';
	strcat(res_str, star, len - 5);
  }
  printf("word you entered : %s, omitted word : %s\n", str, res_str);
  return 0;
}