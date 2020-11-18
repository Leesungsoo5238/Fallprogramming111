#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < stdlib.h>

int main(void)
{
  int size = 0;
  int i;
  int* p;
  int sum = 0;
  printf("Number of integers");
  scanf("%d", &size);
  p = (int*)malloc(sizeof(int) * size); // 메모리를 할당하고 int형 변수의 주소로 형 변환

  for (i = 0; i < size; i++)
  {
	printf("Enter integers : ");
	scanf("%d", &p[i]);
  }

  for (i = 0; i < size; i++)
  {
	sum = sum + p[i];
  }
  printf("Sum is %d.\n", sum);
  free(p); // 할당된 메모리 초기화를 위해 반환
  return 0;
}