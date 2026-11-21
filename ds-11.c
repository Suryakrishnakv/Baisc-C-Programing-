#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
typedef struct 
{
    char items[MAX];
    int top;
} Stack;

void push(Stack *s, char c) 
{
    if (s->top == MAX - 1) 
	{
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) 
{
    if (s->top == -1)
        return '\0';
    return s->items[(s->top)--];
}

char peek(Stack *s) 
{
    if (s->top == -1)
        return '\0';
    return s->items[s->top];
}
int precedence(char op) 
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
void infixToPostfix(char *infix, char *postfix) 
{
    Stack s;
    s.top = -1;
    int j = 0;
	int i;
	for (i = 0; infix[i] != '\0'; i++) 
	{
    	if (infix[i] == ' ') continue; 
		{
        	char c = infix[i];
        	if (isalnum(c)) 
			{  
            	postfix[j++] = c;
        	} 
			else if (c == '(') 
			{  
            	push(&s, c);
        	} 
			else if (c == ')') 
			{  
            	while (peek(&s) != '(')
                postfix[j++] = pop(&s);
            	pop(&s);  
        	} 
			else 
			{  
            	while (precedence(peek(&s)) >= precedence(c) && peek(&s) != '(')
				postfix[j++] = pop(&s);
            	push(&s, c);
        	}
    	}
    }
    while (s.top != -1)
        postfix[j++] = pop(&s);
    postfix[j] = '\0';  
}
int main() 
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
