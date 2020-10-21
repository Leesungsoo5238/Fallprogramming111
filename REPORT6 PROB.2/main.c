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
  double temp; //��ȯ�� ���� ����

  temp = *pa; // temp�� pa�� ����Ű�� ���� ����
  *pa = *pb; // pb�� ����Ű�� ���� pa�� ����Ű�� ������ ����
  *pb = temp; // pb�� ����Ű�� ������ temp ���� ����
}

void line_up(double* maxp, double* midp, double* minp)
{
  if (*maxp < *midp) swap(maxp, midp); 
  if (*maxp < *minp) swap(maxp, minp);
  if (*midp < *minp) swap(midp, minp);
}