#include <stdio.h> 
#define MAX 100   
struct Stack 
{ 
    int arr[MAX];   
    int top;     
}; 
void initializeStack(struct Stack *stack) 
{ 
    stack->top = -1;   
} 
int isEmpty(struct Stack *stack) 
{ 
    return stack->top == -1; 
} 
void push(struct Stack *stack, int value) 
{ 
    if (stack->top == MAX - 1) 
	{ 
        printf("Stack Overflow! Cannot push %d\n", value); 
    } else { 
        stack->arr[++stack->top] = value; 
    } 
} 
int pop(struct Stack *stack) 
{ 
    if (isEmpty(stack)) 
	{ 
        printf("Stack Underflow! Cannot pop\n"); 
        return -1;    
    } else 
	{ 
        return stack->arr[stack->top--]; 
    } 
} 
int performOperation(char operator, int operand1, int operand2) 
{ 
    switch (operator) 
	{ 
        case '+': return operand1 + operand2; 
        case '-': return operand1 - operand2; 
        case '*': return operand1 * operand2; 
        case '/': return operand1 / operand2; 
        default: return 0; 
    } 
} 
int evaluatePostfix(char *postfix) 
{ 
 int i; 
    struct Stack stack; 
    initializeStack(&stack); 
    for ( i = 0; postfix[i] != '\0'; i++) 
	{ 
        char current = postfix[i]; 
        if (current >= '0' && current <= '9') 
		{ 
            push(&stack, current - '0');   
        } 
        else if (current == '+' || current == '-' || current == '*' || current == '/') 
		{ 
            int operand2 = pop(&stack); 
            int operand1 = pop(&stack); 
            int result = performOperation(current, operand1, operand2); 
            push(&stack, result); 
        } 
    } 
    return pop(&stack); 
} 
int main() { 
    char postfix[MAX]; 
    printf("Enter a postfix expression: "); 
    fgets(postfix, sizeof(postfix), stdin); 
    int result = evaluatePostfix(postfix); 
    printf("Result of postfix expression: %d\n", result); 
 
    return 0; 
} 

