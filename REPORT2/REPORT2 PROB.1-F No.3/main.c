#include <stdio.h>

int main(void)
{

  int hour, min, sec;
  double time = 3.76;

  hour = (int)time;
  time -= hour;
  time *= 60.0;
  min = (int) time;
  time -= min;
  time *= 60.0;
  sec = (int) time;
  printf("3.76시간은 %d는 %d분 %d초 입니다.\n", hour, min, sec);

  return 0;

}