// ConsoleApplication72.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10//���� ����� ������� �� SIZE ������ �����Ѵ�

int mainstack[SIZE];//mainstack�� �����Ѵ�
int substack[SIZE];//substack�� �����Ѵ�

int msfront = 0;//msfront(mainstack�� front ��)�� �����Ѵ�
int ssfront = 0;//ssfront(substack�� front ��)�� �����Ѵ�

void pushmain(int);//pushmain �Լ��� ������Ÿ��
void pushsub(int);//pushsub �Լ��� ������Ÿ��
int popmain();//popmain �Լ��� ������Ÿ��
int popsub();//popsub �Լ��� ������Ÿ��

void enqueue(int);//enqueue �Լ��� ������Ÿ��
int dequeue();//dequeue �Լ��� ������Ÿ��

int msfull();//msfull �Լ��� ������Ÿ��
int ssfull();//ssfull �Լ��� ������Ÿ��
int msempty();//msempty �Լ��� ������Ÿ��
int ssempty();//ssempty �Լ��� ������Ÿ��

int msfull()//mainstack�� ���������� �˷��� msfull �Լ��� �����Ѵ�
{
	if (msfront >= SIZE - 1)// ���� msfront�� ���� SIZE -1���� ũ�ų� ������
		return 1;//1�� �����Ѵ�
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}

int ssfull()//substack�� ���������� �˷��� msfull �Լ��� �����Ѵ�
{
	if (ssfront >= SIZE - 1)// ���� ssfront�� ���� SIZE -1���� ũ�ų� ������
		return 1;//1�� �����Ѵ�
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}

int msempty()//mainstack�� ��������� �˷��� msempty �Լ��� �����Ѵ�
{
	if (msfront <= 0)// ���� msfront�� ���� 0���� �۰ų� ������
		return 1;//1�� �����Ѵ�
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}

int ssempty()//substack�� ��������� �˷��� ssempty �Լ��� �����Ѵ�
{
	if (ssfront <= 0)// ���� ssfront�� ���� 0���� �۰ų� ������
		return 1;//1�� �����Ѵ�
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}

void pushmain(int n)//mainstack�� push���� pushmain �Լ��� �����Ѵ�
{
	if (msfull())//msfull()�Լ��� ���� ���� if��(1�̶�� ���� 0�̶�� ������� �ʴ´�)
	{
		printf("mainstack full\n");//mainstack full�� ����Ѵ�
	}
	mainstack[msfront] = n;//mainstack[msfront]�� n�� ���� ����.
	++msfront;//msfront�� ���� 1�� ���Ѵ�.
}

void pushsub(int n)//substack�� push���� pushmain �Լ��� �����Ѵ�
{
	if (ssfull())//ssfull()�Լ��� ���� ���� if��(1�̶�� ���� 0�̶�� ������� �ʴ´�)
	{
		printf("substack full\n");//substack full�� ����Ѵ�
	}
	substack[ssfront] = n;//substack[ssfront]�� n�� ���� ����.
	++ssfront;//ssfront�� ���� 1�� ���Ѵ�.
}

int popmain()//mainstack�� pop���� popmain �Լ��� �����Ѵ�
{
	if (msempty())//msempty()�Լ��� ���� ���� if��(1�̶�� ���� 0�̶�� ������� �ʴ´�)
	{
		printf("mainstack is empty\n");//mainstack is empty�� ����Ѵ�
	}
	return mainstack[--msfront];// mainstack[--msfront]���� �����Ѵ�
}

int popsub()//substack�� pop���� popmain �Լ��� �����Ѵ�
{
	if (ssempty())//ssempty()�Լ��� ���� ���� if��(1�̶�� ���� 0�̶�� ������� �ʴ´�)
	{
		printf("substack is empty\n");//substack is empty�� ����Ѵ�
	}
	return substack[--ssfront];// substack[--ssfront]���� �����Ѵ�
}

void enqueue(int n)//2���� �������� ������ ť�� ���� enqueue �Լ��� �����Ѵ�
{
	pushmain(n);//n�� ���� ���� pushmain �Լ��� �����Ѵ�
}

int dequeue()//2���� �������� ������ ť�� ���� dequeue �Լ��� �����Ѵ�
{
	int n;//���� n�� �����Ѵ�

	while (msfront > 0)//msfront�� ���� 0���� Ŭ������ �ݺ��Ѵ�
		pushsub(popmain());//popmain�Լ��� ���� ���� pushsub�Լ��� �����Ѵ�

	n = popsub();//n�� popsub()�� ���� �����Ѵ�

	while (ssfront > 0)//ssfront�� ���� 0���� Ŭ������ �ݺ��Ѵ�
		pushmain(popsub());//popsub�Լ��� ���� ���� pushmain�Լ��� �����Ѵ�

	return n;//n�� �����Ѵ�
}

int main()//���� �Լ��� �����Ѵ�
{
	
	int num=0;//enqueue�� ���� �޾ƿ� ���� num�� �����Ѵ�
	int choice = 0;//�޴��� ���� ������ ���� �޾ƿ� ���� choice�� �����Ѵ�
	while (1)//choice ���� ���� while��
	{
		printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
		scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
		switch (choice)//choice���� ���� switch��
		{
		case 1://choice�� 1�̸�
			printf("Write enqueue number :");//Write enqueue number�� ����Ѵ�
			scanf("%d", &num);//����ڰ� �Է��� ���� ��ĵ�Ͽ� ���� num�� �����Ѵ�
			enqueue(num);//num�� ���� ���� enqueue�Լ��� �����Ѵ�
			choice = 0;//choice�� ���� 0���� �����Ѵ�
			break;//switch���� �������´�
		case 2://choice�� 2�̸�
			if (msempty())//���� msempty()�Լ��� ���� 1�̶��
			{
				printf("mainstack is empty\n");//mainstack is empty�� ����Ѵ�
				choice = 0;//choice�� ���� 0���� �����Ѵ�
				break;//switch���� �������´�
			}
			else//�ƴ϶��
			{
				printf("%d is pop\n", dequeue());//[dequeue�Լ��� ��] is pop�� ����Ѵ�(dequeue�Լ��� ����ȴ�)
				choice = 0;//choice�� ���� 0���� �����Ѵ�
				break;//switch���� �������´�
			}
		case 3://choice�� 3�̸�
			if (msempty())//���� msempty()�Լ��� ���� 1�̶��
			{
				printf("mainstack is empty\n");//mainstack is empty�� ����Ѵ�
				choice = 0;//choice�� ���� 0���� �����Ѵ�
				break;//switch���� �������´�
			}
			else//�ƴ϶��
			{
				for (int i = 0; i < msfront; i++)//i���� ���� for��
					printf("%d\n", mainstack[i]);//mainstack[i]�� ����Ѵ�
				choice = 0;//choice�� ���� 0���� �����Ѵ�
				break;//switch���� �������´�
			}
		case 4://choice�� 4�̸�
			exit(1);//���α׷��� �����Ѵ�
		default://choice�� �� ���� ���̶��
			printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
			scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
		}
	}
	return 0;//0�� �����Ѵ�
}
