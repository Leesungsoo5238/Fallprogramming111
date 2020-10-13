#include <stdio.h>
/*recursive call fuction*/

int rec_sum(int n); // 1부터 n까지의 합을 반환하는 함수.

int main(void)
{
  int res;
  res = rec_sum(10); // 함수 호출, 1부터 10까지 합을 res에 저장한다.
  printf("result : %d\n", res); //res값을 출력한다.

  return 0;
}
int rec_sum(int n) // 재귀호출
{
  if (n == 1) return 1; // 입력한 값이 1이면 총 합이 1이므로 1을 반환
  else return(n + rec_sum(n - 1)); // 1이 아니라면 합 출력
}
