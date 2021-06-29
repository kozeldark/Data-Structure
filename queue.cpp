// ConsoleApplication65.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>

int isEmpty();
int isFull();
int enQueue();
int deQueue();

int ARR[10];
int front = -1;
int rear = -1;


int isEmpty() {
	if (front == rear) {
		printf("EMPTY!!\n");
		return 1;
	}
	else
		return 0;
}

int isFull() {
	if (rear == 9)
	{
		printf("FULL!!\n");
		return 1;
	}
	else
		return 0;
}


int enQueue() {
	int num;
	if (isFull() == 0) {
		printf("Write Number want EnQueue : ");
		scanf("%d", &num);
		rear++;
		ARR[rear] = num;
		return 1;
	}
	else
		return 0;
}

int deQueue() {
	if (isEmpty() == 0) {
		front++;
		printf("deQueue : %d\n", ARR[front]);
		ARR[front] = NULL;
		return 1;
	}
	else
		isEmpty();
	return 0;
}


void main() {

	int ch = 0;

	while (ch != 4) {
		printf("1. EnQueue 2. DeQueue 3. Print 4. Exit\nChoice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			enQueue();
			break;
		case 2:
			deQueue();
			break;
		case 3:
			if (front == rear)
				isEmpty();
			else {
				for (int i = front + 1; i < rear; i++) {
					printf("%d\n", ARR[i]);
				}
				printf("%d\n", ARR[rear]);
			}
			break;
		case 4:
			break;
		default:
			break;
		}
	}
}