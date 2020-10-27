#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int ballbycompu[4]; // ��ǻ�Ͱ� ������ ���� ������ �迭
  int ballbyuser[4]; // ������� ���� ������ �迭
  int i, j; // �ݺ������� ����� ����
  int dup; // �������� ����� ����
  int round = 1; // ȸ���� ���� ���� ���� (1ȸ������ ����)
  int strike; // ��Ʈ����ũ ���� ���� ����
  int ball; // �� ���� ���� ����

  srand((unsigned)time(NULL));
  for (i = 0; i < 4; i++)
  {
	dup = (rand() % 9) + 1; // 1~9���� ���� ����
	ballbycompu[i] = dup;
	for (j = 0; j < i; j++);
	if (dup == ballbycompu[j] && i != j)
	  i--; // i�� ���� �ϳ� �ٿ� ���� ���
  }

  while (1) // Let's Go!!
  {
	printf("%dst Number baseball\n", round);
	while (1)
	{
	  printf("Enter the number 1 to 9 : ");
		scanf("%d %d %d %d", &ballbyuser[0], &ballbyuser[1],& ballbyuser[2], &ballbyuser[3]);
	  if (ballbyuser[0] < 1 || ballbyuser[0] > 9 || ballbyuser[1] < 1 || ballbyuser[1] > 9 || ballbyuser[2] < 1 || ballbyuser[2] > 9 || ballbyuser[3] < 1 || ballbyuser[3] > 9)
		// ���� �˻�
	  {
		printf("Do not enter numbers outside the range.\n");
		continue;
	  }
	  else if (ballbyuser[0] == ballbyuser[1] || ballbyuser[1] == ballbyuser[2] || ballbyuser[0] == ballbyuser[2] || ballbyuser[3] == ballbyuser[0]|| ballbyuser[3] == ballbyuser[1] || ballbyuser[3] == ballbyuser[2]) 
		// �ߺ� �˻�
	  {
		printf("Do not enter duplicate numbers. \n");
		continue;
	  }
	  break; // �˻��ϰ� �ƹ� ������ ���� ��� �ݺ� ����
	}
	strike = 0;
	ball = 0;
	for (i = 0; i < 4; i++)
	  for (j = 0; j < i; j++)
		if (ballbycompu[i] = ballbyuser[j])
		  if (i == j) // ���� ��ġ�ϰ�� (�迭�� �ּҰ� ���ٸ�)
			strike++; // ��Ʈ����ũ ���� ����
		  else // ��ġ�� �ٸ� ���
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