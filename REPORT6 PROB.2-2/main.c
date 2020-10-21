#include <stdio.h>
#include <stdlib.h>
#define num 11 //매크로 상수 정의

/*2019012567 이성수*/

int main()
{
  int arr[num] = { 0 }; // 0으로 초기화
  int temp = 0; // 대소관계에서 순서 바꿀 변수
  int i, j;

  printf(" before line up : ");

  for (i = 0; i < 10; i++)
  {
	arr[i] = rand() % 12; // 0부터 11까지의 난수를 생성
	  printf("%5d", arr[i]); //정렬 전 배열요소 출력
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
		arr[j] = temp; // i와 j의 배열요소를 바꾼다
	  }
	}
	printf("%5d", arr[i]);
  }
  return 0;
}