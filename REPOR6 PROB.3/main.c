#include <stdio.h>

void input_nums(int* lotto_nums); //배열에 로또 번호를 입력하는 함수
void print_nums(int* lotto_nums); //배열에 저장된 값을 출력하는 함수

int main(void)
{
  int lotto_nums[6];// 로또 번호를 저장할 배열

	input_nums(lotto_nums); // 입력함수 호출
	print_nums(lotto_nums); // 출력함수 호출
	return 0;
}
void input_nums(int* lotto_nums)// 함수에서 사용할때 반드시 포인터 형태로 받아야함
{
  int num;
  int i, j;
  int dup;

  for (i = 0; i < 6; i++) // 6개의 수를 입력받아 배열에 저장하는 반복문
  {
	printf("enter number : ");
	scanf("%d", &num);
	dup = 0; // 플래그 변수
	for (j = 0; j < i; j++)
	{
	  if (num == lotto_nums[j])
	  {
		dup = 1;
		  break;
	  }
	}
	if(!dup)
	{
	  lotto_nums[i] = num;
	}
	else
	{
	  printf("You have same number!\n");
	  i--; 
	}
  }
}

void print_nums(int* lotto_nums)
{
  int i;

  printf("lotto number : ");
	for (i = 0; i < 6; i++)
	{
	  printf("%d", lotto_nums[i]);
    }
}
