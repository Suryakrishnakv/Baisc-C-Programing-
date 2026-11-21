#include <stdio.h>
#define MAX 100
struct Polynomial 
{
	int coefficient;
	int exponent;
};
void readPolynomial(struct Polynomial poly[ ], int numTerms) 
{
	int i;
	printf("Enter the terms of the polynomial (coefficient and exponent):\n");
	for ( i = 0; i < numTerms; i++) 
	{
	printf("Enter coefficient and exponent for term %d: ", i + 1);
	scanf("%d %d", &poly[i].coefficient, &poly[i].exponent);
	}
}
void displayPolynomial(struct Polynomial poly[ ], int numTerms) 
{
	int i;
	printf("The polynomial is: ");
	for ( i = 0; i < numTerms; i++) 
	{
		if (poly[i].coefficient != 0) 
		{
			if (i != 0 && poly[i].coefficient > 0) 
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
				printf("%dx^%d", poly[i].coefficient, 
				poly[i].exponent);
			}
		}	
	}
	printf("\n");
}
void subtractPolynomials(struct Polynomial poly1[ ], int numTerms1, struct Polynomial poly2[ ], int numTerms2, struct Polynomial result[], int *numTermsResult) 
{
	int i = 0, j = 0, k = 0;
	while (i < numTerms1 && j < numTerms2) 
	{
		if (poly1[i].exponent > poly2[j].exponent) 
		{
			result[k++] = poly1[i++];
		}
 		else if (poly1[i].exponent < poly2[j].exponent) 
 		{
			result[k++] = poly2[j++];
			result[k-1].coefficient = -result[k-1].coefficient;
		}
 		else 
 		{	
			result[k].exponent = poly1[i].exponent;
			result[k].coefficient = poly1[i].coefficient -
			poly2[j].coefficient;
			i++;
			j++;
			k++;
		}
	}
	while (i < numTerms1) 
	{
		result[k++] = poly1[i++];
	}
	while (j < numTerms2) 
	{
		result[k++] = poly2[j++];
		result[k-1].coefficient = -result[k-1].coefficient;
	}
	*numTermsResult = k;
}
int main() 
{
	struct Polynomial poly1[MAX], poly2[MAX], result[MAX];
	int numTerms1, numTerms2, numTermsResult;
	printf("Enter the number of terms in the first polynomial: ");
	scanf("%d", &numTerms1);
	printf("Enter the number of terms in the second polynomial: ");
	scanf("%d", &numTerms2);
	printf("Enter the first polynomial:\n");
	readPolynomial(poly1, numTerms1);
	printf("Enter the second polynomial:\n");
	readPolynomial(poly2, numTerms2);
	subtractPolynomials(poly1, numTerms1, poly2, numTerms2, result, &numTermsResult);
	printf("The difference of the polynomials is:\n");
	displayPolynomial(result, numTermsResult);
	return 0;
}
