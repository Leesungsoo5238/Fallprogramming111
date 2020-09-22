#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define PI  3.141592
#define Seongsunum  2019012567
#define TRIANGLEAREA(a, b) (0.5*(a)*(b))
/*main fuction
2020. 09.13
made by Lee seongsu
*/

int main(void)
{
  student student2 = { Seongsunum, "Seongsu Lee" };
  printf("a:%lf, No.:%d, Name:%s/n", PI, student2.num, student2.name);
  printf("Triangle area:(%.41f, %.41f)=(%.41f)/n", 1.0, 3.0, TRIANGLEAREA(1.0, 3.0));
	system("pause..");
	return 0;
}