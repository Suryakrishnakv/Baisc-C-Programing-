#include <stdio.h>
#define MAX 100
void readPolynomial(int poly[], int degree) 
{
	int i;
	printf("Enter the coefficients of the polynomial (from constant term to highest degree):\n");
	for ( i = 0; i <= degree; i++) 
	{
		printf("Coefficient of x^%d: ", i);
		scanf("%d", &poly[i]);
	}
}
void displayPolynomial(int poly[], int degree) 
{
	printf("The polynomial is: ");
	int i;
	for ( i = degree; i >= 0; i--) 
	{
		if (poly[i] != 0) {
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
void addPolynomials(int poly1[], int poly2[], int result[], int 
degree1, int degree2) 
{
	int i;
	int maxDegree = (degree1 > degree2) ? 
	degree1 : degree2;
	for ( i = 0; i <= maxDegree; i++) 
	{
		result[i] = 0;
		if (i <= degree1) 
		{
			result[i] += poly1[i];
		}
		if (i <= degree2) 
		{
			result[i] += poly2[i];
		}
	}
}
int main() 
{
	int poly1[MAX], poly2[MAX], result[MAX];
	int degree1, degree2;
	printf("Enter the degree of the first polynomial: ");
	scanf("%d", &degree1);
	printf("Enter the degree of the second polynomial: ");
	scanf("%d", &degree2);
	printf("Enter the first polynomial:\n");
	readPolynomial(poly1, degree1);
	printf("Enter the second polynomial:\n");
	readPolynomial(poly2, degree2);
	addPolynomials(poly1, poly2, result, degree1, degree2);
	int resultDegree = (degree1 > degree2) ? 
	degree1 : degree2;
	while (resultDegree >= 0 && 
	result[resultDegree] == 0) 
	{
		resultDegree--;
	}
	printf("The sum of the polynomials is:\n");
	displayPolynomial(result, resultDegree);
	return 0;
}

