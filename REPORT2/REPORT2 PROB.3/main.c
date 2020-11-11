#include <stdio.h>


int main(void)
{
  int a, b;

  printf("please enter any number : ");
  scanf("%d%d", &a, &b);
  printf("%d + %d = %d \n", a, b, a + b);
  printf("%d - %d = %d \n", a, b, a - b);
  printf("%d * %d = %d \n", a, b, a * b);
  printf("%lf / %lf = %.4lf \n", (double)a, (double)b, (double)a / (double)b);
  printf("remainder = %d \n", a % b);

  return 0;
}
