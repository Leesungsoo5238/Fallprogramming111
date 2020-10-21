#include <stdio.h>

void swap(double *pa, double *pb);
void line_up(double *maxp, double *midp, double *minp);

int main(void)
{
  double max, mid, min;

  printf("enter three real number : ");
  scanf("%lf%lf%lf", &max, &mid, &min);
  line_up(&max, &mid, &min);
  printf("lineuped num : %.1lf, %.1lf, %.1lf\n", max, mid, min);

  return 0;

}

void swap(double *pa, double *pb)
{
  double temp; //교환을 위한 변수

  temp = *pa; // temp에 pa가 가리키는 변수 저장
  *pa = *pb; // pb가 가리키는 값을 pa가 가리키는 변수에 저장
  *pb = temp; // pb가 가리키는 변수에 temp 값을 저장
}

void line_up(double* maxp, double* midp, double* minp)
{
  if (*maxp < *midp) swap(maxp, midp); 
  if (*maxp < *minp) swap(maxp, minp);
  if (*midp < *minp) swap(midp, minp);
}