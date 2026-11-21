#include <stdio.h>
#define AREA_OF_CIRCLE(radius) (3.14159 * (radius) * (radius))
int main() 
{
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    printf("The area of the circle with radius %.2f is: %.2f\n", radius, AREA_OF_CIRCLE(radius));
    return 0;
}
