#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;

void push(char x) 
{
    if (top == MAX_SIZE - 1) 
	{
        printf("Overflow stack!!!\n");
        return;
    }
    else
    {
    	top = top + 1;
    	stack[top] = x;
	}
}

char pop() 
{
    if (top == -1) 
	{
        printf("Stack is Empty!!\n");
        return ' ';
    }
    else
    {
    	char poppedElement = stack[top];
    	top = top - 1;
    	return poppedElement;
	}
}

int is_matching_pair(char c1, char c2) 
{
    if (c1 == '(' && c2 == ')') 
	{
        return 1;
    } 
	else if (c1 == '[' && c2 == ']') 
	{
        return 1;
    } 
	else if (c1 == '{' && c2 == '}') 
	{
        return 1;
    } 
	else
        return 0;
}

int is_Balanced(char c1[]) 
{
    int i;
    for (i = 0; i < strlen(c1); i++) 
	{
        if (c1[i] == '(' || c1[i] == '{' || c1[i] == '[') 
		{
            push(c1[i]);
        } 
		else if (c1[i] == ')' || c1[i] == '}' || c1[i] == ']') 
		{
            if (top == -1) 
			{
                printf("No matching opening bracket!!\n");
                return 0;
            } 
			else 
			{
                if (!is_matching_pair(pop(), c1[i])) 
				{
                    printf("No matching found\n");
                    return 0;
                }
            }
        }
    }
    if (top == -1) 
	{
        return 1;
    } 
	else 
	{
        return 0; 
    }
}

int main() 
{
    char text[100];
    printf("Enter an expression with parenthesis:\n");
    scanf("%[^\n]s", text);

    if (is_Balanced(text)) 
	{
        printf("Expression is balanced\n");
    } 
	else 
	{
        printf("Expression is not balanced\n");
    }
    return 0;
}
