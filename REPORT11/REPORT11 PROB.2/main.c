#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_assert(FILE* fp); // NULL���ڸ� ��ȯ�ϴ��� Ȯ���ϴ� �Լ�
int check_registration(char(*reg_word)[21], char* word, int cnt); // ��ϵǾ����� Ȯ���ϴ� �Լ�

int main(void)
{
  FILE* afp, * bfp, * cfp;
  char reg_word[10][21]; // ��� �ܾ��� ���̴� �ִ� 20��, ��� �ܾ� ���� 10�������̹Ƿ� 10�� 21���� ����
  char word[21]; //��� ���θ� Ȯ���� ���ڸ� ������ �迭
  int i, cnt;

  afp = fopen("a.txt", "r"); // read ���� ����
  my_assert(afp); // NULL���ڰ� �ִ��� Ȯ���ϱ� ���� �Լ� ȣ��
  bfp = fopen("b.txt", "r");
  my_assert(bfp);
  cfp = fopen("c.txt", "w"); // ���� ���� ����
  my_assert(cfp);

  for (i = 0; i < 10; i++) 
  {
	fscanf(afp, "%s", reg_word[i]);
	if (feof(afp)) // ��Ʈ�� ������ ������ ��� �о����� Ȯ���Ѵ�
	{
	  break;
	}
  }
  cnt = i; //�о���� �ܾ��� ���� cnt�� ����

  while (fscanf(bfp, "%s", word) != EOF) // �о���� �����Ͱ� EOF�� �ƴ϶�� ��
  {
	if (!check_registration(reg_word, word, cnt)) // �Լ� ȣ��
	{
	  fprintf(cfp, "%s\n", word); // ��ϵ��� ���� �ܾ ����Ѵ�
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
	if (strcmp(reg_word[i], word) == 0) // a, b ������ ���� ���� �ܾ �ִٸ� 1�� ��ȯ�Ѵ�
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