#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void inverse_matrix(double m[][2], double inverse [][2]);
void print_matrix(double m[][2]);

int main(void)
{
  double m[2][2], res[2][2];
  int i, j = 0;
  srand((unsigned)time(NULL));
  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  m[i][j] = rand() % 10 + 1; // 1부터 10까지 난수 생성
	}
  }
  printf("Existing matrix\n");
  print_matrix(m);
  inverse_matrix(m, res);
  printf("inverse matrix\n");
  print_matrix(res);

  return 0;
}

void inverse_matrix(double m[][2], double res[][2])
{
  int i, j = 0;
  for (i = 0; i < 2; i++)
  {
	if (i == j) // ex) (0, 0), (1, 1)
	{
	  res[i][j] = m[1 - i][1 - j] / (m[0][0] * m[1][1] - m[0][1] * m[1][0]); //  1/(ad - bc)*a, 1/(ad - bc)*d
	}
	else
	{
	  res[i][j] = -m[i][j] / (m[0][0] * m[1][1] - m[0][1] * m[1][0]); // 1/(ad - bc)*(-b), 1/(ad - bc)*(-c)
	}
  }
}

void print_matrix(double m[][2])
{
  int i, j = 0;
  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  printf("%2lf", m[i][j]);
	}
	printf("\n");
  }
}