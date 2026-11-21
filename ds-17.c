#include <stdio.h>
#define MAX 100
struct Polynomial 
{
	int coefficient;
	int exponent;
};
void readPolynomial(struct Polynomial poly[], int numTerms) 
{
	int i;
	printf("Enter the terms of the polynomial:\n");
	for ( i = 0; i < numTerms; i++) 
	{
	printf("Enter coefficient of x^%d: ", i);
	scanf("%d", &poly[i].coefficient);
	poly[i].exponent = i;
	}
}
void displayPolynomial(struct Polynomial poly[], int numTerms) 
{
	int i;
	printf("The polynomial is: ");
	for ( i = numTerms - 1; i >= 0; i--) 
	{
		if (poly[i].coefficient != 0) 
		{
			if (i != numTerms - 1 && 
			poly[i].coefficient > 0) 
			{
				printf("+");
			}
			if (poly[i].exponent == 0) 
			{
				printf("%d", poly[i].coefficient);
			}
	 		else if (poly[i].exponent == 1) 
	 		{
				printf("%dx", poly[i].coefficient);
			}
			else 
			{
				printf("%dx^%d", 
				poly[i].coefficient, poly[i].exponent);
			}
		}
	}
	printf("\n");
}
int main() 
{
	struct Polynomial poly[MAX];
	int numTerms;
	printf("Enter the number of terms in the polynomial: ");
	scanf("%d", &numTerms);
	readPolynomial(poly, numTerms);
	displayPolynomial(poly, numTerms);
	return 0;
}
