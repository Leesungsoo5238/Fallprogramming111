#include <stdio.h>
int main(void)
{
  int m; // The 'm' means month

	printf("please enter the month that you want : ");
    scanf("%d", &m);

	switch (m) // 입력한 달(m)에 따라 스위치문 작성
	{
	  case 3:
	  
	  case 4:
	 
	  case 5:
      
		printf("Entered %d is spring", m);
	  
		break;
	  
	  case 6:
	 
	  case 7:
	 
	  case 8:

		printf("Entered %d is summer", m);
		
		break;

	  case 9:
	 
	  case 10:
	  
	  case 11:

		printf("Entered %d is autumn", m);
		
		break;

	  case 12:
	 
	  case 1:
	  
	  case 2:

		printf("Entered %d is winter", m);
		
		break;

	  default:
		printf("Yot entered the wrong month.\n");
     }
	return 0;
}