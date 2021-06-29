// ConsoleApplication69.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {//구조체 정의(typedef로 선언한 이유는 10번째 줄 주석에 첨가)
	int key;//스택에 저장할 값을 저장할 변수를 선언한다
	struct Node* next;;//다음 노드를 가르켜줄 포인터 변수를 선언한다
}node;;//struct Node를 node로 부르기 위해 typedef로 선언한다

node* top;//struct Node 포인터 변수 top을 선언한다
node* end;//struct Node 포인터 변수 end을 선언한다


int is_empty();//is_empty 함수 프로토타입
int is_full();//is_full 함수 프로토타입
int push(int pushdata);//push 함수 프로토타입
int pop();//pop 함수 프로토타입


void main()//메인 함수	
{
	top = (node*)malloc(sizeof(node));//malloc 명령어를 사용하여 메모리를 할당하여 준다
	end = (node*)malloc(sizeof(node));//malloc 명령어를 사용하여 메모리를 할당하여 준다
	top->next = end;//top의 다음노드는 end
	end->next = end;//end의 다음노드는 end

	int pushnum;//push할 값을 저장해줄 변수 pushnum을 선언한다
	int choice=0;//사용자가 선택한 값을 저장해줄 변수 choice를 선언한다

	printf("1.push 2.pop 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
	scanf("%d", &choice);//사용자가 선택한 값을 받아온다
	while (1)//while문
	{
		switch (choice) {//choice 값에 대한 스위치문
		case 1://만약 choice의 값이 1이면
			printf("Write number want push : ");// Write number want push :를 출력한다
			scanf("%d", &pushnum);//pushnum의 값을 받아온다
			push(pushnum);//pushnum의 값에 대한 push 함수를 실행한다
			choice = 0;//choice의 값을 0으로 초기화한다
			break;//스위치문을 빠져나온다
		case 2://만약 choice의 값이 2이면
			if (top->next == end) {//만약 top의 다음 노드가 end와 같다면(=스택에 아무것도 없다면)
				is_empty(); //is_empty 함수를 실행한다
			}
			else//아니라면
				pop();//pop함수를 실행한다
			choice = 0;//choice의 값을 0으로 초기화한다
			break;//스위치문을 빠져나온다
		case 3://만약 choice의 값이 3이면
			node* printdata;//struct Node의 포인터 변수 printdata를 선언한다
			printdata = top->next;//printdata에 top의 다음노드의 값을 대입한다
			is_empty();//is_empty함수를 실행한다
			while (printdata != end)//printdata가 end가 아닐때까지 반복하는 while문
			{
				printf("%6d\n", printdata->key);//printdata에 key의 값을 대입하여 출력
				printdata = printdata->next;//printdata에 printdata의 다음 노드의 값을 대입
			}
			choice = 0;//choice의 값을 0으로 초기화한다
			break;//스위치문을 빠져나온다
		case 4://choice가 4이면
			exit(1);//프로그램을 종료한다
		default://만약 choice의 값이 그 외라면
			printf("1.push 2.pop 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
			scanf("%d", &choice);//사용자가 선택한 값을 받아온다
		}
	}
}




int is_empty()//스택이 비어있음을 알려줄 is_empty 함수

{
	if (top->next == end)//만약 top의 다음 노드가 end와 같다면(=스택에 아무것도 없다면)
		printf("Stack is empty\n");//Stack is empty를 출력한다
	return 0;//값 0을 리턴한다
}

int is_full()//스택이 꽉차있음을 알려줄 empty 함수

{
	printf("Stack is full\n");//Stack is full를 출력한다
	return 0;//값 0을 리턴한다
}

int push(int pushdata)//push를 할 push 함수

{
	node* newdata;//struct Node 포인터 변수 newdata 선언

	newdata = (node*)malloc(sizeof(node));//malloc 명령어를 사용하여 메모리를 할당하여 준다

	if (newdata == NULL)//만약 newdata의 값이 NULL이라면
	{
		is_full();//is_full 함수를 실행한다
	}

	newdata->key = pushdata;//newdata의 구조체 key값에 pushdata값 대입
	newdata->next = top->next;//newdata의 다음노드에 top의 다음노드의 값 대입
	top->next = newdata;// top의 다음노드에 newdata의 값 대입
	return 0;
}

int pop()//pop을 할 pop 함수

{
	node* nextdata;//struct Node 포인터 변수 nextdata를 선언한다
	int popdata;//pop한 값을 저장할 변수 popdata를 선언한다

	nextdata = top;//nextdata에 top의 값을 대입힌다
	popdata = nextdata->key;//popdata에 nextdata의 구조체 key값을 대입한다

	top = top->next;//top에 top의 다음 노드의 값을 대입한다
	free(nextdata);//메모리를 반환한다
	return popdata;//popdata값을 리턴한다
}

