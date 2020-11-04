#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

void PresentMatrix(int a_matrix[][3], const char* ap_title) // 3 by 3 ��İ��� ����ϴ� �Լ�
{
  printf("%s\n", ap_title);

  for (int y = 0; y < 3; y++)
  {
	for (int x = 0; x < 3; x++)
	  printf("%5d", a_matrix[y][x]);
	  printf("\n");
  }
  printf("\n");
}

void Add(int a[][3], int b[][3]) // 3 by 3 ����� ���� ���ϴ� �Լ�
{
  int res[3][3]; // ������ ����� ������ �迭

  for (int y = 0; y < 3; y++)
  {
	for (int x = 0; x < 3; x++)
	  res[y][x] = a[y][x] + b[y][x];
  }
  PresentMatrix(res, "3 by 3 matrix A + B = "); 
  printf("\n");
}

void Sub(int a[][3], int b[][3]) // ���� ���ϴ� �Լ�
{
  int res[3][3];

  for (int y = 0; y < 3; y++)
  {
	for (int x = 0; x < 3; x++)
	  res[y][x] = a[y][x] - b[y][x];
  }
  PresentMatrix(res, "3 by 3 matrix A - B = ");
  printf("\n");
}

void Mul(int a[][3], int b[][3]) // ���� ���ϴ� �Լ�
{
  int res[3][3], tem; // tem: ������ ����� ������ �ӽ� ����

  for (int y = 0; y < 3; y++)
  {
	for (int x = 0; x < 3; x++)
	{
	  tem = 0;
	  for (int i = 0; i < 3; i++) // �� ��Ҹ� 3���� ���ϰ� ���Ѵ�
	  {
		tem += a[y][i] * b[i][x];
		res[y][x] = tem; // �������� ����
	  }
	}
  }
  PresentMatrix(res, "3 by 3 A * B = ");
  printf("\n");
}

int main(void) // �����Լ�
{
  int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; // �迭 �ʱ�ȭ
  int b[3][3] = { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} };

  PresentMatrix(a, "matrix a");
  PresentMatrix(b, "matrix b"); // a, b�� ����� ���� ǥ���Ѵ�.

  Add(a, b); // ���� �Լ� ȣ��
  Sub(a, b); // ���� �Լ� ȣ��
  Mul(a, b); // ���� �Լ� ȣ��

  return 0;
}