#include <stdio.h>
/*recursive call fuction*/

int rec_sum(int n); // 1���� n������ ���� ��ȯ�ϴ� �Լ�.

int main(void)
{
  int res;
  res = rec_sum(10); // �Լ� ȣ��, 1���� 10���� ���� res�� �����Ѵ�.
  printf("result : %d\n", res); //res���� ����Ѵ�.

  return 0;
}
int rec_sum(int n) // ���ȣ��
{
  if (n == 1) return 1; // �Է��� ���� 1�̸� �� ���� 1�̹Ƿ� 1�� ��ȯ
  else return(n + rec_sum(n - 1)); // 1�� �ƴ϶�� �� ���
}
