#include <stdio.h>
#include <math.h>

/*Euclidean distance, Made by SEONGSU LEE*/

typedef struct { double x; double y; } point; // 2���� ��ǥ�� ���� ǥ���ϱ� ���� ����ü point�� �����Ѵ�.

double dist(point p1, point p2)
{
  return(sqrt((double)(p2.x - p1.x)*(p2.x - p1.x) + (double)(p2.y - p1.y)*(p2.y - p1.y)));
  // �� �� ������ ��Ŭ����� �Ÿ��� ���ϴ� ����
}
int main(void)
{
  point p1, p2; // point���� ���� p1, p2�� �����Ѵ�.
  double result; // �Ÿ����� �����ϱ� ���� ���� result�� �����Ѵ�.
  scanf("%lf %lf", &p1.x, &p1.y); // p1�� ��ǥ�� �Է¹޴´�.
  scanf("%lf %lf", &p2.x, &p2.y); // p2�� ��ǥ�� �Է¹޴´�.

  result = dist(p1, p2); // p1, p2���� ��Ŭ����� �Ÿ��� ����Ͽ� result�� �����Ѵ�.

  printf("Distance of two point is %.1lf\n", result);

  return 0;
}