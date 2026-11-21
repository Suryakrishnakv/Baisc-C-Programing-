#include <stdio.h>
int globalCounter = 0;
void incrementGlobalCounter() 
{
    globalCounter++;
}
void incrementLocalCounter() 
{
    int localCounter = 0;
    localCounter++;
    printf("Local counter inside function: %d\n", localCounter);
}

int main() 
{
    int mainLocalCounter = 0;
    incrementGlobalCounter();
    printf("Global counter after increment: %d\n", globalCounter);
    mainLocalCounter++;
    printf("Local counter inside main: %d\n", mainLocalCounter);
    incrementLocalCounter();
    return 0;
}
