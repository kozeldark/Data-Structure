// ConsoleApplication67.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>

#define ARR 10
#define NULL 0

int front = 0;
int stack[ARR];

void push(int);
void pop();
int stack_full();
int stack_empty();



void push(int data)
{
	if (stack_full() == 0)
		stack[front++]=data;
}
void pop()
{
	if (stack_empty() == 0)
		stack[--front];
}
int stack_full()
{
	if (front >= ARR)
	{
		printf("FULL!! \n");
		return 1;
	}
	else
		return 0;
}
int stack_empty()
{
	if (front == NULL)
	{
		printf("EMPTY!! \n");
		return 1;
	}
	else
		return 0;
}

void main()
{
	int i;
	int num = 0;
	int value;

	while (num != 4)
	{
		printf("1. Push 2. Pop 3. Print 4. Exit\n");
		printf("Select : ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("Write Number want push : ");
			while (getchar() != '\n');
			scanf("%d", &value);
			push(value);
			break;
		case 2:
			printf("Write Number want pop : ");
			pop();
			break;
		case 3:
			int i;
			for (i = 0; i < front; i++)
				printf("%6d \n", stack[i], i + 1);
			break;
		default:
			break;
		}
	}
}