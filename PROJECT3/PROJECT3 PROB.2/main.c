#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // 2차원 좌표를 표현하기 위해 사용

int main(void)
{
  double slope;
  double bias;
  double pointx, pointy;

  printf("Enter the slope(a) and bias(b) in y = ax + b ");

  scanf("%lf %lf", &slope, &bias);

  double A, B;
  A = -1 / slope;
  B = bias / slope;

  printf("y = %.1lfx + %.1lf -> x + %.1lfy + %.1lf + 0\n", slope, bias, A, B); // 직선의 함수를 일반형으로 바꾸기
  printf("input point a : ");
  scanf("%lf%lf", &pointx, &pointy);
  printf("point a coordinates(%.1lf, %.1lf)\n", pointx, pointy);

  double C = (1 + (A * A));
  double D = pointx + (A * pointy) + B;
  double dis;

  printf("(AH vector)^2 = d^2\n");;

  dis = fabs(D) / sqrt(C);
  printf("The shortest distane : %.1lf", dis);

  return 0;
}