#include <stdio.h>
#include <stdlib.h>
#define num 11 //��ũ�� ��� ����

/*2019012567 �̼���*/

int main()
{
  int arr[num] = { 0 }; // 0���� �ʱ�ȭ
  int temp = 0; // ��Ұ��迡�� ���� �ٲ� ����
  int i, j;

  printf(" before line up : ");

  for (i = 0; i < 10; i++)
  {
	arr[i] = rand() % 12; // 0���� 11������ ������ ����
	  printf("%5d", arr[i]); //���� �� �迭��� ���
  }
  printf("\nafter line up: ");
  for (i = 0; i < 10; i++)
  {
	{
	for(j = i; j < 10; j++)
	  if (arr[i] < arr[j])
	  {
		temp = arr[i]; 
		arr[i] = arr[j];
		arr[j] = temp; // i�� j�� �迭��Ҹ� �ٲ۴�
	  }
	}
	printf("%5d", arr[i]);
  }
  return 0;
}