// ConsoleApplication71.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h>
#include <stdlib.h>

#define ARR 11//ť ����� ������� �� SIZE ������ �����Ѵ�

int mainqueue[ARR];//mainqueue�� �����Ѵ�
int subqueue[ARR];//subqueue�� �����Ѵ�


void push(int);//push �Լ��� ������Ÿ��
int pop();//pop �Լ��� ������Ÿ��

int mqueue_full();//mqueue_full�Լ��� ������Ÿ��
int mqueue_empty();//mqueue_empty�Լ��� ������Ÿ��
int squeue_full();//squeue_full�Լ��� ������Ÿ��
int squeue_empty();//squeue_empty�Լ��� ������Ÿ��

int maindequeue();//maindequeue�Լ��� ������Ÿ��
int mainenqueue(int);//mainenqueue�Լ��� ������Ÿ��

int subdequeue();//subdequeue�Լ��� ������Ÿ��
int subenqueue(int);//subenqueue�Լ��� ������Ÿ��

int mfront;//mainqueue�� front���� �Ǿ��� mfront ������ �����Ѵ�
int mrear;//mainqueue�� rear���� �Ǿ��� mrear ������ �����Ѵ�

int sfront;//subqueue�� front���� �Ǿ��� sfront ������ �����Ѵ�
int srear;//subqueue�� rear���� �Ǿ��� srear ������ �����Ѵ�

void push(int data)//2���� queue�� ������ stack�� push���� push �Լ��� �����Ѵ�
{
	mainenqueue(data);//data���� ���� mainenqueue�Լ��� �����Ѵ�
}
int pop()//2���� queue�� ������ stack�� pop���� pop �Լ��� �����Ѵ�
{
	int n;//���� ���� ���� ������ ���� n�� �����Ѵ�
	while (!mqueue_empty()) {//mqueue_empty()�� 1�϶����� �ݺ��ϴ� while��
		subenqueue(maindequeue());//maindequeue()���� ���� subenqueue()�Լ��� �����Ѵ�(maindequeue()�� ����ȴ�)
	}
	
	n = subdequeue();//n�� subdequeue() ���� �����Ѵ�

	while (!squeue_empty()) {//squeue_empty()�� 1�϶����� �ݺ��ϴ� while��
		mainenqueue(subdequeue());//subdequeue()���� ���� mainenqueue()�Լ��� �����Ѵ�(subdequeue()�� ����ȴ�)
	}
	
	return n;//n�� �����Ѵ�
}
int mqueue_full()//mainqueue�� ���������� �˷��� mqueue_full �Լ��� �����Ѵ�
{
	if ((mrear + 1)%ARR==mfront)//���� (mrear + 1)%ARR�� mfront�� ���� ���ٸ�
	{
		printf("mainstack is full \n");//mainstack is full�� ����Ѵ�
		return 1;//1�� �����Ѵ�
	}
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}
int mqueue_empty()//mainqueue�� ��������� �˷��� mqueue_empty �Լ��� �����Ѵ�
{
	if (mfront == mrear)//���� mfront�� mrear�� ���� ���ٸ�
	{
		return 1;//1�� �����Ѵ�
	}
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}
int squeue_full()//subqueue�� ���������� �˷��� mqueue_full �Լ��� �����Ѵ�
{
	if ((srear + 1) % ARR == sfront)//���� (srear + 1)%ARR�� sfront�� ���� ���ٸ�
	{
		printf("substack is full \n");//substack is full�� ����Ѵ�
		return 1;//1�� �����Ѵ�
	}
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}
int squeue_empty()//subqueue�� ��������� �˷��� squeue_empty �Լ��� �����Ѵ�
{
	if (sfront == srear)//���� sfront�� srear�� ���� ���ٸ�
	{
		return 1;//1�� �����Ѵ�
	}
	else//�ƴ϶��
		return 0;//0�� �����Ѵ�
}
int maindequeue()//mainqueue�� dequeue���� maindequeue �Լ��� �����Ѵ�
{
	int old = mfront;//mfront ���� �������� old ������ �����Ѵ�
	mfront++;//mfront ���� 1�� ���Ѵ�
	return mainqueue[old % ARR];//mainqueue[old % ARR]�� �����Ѵ�
}
int mainenqueue(int data)//mainqueue�� enqueue���� mainenqueue �Լ��� �����Ѵ�
{
	if (mqueue_full() == 0)//���� mqueue_full�Լ��� ���� 0�̶��
	{
		mainqueue[mrear++ % ARR] = data;//mainqueue[mrear++ % ARR]�� data�� ���� �����Ѵ�
	}
	return 0;//0�� �����Ѵ�
}
int subdequeue()//subqueue�� dequeue���� subdequeue �Լ��� �����Ѵ�
{
	int old = sfront;//sfront ���� �������� old ������ �����Ѵ�
	sfront++;//sfront ���� 1�� ���Ѵ�
	return subqueue[old % ARR];//subqueue[old % ARR]�� �����Ѵ�
}
int subenqueue(int data)//subqueue�� enqueue���� subenqueue �Լ��� �����Ѵ�
{
	if (squeue_full() == 0) //���� squeue_full�Լ��� ���� 0�̶��
	{
		subqueue[srear++ % ARR] = data;//subqueue[srear++ % ARR]�� data�� ���� �����Ѵ�
	}
	return 0;//0�� �����Ѵ�
}

void main()//���� �Լ��� �����Ѵ�
{
	int choice = 0;//�޴��� ���� ������ ���� �޾ƿ� ���� choice�� �����Ѵ�
	int pushnum = 0;//push�� ���� �޾ƿ� ���� num�� �����Ѵ�

	printf("1.push 2.pop 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
	scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
	while (1)//while��
	{
		switch (choice)//choice ���� ���� ����ġ��
		{
		case 1://���� choice�� ���� 1�̸�
			printf("Write Number want push : ");// Write number want push :�� ����Ѵ�
			scanf("%d", &pushnum);//pushnum�� ���� �޾ƿ´�
			push(pushnum);//pushnum�� ���� ���� push �Լ��� �����Ѵ�
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 2://���� choice�� ���� 2�̸�
			if (mqueue_empty())//���� mqueue_empty�Լ��� ���� 1�̶��
			{
				printf("mainstack is empty\n");//mainstack is empty�� ����Ѵ�
				choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
				break;//����ġ���� �������´�
			}
			else
			{
				printf("%d is pop\n", pop());//[pop()�� ��] is pop�� ����Ѵ�(pop()�� ����ȴ�)
				choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
				break;//����ġ���� �������´�
			}
		case 3://���� choice�� ���� 3�̸�
			if (mqueue_empty())//���� mqueue_empty�� 1�̶��
			{
				printf("mainstack is empty\n");//mainstack is empty�� ����Ѵ�
				choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
				break;//����ġ���� �������´�
			}
			else//�ƴ϶��
			{
				if ((mfront % ARR) < (mrear % ARR))//���� (mfront % ARR)�� ���� (mrear % ARR)���� ������
				{
					for (int i = (mfront % ARR); i < (mrear % ARR); i++)//(mfront % ARR)���� (mrear % ARR)������ ���� for�� ����
						printf("%d : mq[%d]\n", mainqueue[i], i);//mainqueue[i], i�� ����Ѵ�
					choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
					break;//����ġ���� �������´�
				}
				else//�ƴ϶��
				{
					for (int i = (mfront % ARR); i < ARR; i++)//(mfront % ARR)���� ARR������ ���� for�� ����
						printf("%d : mq[%d]\n", mainqueue[i], i);//mainqueue[i], i�� ����Ѵ�
					for (int i = 0; i < (mrear % ARR); i++)//0���� (mrear % ARR)������ ���� for�� ����
						printf("%d : mq[%d]\n", mainqueue[i], i);//mainqueue[i], i�� ����Ѵ�
					choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
					break;//����ġ���� �������´�
				}
			}
		case 4://���� choice�� ���� 4�̸�
			exit(1);//���α׷��� �����Ѵ�
		default:
			printf("1.push 2.pop 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
			scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
		}
	}
}
