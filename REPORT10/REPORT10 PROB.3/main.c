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
  p = (int*)malloc(sizeof(int) * size); // �޸𸮸� �Ҵ��ϰ� int�� ������ �ּҷ� �� ��ȯ

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
  free(p); // �Ҵ�� �޸� �ʱ�ȭ�� ���� ��ȯ
  return 0;
}