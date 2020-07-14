#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>

int main(void)
{

	double num;

	scanf("%lf", &num);

	printf("%6f\n", num * num * 3.14159265358979);
	printf("%6f", (double)(num * num * 2));

	return 0;
}