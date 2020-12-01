#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_assert(FILE* fp); // NULL문자를 반환하는지 확인하는 함수
int check_registration(char(*reg_word)[21], char* word, int cnt); // 등록되었는지 확인하는 함수

int main(void)
{
  FILE* afp, * bfp, * cfp;
  char reg_word[10][21]; // 모든 단어의 길이는 최대 20자, 등록 단어 수는 10개까지이므로 10행 21열로 선언
  char word[21]; //등록 여부를 확인할 문자를 저장할 배열
  int i, cnt;

  afp = fopen("a.txt", "r"); // read 모드로 개방
  my_assert(afp); // NULL문자가 있는지 확인하기 위해 함수 호출
  bfp = fopen("b.txt", "r");
  my_assert(bfp);
  cfp = fopen("c.txt", "w"); // 쓰기 모드로 개방
  my_assert(cfp);

  for (i = 0; i < 10; i++) 
  {
	fscanf(afp, "%s", reg_word[i]);
	if (feof(afp)) // 스트림 파일의 내용을 모두 읽었는지 확인한다
	{
	  break;
	}
  }
  cnt = i; //읽어들인 단어의 수를 cnt에 저장

  while (fscanf(bfp, "%s", word) != EOF) // 읽어들인 데이터가 EOF가 아니라면 참
  {
	if (!check_registration(reg_word, word, cnt)) // 함수 호출
	{
	  fprintf(cfp, "%s\n", word); // 등록되지 않은 단어를 기록한다
	}
  }

  fclose(afp);
  fclose(bfp);
  fclose(cfp);

  return 0;
}

int check_registration(char(*reg_word)[21], char* word, int cnt)
{
  int i;
  
  for (i = 0; i < cnt; i++)
  {
	if (strcmp(reg_word[i], word) == 0) // a, b 파일을 비교해 같은 단어가 있다면 1을 반환한다
	{
	  return 1;
	}
  }

  return 0;
}

void my_assert(FILE* fp)
{
  if (fp == NULL)
  {
	printf("Failed to open the file!!\n");
	exit(1);
  }
}