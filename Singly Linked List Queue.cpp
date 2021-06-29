// ConsoleApplication70.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node//����ü ����(typedef�� ������ ������ 11��° �� �ּ��� ÷��)
{
	int key;//ť�� ������ ���� ������ ������ �����Ѵ�
	struct Node *next;//���� ��带 ����ų ������ ������ �����Ѵ�
}node;//struct Node�� node�� �θ��� ���� typedef�� �����Ѵ�

node *top;//struct Node ������ ���� top �����Ѵ�
node *end;//struct Node ������ ���� end �����Ѵ�

int empty();//empty �Լ� ������Ÿ��
int is_full();//is_full �Լ� ������Ÿ��
void enqueue(int eqdata);//enqueue �Լ� ������Ÿ��
int dequeue();//dequeue �Լ� ������Ÿ��

void main()//���� �Լ��� �����Ѵ�
{
	int eqdata;//enqueue�� ���� ������ ������ �����Ѵ�
	int choice = 0;//������� ������ ���� ������ ������ �����Ѵ�

	printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
	scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
	while (1)//while ��
	{
		switch (choice)//choice ���� ���� ����ġ��
		{
		case 1://���� choice�� 1�̸�
			printf("Write a number : ");//Write a number : �� ����Ѵ�
			scanf("%d", &eqdata);//eqdata ���� �޾ƿ´�
			enqueue(eqdata);//eqdata���� ���� enqueue �Լ��� �����Ѵ�
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 2://���� choice�� 2�̸�
			if (top == NULL) // ť�� �ƹ��͵� ������
			{
				empty();//empty �Լ��� �����Ѵ�
			}
			else//�ƴϸ�
			{
				dequeue();//dequeue �Լ��� �����Ѵ�
			}
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 3://���� choice�� 3�̸�
			if (top != NULL) //���� ť�� NULL�� �ƴϸ�
			{
				node *printdata;//struct Node ������ ���� printdata ����

				for (printdata = top; printdata != NULL; printdata = printdata->next)//ť�� ����� ������ top���� NULL���� ����� for��
				{
					printf("%d\n", printdata->key);//%d(printdata�� ����ü key��)�� ��� �� �� �� ��
				}
			}
			else//�ƴ϶��
				empty();//empty �Լ��� �����Ѵ�
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 4://choice�� 4�̸�
			exit(1);//���α׷��� �����Ѵ�
		default://���� choice�� ���� �� ���̸�
			printf("1.enqueue 2.dequeue 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
			scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
		}
	}

}

void enqueue(int eqdata)//queue�� enqueue�� enqueue �Լ��� �����Ѵ�
{
	node *newdata;//struct Node ������ ���� newdata�� �����Ѵ�
	newdata = (node *)malloc(sizeof(node));//malloc���� �޸𸮸� �Ҵ��Ͽ� �ش�

	newdata->key = eqdata;//newdata�� ����ü key���� eqdata���� �����Ѵ�
	newdata->next = NULL; //newdata�� �������� NULL(�� �ڿ� �����̶�)

	if (top == NULL) //���� ť�� ���������
		top = end = newdata;//top�� end�� newdata�� ���� �����Ѵ�

	else//�ƴϸ�
	{
		end->next = newdata;//end�� ������忡 newdata�� ���� �����Ѵ�
		end = end->next; //end�� ��ġ�� �̵��Ѵ�
	}
	if (newdata == NULL)//���� newdata�� ���� NULL�̶��
	{
		is_full();//is_full �Լ��� �����Ѵ�
	}

}

int dequeue()//queue�� dequeue �� dequeue �Լ��� �����Ѵ�
{
	node *nextdata;//struct Node ������ ���� nextdata�� �����Ѵ�

	int dqdata;//dequeue�� ���� ������ ������ �����Ѵ�



	if (top == end)//���� ť�� ��尡 1���̸�
	{
		dqdata = top->key;  //dqdata�� top�� ����ü key���� �����Ѵ�
		free(top);// �޸𸮸� ��ȯ�Ѵ�
		top = end = NULL; //ť�� �����Ͱ� ����

		printf("%d is dequeued\n", dqdata);//%d(dqdata�� ��) is dequeued ��� �� �� �� ���

	}
	else //�ƴϸ�
	{
		nextdata = top;//nextdata�� top�� �� �����Ѵ�
		dqdata = top->key;//dqdata�� top�� ����ü key���� �����Ѵ�
		top = top->next;//top�� ��ġ�� �̵��Ѵ�
		free(nextdata);// �޸𸮸� ��ȯ�Ѵ�
		nextdata = NULL;//nextdata�� NULL

		printf("%d is dequeued\n", dqdata);//%d(dqdata�� ��) is dequeued ��� �� �� �� ���
	}
	return 0;//�� 0�� �����Ѵ�
}

int empty()//ť�� ��������� �˷��� empty �Լ��� �����Ѵ�
{
	if (top == NULL) // ť�� �ƹ��͵� ������
		printf("queue is empty\n");//queue is empty ��� �� �� �� ���
	return 0;
}
int is_full()//ť�� ���������� �˷��� is_full �Լ��� �����Ѵ�(���� ����Ʈ�� �޸� �Ҵ� �������� ������ �����ʴ� �� �޸� ��ȭ ���´� ���ٰ� ���������� ������ ��츦 ���� ������ ���߾���)
{
	printf("queue is full\n");//queue is full�� ��� �� �� �� ���
	return 0;//�� 0�� �����Ѵ�
}