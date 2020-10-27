#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int ballbycompu[4]; // 컴퓨터가 생성한 수를 저장할 배열
  int ballbyuser[4]; // 사용자의 수를 저장할 배열
  int i, j; // 반복문에서 사용할 변수
  int dup; // 난수에서 사용할 변수
  int round = 1; // 회차를 세기 위한 변수 (1회차부터 시작)
  int strike; // 스트라이크 세기 위한 변수
  int ball; // 볼 세기 위한 변수

  srand((unsigned)time(NULL));
  for (i = 0; i < 4; i++)
  {
	dup = (rand() % 9) + 1; // 1~9까지 난수 생성
	ballbycompu[i] = dup;
	for (j = 0; j < i; j++);
	if (dup == ballbycompu[j] && i != j)
	  i--; // i의 값을 하나 줄여 실행 취소
  }

  while (1) // Let's Go!!
  {
	printf("%dst Number baseball\n", round);
	while (1)
	{
	  printf("Enter the number 1 to 9 : ");
		scanf("%d %d %d %d", &ballbyuser[0], &ballbyuser[1],& ballbyuser[2], &ballbyuser[3]);
	  if (ballbyuser[0] < 1 || ballbyuser[0] > 9 || ballbyuser[1] < 1 || ballbyuser[1] > 9 || ballbyuser[2] < 1 || ballbyuser[2] > 9 || ballbyuser[3] < 1 || ballbyuser[3] > 9)
		// 범위 검사
	  {
		printf("Do not enter numbers outside the range.\n");
		continue;
	  }
	  else if (ballbyuser[0] == ballbyuser[1] || ballbyuser[1] == ballbyuser[2] || ballbyuser[0] == ballbyuser[2] || ballbyuser[3] == ballbyuser[0]|| ballbyuser[3] == ballbyuser[1] || ballbyuser[3] == ballbyuser[2]) 
		// 중복 검사
	  {
		printf("Do not enter duplicate numbers. \n");
		continue;
	  }
	  break; // 검사하고 아무 문제가 없을 경우 반복 종료
	}
	strike = 0;
	ball = 0;
	for (i = 0; i < 4; i++)
	  for (j = 0; j < i; j++)
		if (ballbycompu[i] = ballbyuser[j])
		  if (i == j) // 같은 위치일경우 (배열의 주소가 같다면)
			strike++; // 스트라이크 개수 증가
		  else // 위치가 다를 경우
			ball++;

	printf("(result) strikes : %d, balls : %d\n\n", strike, ball);
	if (strike == 3)
	{
	  printf("You are win!! \n\n");
	  break;
	}
	else if (round == 9)
	{
	  printf("You are defeated...right answer : %d %d %d %d....\n\n", ballbycompu[0], ballbycompu[1], ballbycompu[2], ballbycompu[3]);
	  break;
	}
	round++;
  }
  return 0;
}