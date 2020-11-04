#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

void PresentMatrix(int a_matrix[][3], const char* ap_title) // 3 by 3 행렬값을 출력하는 함수
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

void Add(int a[][3], int b[][3]) // 3 by 3 행렬의 합을 구하는 함수
{
  int res[3][3]; // 연산의 결과를 저장할 배열

  for (int y = 0; y < 3; y++)
  {
	for (int x = 0; x < 3; x++)
	  res[y][x] = a[y][x] + b[y][x];
  }
  PresentMatrix(res, "3 by 3 matrix A + B = "); 
  printf("\n");
}

void Sub(int a[][3], int b[][3]) // 차를 구하는 함수
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

void Mul(int a[][3], int b[][3]) // 곱을 구하는 함수
{
  int res[3][3], tem; // tem: 연산의 결과를 저장할 임시 변수

  for (int y = 0; y < 3; y++)
  {
	for (int x = 0; x < 3; x++)
	{
	  tem = 0;
	  for (int i = 0; i < 3; i++) // 각 요소를 3번씩 곱하고 더한다
	  {
		tem += a[y][i] * b[i][x];
		res[y][x] = tem; // 연산결과를 저장
	  }
	}
  }
  PresentMatrix(res, "3 by 3 A * B = ");
  printf("\n");
}

int main(void) // 메인함수
{
  int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; // 배열 초기화
  int b[3][3] = { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} };

  PresentMatrix(a, "matrix a");
  PresentMatrix(b, "matrix b"); // a, b의 행렬을 먼저 표시한다.

  Add(a, b); // 덧셈 함수 호출
  Sub(a, b); // 뺄셈 함수 호출
  Mul(a, b); // 곱셈 함수 호출

  return 0;
}