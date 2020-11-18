#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int num; // 학번
  char name[20]; // 이름
  int kor, eng, mat; // 3과목 점수
  int tot; // 총점
  double avg; // 평균
  char grade; // 학점
} Student;

void input_data(Student* pary);
void calc_data(Student* pary);
void sort_data(Student* pary);
void print_data(Student* pary);

int main(void)
{
  Student ary[5];

  input_data(ary); // 학생 5명의 성적
  calc_data(ary); // 총전, 평균, 학점 계산

  printf("Data before sorting\n");
  print_data(ary); // 정렬 전 데이터 출력
  sort_data(ary); // 총점 순으로 내림차순 정렬
  printf("Data after sorting\n");
  print_data(ary); // 정렬 후 데이터 출력

  return 0;
}

void input_data(Student* pary)
{
  int i;
  
  for (i = 0; i < 5; i++)
  {
	printf("> student number : ");
	scanf("%d", &pary->num);
	printf("> name ");
	scanf("%s", pary->name);
	printf("> korean, english, math score : ");
	scanf("%d%d%d", &pary->kor, &pary->eng, &pary->mat);

	pary++;
  }
}

void calc_data(Student* pary)
{
  int i;

  for (i = 0; i < 5; i++)
  {
	pary->tot = pary->kor + pary->eng + pary->mat;
	pary->avg = pary->tot / 3.0;
	if (pary->avg >= 90.0) pary->grade = 'A';
	else if (pary->avg >= 80.0) pary->grade = 'B';
	else if (pary->avg >= 70.0) pary->grade = 'C';
	else pary->grade = 'F';
	pary++;
  }
}

void sort_data(Student* pary)
{
  Student temp;
  int i, j;
  int max;

  for (i = 0; i < 4; i++)
  {
	max = i;
	for (j = i + 1; j < 5; j++)
	{
	  if (pary[max].tot < pary[j].tot)
	  {
		max = j;
	  }
	}
	if (max != i)
	{
	  temp = pary[max];
	  pary[max] = pary[i];
	  pary[i] = temp; // 값 교환
	}
  }
}

void print_data(Student* pary)
{
  int i;
  
  for (i = 0; i < 5; i++)
  {
	printf("%5d%7s%5d%5d%5d%5d%7.1lf%5c\n", pary->num, pary->name, pary->kor, pary->eng, pary->mat, pary->tot, pary->avg, pary->grade);
	pary++;
  }
}