// ConsoleApplication71.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdlib.h>

#define ARR 11//큐 어레이의 사이즈로 쓸 SIZE 변수를 정의한다

int mainqueue[ARR];//mainqueue를 선언한다
int subqueue[ARR];//subqueue를 선언한다


void push(int);//push 함수의 프로토타입
int pop();//pop 함수의 프로토타입

int mqueue_full();//mqueue_full함수의 프로토타입
int mqueue_empty();//mqueue_empty함수의 프로토타입
int squeue_full();//squeue_full함수의 프로토타입
int squeue_empty();//squeue_empty함수의 프로토타입

int maindequeue();//maindequeue함수의 프로토타입
int mainenqueue(int);//mainenqueue함수의 프로토타입

int subdequeue();//subdequeue함수의 프로토타입
int subenqueue(int);//subenqueue함수의 프로토타입

int mfront;//mainqueue의 front값이 되어줄 mfront 변수를 선언한다
int mrear;//mainqueue의 rear값이 되어줄 mrear 변수를 선언한다

int sfront;//subqueue의 front값이 되어줄 sfront 변수를 선언한다
int srear;//subqueue의 rear값이 되어줄 srear 변수를 선언한다

void push(int data)//2개의 queue로 구현한 stack을 push해줄 push 함수를 정의한다
{
	mainenqueue(data);//data값에 따른 mainenqueue함수를 실행한다
}
int pop()//2개의 queue로 구현한 stack을 pop해줄 pop 함수를 정의한다
{
	int n;//리턴 받을 값을 저장할 변수 n을 선언한다
	while (!mqueue_empty()) {//mqueue_empty()가 1일때까지 반복하는 while문
		subenqueue(maindequeue());//maindequeue()값에 대한 subenqueue()함수를 실행한다(maindequeue()도 실행된다)
	}
	
	n = subdequeue();//n에 subdequeue() 값을 대입한다

	while (!squeue_empty()) {//squeue_empty()가 1일때까지 반복하는 while문
		mainenqueue(subdequeue());//subdequeue()값에 대한 mainenqueue()함수를 실행한다(subdequeue()도 실행된다)
	}
	
	return n;//n을 리턴한다
}
int mqueue_full()//mainqueue가 꽉차있음을 알려줄 mqueue_full 함수를 정의한다
{
	if ((mrear + 1)%ARR==mfront)//만약 (mrear + 1)%ARR가 mfront의 값과 같다면
	{
		printf("mainstack is full \n");//mainstack is full을 출력한다
		return 1;//1을 리턴한다
	}
	else//아니라면
		return 0;//0을 리턴한다
}
int mqueue_empty()//mainqueue가 비어있음을 알려줄 mqueue_empty 함수를 정의한다
{
	if (mfront == mrear)//만약 mfront가 mrear의 값과 같다면
	{
		return 1;//1을 리턴한다
	}
	else//아니라면
		return 0;//0을 리턴한다
}
int squeue_full()//subqueue가 꽉차있음을 알려줄 mqueue_full 함수를 정의한다
{
	if ((srear + 1) % ARR == sfront)//만약 (srear + 1)%ARR가 sfront의 값과 같다면
	{
		printf("substack is full \n");//substack is full을 출력한다
		return 1;//1을 리턴한다
	}
	else//아니라면
		return 0;//0을 리턴한다
}
int squeue_empty()//subqueue가 비어있음을 알려줄 squeue_empty 함수를 정의한다
{
	if (sfront == srear)//만약 sfront가 srear의 값과 같다면
	{
		return 1;//1을 리턴한다
	}
	else//아니라면
		return 0;//0을 리턴한다
}
int maindequeue()//mainqueue를 dequeue해줄 maindequeue 함수를 정의한다
{
	int old = mfront;//mfront 값을 저장해줄 old 변수를 선언한다
	mfront++;//mfront 값에 1을 더한다
	return mainqueue[old % ARR];//mainqueue[old % ARR]를 리턴한다
}
int mainenqueue(int data)//mainqueue를 enqueue해줄 mainenqueue 함수를 정의한다
{
	if (mqueue_full() == 0)//만약 mqueue_full함수의 값이 0이라면
	{
		mainqueue[mrear++ % ARR] = data;//mainqueue[mrear++ % ARR]에 data의 값을 대입한다
	}
	return 0;//0을 리턴한다
}
int subdequeue()//subqueue를 dequeue해줄 subdequeue 함수를 정의한다
{
	int old = sfront;//sfront 값을 저장해줄 old 변수를 선언한다
	sfront++;//sfront 값에 1을 더한다
	return subqueue[old % ARR];//subqueue[old % ARR]를 리턴한다
}
int subenqueue(int data)//subqueue를 enqueue해줄 subenqueue 함수를 정의한다
{
	if (squeue_full() == 0) //만약 squeue_full함수의 값이 0이라면
	{
		subqueue[srear++ % ARR] = data;//subqueue[srear++ % ARR]에 data의 값을 대입한다
	}
	return 0;//0을 리턴한다
}

void main()//메인 함수를 정의한다
{
	int choice = 0;//메뉴에 대한 선택의 값을 받아올 변수 choice를 선언한다
	int pushnum = 0;//push할 값을 받아올 변수 num을 선언한다

	printf("1.push 2.pop 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
	scanf("%d", &choice);//사용자가 선택한 값을 받아온다
	while (1)//while문
	{
		switch (choice)//choice 값에 대한 스위치문
		{
		case 1://만약 choice의 값이 1이면
			printf("Write Number want push : ");// Write number want push :를 출력한다
			scanf("%d", &pushnum);//pushnum의 값을 받아온다
			push(pushnum);//pushnum의 값에 대한 push 함수를 실행한다
			choice = 0;//choice의 값을 0으로 초기화한다
			break;//스위치문을 빠져나온다
		case 2://만약 choice의 값이 2이면
			if (mqueue_empty())//만약 mqueue_empty함수의 값이 1이라면
			{
				printf("mainstack is empty\n");//mainstack is empty를 출력한다
				choice = 0;//choice의 값을 0으로 초기화한다
				break;//스위치문을 빠져나온다
			}
			else
			{
				printf("%d is pop\n", pop());//[pop()의 값] is pop을 출력한다(pop()도 실행된다)
				choice = 0;//choice의 값을 0으로 초기화한다
				break;//스위치문을 빠져나온다
			}
		case 3://만약 choice의 값이 3이면
			if (mqueue_empty())//만약 mqueue_empty가 1이라면
			{
				printf("mainstack is empty\n");//mainstack is empty를 출력한다
				choice = 0;//choice의 값을 0으로 초기화한다
				break;//스위치문을 빠져나온다
			}
			else//아니라면
			{
				if ((mfront % ARR) < (mrear % ARR))//만약 (mfront % ARR)의 값이 (mrear % ARR)보다 작으면
				{
					for (int i = (mfront % ARR); i < (mrear % ARR); i++)//(mfront % ARR)부터 (mrear % ARR)까지에 관한 for문 실행
						printf("%d : mq[%d]\n", mainqueue[i], i);//mainqueue[i], i를 출력한다
					choice = 0;//choice의 값을 0으로 초기화한다
					break;//스위치문을 빠져나온다
				}
				else//아니라면
				{
					for (int i = (mfront % ARR); i < ARR; i++)//(mfront % ARR)부터 ARR까지에 관한 for문 실행
						printf("%d : mq[%d]\n", mainqueue[i], i);//mainqueue[i], i를 출력한다
					for (int i = 0; i < (mrear % ARR); i++)//0부터 (mrear % ARR)까지에 관한 for문 실행
						printf("%d : mq[%d]\n", mainqueue[i], i);//mainqueue[i], i를 출력한다
					choice = 0;//choice의 값을 0으로 초기화한다
					break;//스위치문을 빠져나온다
				}
			}
		case 4://만약 choice의 값이 4이면
			exit(1);//프로그램을 종료한다
		default:
			printf("1.push 2.pop 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
			scanf("%d", &choice);//사용자가 선택한 값을 받아온다
		}
	}
}
