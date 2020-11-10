#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap(char* type, void* ap, void* bp); // 함수 선언

int main(void)
{
  int age1, age2;
  double height1, height2;

  printf(" Enter the age and height of the first person : ");
  scanf("%d%lf", &age1, &height1);

  printf(" Enter the age and height of the second person : ");
  scanf("%d%lf", &age2, &height2);

  swap("int", &age1, &age2);
  swap("double", &height1, &height2); // 강제 형변환

  printf("the age and height of the first person : %d, %lf\n", age1, height1);
  printf("the age and height of the second person : %d, %lf\n", age2, height2);

  return 0;
}

void swap(char* type, void* ap, void* bp) // 함수 정의
{
  int temp;
  double dtemp; // swapping을 위해 필요한 일시적인 변수 선언

  if (strcmp(type, "int") == 0) 
  {
	temp = *(int*)ap;
	*(int*)ap = *(int*)bp;
	*(int*)bp = temp;
  }
  if (strcmp(type, "double") == 0)
  {
	dtemp = *(double*)ap;
	*(double*)ap = *(double*)bp;
	*(double*)bp = dtemp;
  }
}