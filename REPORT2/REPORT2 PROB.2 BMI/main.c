#include <stdio.h>

int main(void)
{
  double Weight, Height, BMI;

	printf("please enter your height and weight : ");
    scanf("%lf%lf", &Weight, &Height);

	Height = Height / 100.0;
	BMI = Weight / (Height * Height);

	((BMI >= 20.0) && (BMI < 25.0))
	  ? printf("You are normal. \n")
	  : printf("You need to lose weight. \n");

	return 0;

}