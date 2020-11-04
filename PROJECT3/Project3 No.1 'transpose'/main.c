#include <stdio.h>

void transpose(int m[][3], int row);
void print_matrix(int m[][3], int row_size, int col_size); // �Լ� ����


int main(void)
{
  int m[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  printf("Before transpose\n");
  print_matrix(m, 3, 3); // �Լ� ȣ��
  printf("After transpose\n");
  transpose(m, 3); // �Լ� ȣ��

  return 0;
}

void transpose(int m[][3], int row) // ���� ��� �Լ� ����
{
  int i, j;
  int tem[3][3];
  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  tem[j][i] = m[i][j];
	}
  }
  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  m[i][j] = tem[i][j];
	}
  }
  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  printf("%2d", m[i][j]);
	}
	printf("\n");
  }
}

void print_matrix(int m[][3], int row_size, int col_size)
{
  int i, j;
  for (i = 0; i < row_size; i++)
  {
	for (j = 0; j < col_size; j++)
	  printf("%2d", m[i][j]);
	printf("\n");
  }
  
}