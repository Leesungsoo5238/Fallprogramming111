#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
  FILE* fp1;
  FILE* fp2;

  if ((fp1 = fopen("test1.txt", "r")) == NULL)
	printf("Failed to open the test1.txt");

  if ((fp2 = fopen("test2.txt", "r")) == NULL)
	printf("Failed to open the test2.txt");

  while (1)
  {
	if (fgetc(fp1) != fgetc(fp2))
	{
	  printf("Two files are different.");
	  break;
	}
	else if ((feof(fp1) == 0 && feof(fp2) != 0) || (feof(fp1) != 0 && feof(fp2) == 0))
	{
	  printf("Two files are different.");
	}
	else if (feof(fp1) != 0 && feof(fp2) != 0)
	{
	  printf("Two files are the same.");
	  break;
	}
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}