#include <stdio.h>
#define MAX 100
void readPolynomial(int poly[ ], int degree) 
{
	int i;
	printf("Enter the coefficients of the polynomial (from constant term to highest degree):\n");
	for (i = 0; i <= degree; i++) 
	{
		printf("Coefficient of x^%d: ", i);
		scanf("%d", &poly[i]);
	}
}
void displayPolynomial(int poly[], int degree) 
{
	printf("The polynomial is: ");
	int i ;
	for (i = degree; i >= 0; i--) 
	{
		if (poly[i] != 0) 
		{
			if (i != degree && poly[i] > 0) 
			{
				printf("+");
			}
			if (i == 0) 
			{
				printf("%d", poly[i]);
			}
			else if (i == 1) 
			{
				printf("%dx", poly[i]);
			}
			else 
			{
				printf("%dx^%d", poly[i], i);
			}
		}
	}
	printf("\n");
}
int main() 
{
	int poly[MAX], degree;
	printf("Enter the degree of the polynomial: ");
	scanf("%d", &degree);
	readPolynomial(poly, degree);
	displayPolynomial(poly, degree);
	return 0;
}
