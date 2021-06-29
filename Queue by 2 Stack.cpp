// ConsoleApplication72.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10//스택 어레이의 사이즈로 쓸 SIZE 변수를 정의한다

int mainstack[SIZE];//mainstack을 선언한다
int substack[SIZE];//substack을 선언한다

int msfront = 0;//msfront(mainstack의 front 값)을 선언한다
int ssfront = 0;//ssfront(substack의 front 값)을 선언한다

void pushmain(int);//pushmain 함수의 프로토타입
void pushsub(int);//pushsub 함수의 프로토타입
int popmain();//popmain 함수의 프로토타입
int popsub();//popsub 함수의 프로토타입

void enqueue(int);//enqueue 함수의 프로토타입
int dequeue();//dequeue 함수의 프로토타입

int msfull();//msfull 함수의 프로토타입
int ssfull();//ssfull 함수의 프로토타입
int msempty();//msempty 함수의 프로토타입
int ssempty();//ssempty 함수의 프로토타입

int msfull()//mainstack이 꽉차있음을 알려줄 msfull 함수를 정의한다
{
	if (msfront >= SIZE - 1)// 만약 msfront의 값이 SIZE -1보다 크거나 같으면
		return 1;//1을 리턴한다
	else//아니라면
		return 0;//0을 리턴한다
}

int ssfull()//substack이 꽉차있음을 알려줄 msfull 함수를 정의한다
{
	if (ssfront >= SIZE - 1)// 만약 ssfront의 값이 SIZE -1보다 크거나 같으면
		return 1;//1을 리턴한다
	else//아니라면
		return 0;//0을 리턴한다
}

int msempty()//mainstack이 비어있음을 알려줄 msempty 함수를 정의한다
{
	if (msfront <= 0)// 만약 msfront의 값이 0보다 작거나 같으면
		return 1;//1을 리턴한다
	else//아니라면
		return 0;//0을 리턴한다
}

int ssempty()//substack이 비어있음을 알려줄 ssempty 함수를 정의한다
{
	if (ssfront <= 0)// 만약 ssfront의 값이 0보다 작거나 같으면
		return 1;//1을 리턴한다
	else//아니라면
		return 0;//0을 리턴한다
}

void pushmain(int n)//mainstack을 push해줄 pushmain 함수를 정의한다
{
	if (msfull())//msfull()함수의 값에 따른 if문(1이라면 실행 0이라면 실행되지 않는다)
	{
		printf("mainstack full\n");//mainstack full을 출력한다
	}
	mainstack[msfront] = n;//mainstack[msfront]에 n의 값을 대입.
	++msfront;//msfront의 값에 1을 더한다.
}

void pushsub(int n)//substack을 push해줄 pushmain 함수를 정의한다
{
	if (ssfull())//ssfull()함수의 값에 따른 if문(1이라면 실행 0이라면 실행되지 않는다)
	{
		printf("substack full\n");//substack full을 출력한다
	}
	substack[ssfront] = n;//substack[ssfront]에 n의 값을 대입.
	++ssfront;//ssfront의 값에 1을 더한다.
}

int popmain()//mainstack을 pop해줄 popmain 함수를 정의한다
{
	if (msempty())//msempty()함수의 값에 따른 if문(1이라면 실행 0이라면 실행되지 않는다)
	{
		printf("mainstack is empty\n");//mainstack is empty을 출력한다
	}
	return mainstack[--msfront];// mainstack[--msfront]값을 리턴한다
}

int popsub()//substack을 pop해줄 popmain 함수를 정의한다
{
	if (ssempty())//ssempty()함수의 값에 따른 if문(1이라면 실행 0이라면 실행되지 않는다)
	{
		printf("substack is empty\n");//substack is empty을 출력한다
	}
	return substack[--ssfront];// substack[--ssfront]값을 리턴한다
}

void enqueue(int n)//2개의 스택으로 구현한 큐에 대한 enqueue 함수를 정의한다
{
	pushmain(n);//n에 값에 대한 pushmain 함수를 실행한다
}

int dequeue()//2개의 스택으로 구현한 큐에 대한 dequeue 함수를 정의한다
{
	int n;//변수 n을 선언한다

	while (msfront > 0)//msfront의 값이 0보다 클때까지 반복한다
		pushsub(popmain());//popmain함수의 값에 대한 pushsub함수를 실행한다

	n = popsub();//n에 popsub()에 값을 대입한다

	while (ssfront > 0)//ssfront의 값이 0보다 클때까지 반복한다
		pushmain(popsub());//popsub함수의 값에 대한 pushmain함수를 실행한다

	return n;//n을 리턴한다
}

int main()//메인 함수를 정의한다
{
	
	int num=0;//enqueue할 값을 받아올 변수 num을 선언한다
	int choice = 0;//메뉴에 대한 선택의 값을 받아올 변수 choice를 선언한다
	while (1)//choice 값에 대한 while문
	{
		printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
		scanf("%d", &choice);//사용자가 선택한 값을 받아온다
		switch (choice)//choice값에 대한 switch문
		{
		case 1://choice가 1이면
			printf("Write enqueue number :");//Write enqueue number를 출력한다
			scanf("%d", &num);//사용자가 입력한 값을 스캔하여 변수 num에 저장한다
			enqueue(num);//num의 값에 대한 enqueue함수를 실행한다
			choice = 0;//choice의 값을 0으로 설정한다
			break;//switch문을 빠져나온다
		case 2://choice가 2이면
			if (msempty())//만약 msempty()함수의 값이 1이라면
			{
				printf("mainstack is empty\n");//mainstack is empty을 출력한다
				choice = 0;//choice의 값을 0으로 설정한다
				break;//switch문을 빠져나온다
			}
			else//아니라면
			{
				printf("%d is pop\n", dequeue());//[dequeue함수의 값] is pop을 출력한다(dequeue함수도 실행된다)
				choice = 0;//choice의 값을 0으로 설정한다
				break;//switch문을 빠져나온다
			}
		case 3://choice가 3이면
			if (msempty())//만약 msempty()함수의 값이 1이라면
			{
				printf("mainstack is empty\n");//mainstack is empty을 출력한다
				choice = 0;//choice의 값을 0으로 설정한다
				break;//switch문을 빠져나온다
			}
			else//아니라면
			{
				for (int i = 0; i < msfront; i++)//i값에 대한 for문
					printf("%d\n", mainstack[i]);//mainstack[i]를 출력한다
				choice = 0;//choice의 값을 0으로 설정한다
				break;//switch문을 빠져나온다
			}
		case 4://choice가 4이면
			exit(1);//프로그램을 종료한다
		default://choice가 그 외의 값이라면
			printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//사용자가 볼 메뉴를 출력한다
			scanf("%d", &choice);//사용자가 선택한 값을 받아온다
		}
	}
	return 0;//0을 리턴한다
}
