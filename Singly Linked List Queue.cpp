// ConsoleApplication70.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node//구조체 정의(typedef로 선언한 이유는 11번째 줄 주석에 첨가)
{
	int key;//큐에 저장할 값을 저장할 변수를 선언한다
	struct Node *next;//다음 노드를 가르킬 포인터 변수를 선언한다
}node;//struct Node를 node로 부르기 위해 typedef로 선언한다

node *top;//struct Node 포인터 변수 top 선언한다
node *end;//struct Node 포인터 변수 end 선언한다

int empty();//empty 함수 프로토타입
int is_full();//is_full 함수 프로토타입
void enqueue(int eqdata);//enqueue 함수 프로토타입
int dequeue();//dequeue 함수 프로토타입

void main()//메인 함수를 정의한다
{
	int eqdata;//enqueue할 값을 저장할 변수를 선언한다
	int choice = 0;//사용자의 선택의 값을 저장할 변수를 선언한다

	printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
	scanf("%d", &choice);//사용자가 선택한 값을 받아온다
	while (1)//while 문
	{
		switch (choice)//choice 값에 대한 스위치문
		{
		case 1://만약 choice가 1이면
			printf("Write a number : ");//Write a number : 를 출력한다
			scanf("%d", &eqdata);//eqdata 값을 받아온다
			enqueue(eqdata);//eqdata값에 대한 enqueue 함수를 실행한다
			choice = 0;//choice의 값을 0으로 초기화한다
			break;//스위치문을 빠져나온다
		case 2://만약 choice가 2이면
			if (top == NULL) // 큐에 아무것도 없으면
			{
				empty();//empty 함수를 실행한다
			}
			else//아니면
			{
				dequeue();//dequeue 함수를 실행한다
			}
			choice = 0;//choice의 값을 0으로 초기화한다
			break;//스위치문을 빠져나온다
		case 3://만약 choice가 3이면
			if (top != NULL) //만약 큐가 NULL이 아니면
			{
				node *printdata;//struct Node 포인터 변수 printdata 선언

				for (printdata = top; printdata != NULL; printdata = printdata->next)//큐에 저장된 값들을 top부터 NULL까지 출력할 for문
				{
					printf("%d\n", printdata->key);//%d(printdata의 구조체 key값)을 출력 후 한 줄 띔
				}
			}
			else//아니라면
				empty();//empty 함수를 실행한다
			choice = 0;//choice의 값을 0으로 초기화한다
			break;//스위치문을 빠져나온다
		case 4://choice가 4이면
			exit(1);//프로그램을 종료한다
		default://만약 choice의 값이 그 외이면
			printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
			scanf("%d", &choice);//사용자가 선택한 값을 받아온다
		}
	}

}

void enqueue(int eqdata)//queue를 enqueue할 enqueue 함수를 정의한다
{
	node *newdata;//struct Node 포인터 변수 newdata를 선언한다
	newdata = (node *)malloc(sizeof(node));//malloc으로 메모리를 할당하여 준다

	newdata->key = eqdata;//newdata의 구조체 key값에 eqdata값을 대입한다
	newdata->next = NULL; //newdata의 다음노드는 NULL(맨 뒤에 삽입이라서)

	if (top == NULL) //만약 큐가 비어있으면
		top = end = newdata;//top과 end에 newdata의 값을 대입한다

	else//아니면
	{
		end->next = newdata;//end의 다음노드에 newdata의 값을 대입한다
		end = end->next; //end의 위치를 이동한다
	}
	if (newdata == NULL)//만약 newdata의 값이 NULL이라면
	{
		is_full();//is_full 함수를 실행한다
	}

}

int dequeue()//queue를 dequeue 할 dequeue 함수를 정의한다
{
	node *nextdata;//struct Node 포인터 변수 nextdata를 선언한다

	int dqdata;//dequeue한 값을 저장할 변수를 선언한다



	if (top == end)//만약 큐에 노드가 1개이면
	{
		dqdata = top->key;  //dqdata에 top의 구조체 key값을 대입한다
		free(top);// 메모리를 반환한다
		top = end = NULL; //큐에 데이터가 없음

		printf("%d is dequeued\n", dqdata);//%d(dqdata의 값) is dequeued 출력 후 한 줄 띈다

	}
	else //아니면
	{
		nextdata = top;//nextdata에 top의 값 대입한다
		dqdata = top->key;//dqdata에 top의 구조체 key값을 대입한다
		top = top->next;//top의 위치를 이동한다
		free(nextdata);// 메모리를 반환한다
		nextdata = NULL;//nextdata는 NULL

		printf("%d is dequeued\n", dqdata);//%d(dqdata의 값) is dequeued 출력 후 한 줄 띈다
	}
	return 0;//값 0을 리턴한다
}

int empty()//큐가 비어있으면 알려줄 empty 함수를 정의한다
{
	if (top == NULL) // 큐에 아무것도 없으면
		printf("queue is empty\n");//queue is empty 출력 후 한 줄 띈다
	return 0;
}
int is_full()//큐가 꽉차있으면 알려줄 is_full 함수를 정의한다(연결 리스트는 메모리 할당 과정에서 오류가 있지않는 한 메모리 포화 상태는 없다고 봐야하지만 만일의 경우를 위해 구상을 갖추었다)
{
	printf("queue is full\n");//queue is full를 출력 후 한 줄 띈다
	return 0;//값 0을 리턴한다
}