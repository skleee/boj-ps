#include <stdio.h>
#include <string.h>
#define MAX_SIZE  100

typedef struct ArrayStack {
	int top;
	char stack[MAX_SIZE];
}ArrayStack;

void push(ArrayStack *stack, char data) {
	stack->top++;
	stack->stack[stack->top] = data;
}

char pop(ArrayStack *stack) {
	char temp = stack->stack[stack->top];
	stack->top--;
	return temp;
}
int IsEmpty(ArrayStack *stack) {
	if (stack->top != -1)
		return 0;
	return 1;
}

char peek(ArrayStack *stack) {
	return stack->stack[stack->top];
}

int Priority(char operand) {
	switch (operand) {
	case '(': case ')':
		return 0;
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	default:
		return -1;
	}
}

void postfix(char *exp) {
	int i = 0;
	ArrayStack stack;
	stack.top = -1;
	for (i = 0; i<strlen(exp); i++) {
		if (Priority(exp[i]) == -1) {
			printf("%c", exp[i]);
		}
		else if (exp[i] == '(') {
			push(&stack, exp[i]);
		}
		else if (exp[i] == ')') {
			while (peek(&stack) != '(') {
				printf("%c", pop(&stack));
			}
			pop(&stack);
		}
		else if (Priority(exp[i]) >= 1) {
			while (!IsEmpty(&stack) && Priority(exp[i]) <= Priority(peek(&stack))) {
				printf("%c", pop(&stack));
			}
			push(&stack, exp[i]);
		}
	}
	while (!IsEmpty(&stack)) {
		printf("%c", pop(&stack));
	}
}

int main() {
	int i = 0;
	char exp[100];
	scanf("%s", exp);
	postfix(exp);
}