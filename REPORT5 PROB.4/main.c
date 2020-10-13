#include <stdio.h>
#include <math.h>

/*Euclidean distance, Made by SEONGSU LEE*/

typedef struct { double x; double y; } point; // 2차원 좌표의 점을 표현하기 위한 구조체 point를 정의한다.

double dist(point p1, point p2)
{
  return(sqrt((double)(p2.x - p1.x)*(p2.x - p1.x) + (double)(p2.y - p1.y)*(p2.y - p1.y)));
  // 두 점 사이의 유클리디언 거리를 구하는 공식
}
int main(void)
{
  point p1, p2; // point형의 변수 p1, p2를 지정한다.
  double result; // 거리값을 저장하기 위한 변수 result를 지정한다.
  scanf("%lf %lf", &p1.x, &p1.y); // p1의 좌표를 입력받는다.
  scanf("%lf %lf", &p2.x, &p2.y); // p2의 좌표를 입력받는다.

  result = dist(p1, p2); // p1, p2점의 유클리디언 거리를 계산하여 result에 저장한다.

  printf("Distance of two point is %.1lf\n", result);

  return 0;
}