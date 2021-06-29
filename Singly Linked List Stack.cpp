// ConsoleApplication69.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {//����ü ����(typedef�� ������ ������ 10��° �� �ּ��� ÷��)
	int key;//���ÿ� ������ ���� ������ ������ �����Ѵ�
	struct Node* next;;//���� ��带 �������� ������ ������ �����Ѵ�
}node;;//struct Node�� node�� �θ��� ���� typedef�� �����Ѵ�

node* top;//struct Node ������ ���� top�� �����Ѵ�
node* end;//struct Node ������ ���� end�� �����Ѵ�


int is_empty();//is_empty �Լ� ������Ÿ��
int is_full();//is_full �Լ� ������Ÿ��
int push(int pushdata);//push �Լ� ������Ÿ��
int pop();//pop �Լ� ������Ÿ��


void main()//���� �Լ�	
{
	top = (node*)malloc(sizeof(node));//malloc ��ɾ ����Ͽ� �޸𸮸� �Ҵ��Ͽ� �ش�
	end = (node*)malloc(sizeof(node));//malloc ��ɾ ����Ͽ� �޸𸮸� �Ҵ��Ͽ� �ش�
	top->next = end;//top�� �������� end
	end->next = end;//end�� �������� end

	int pushnum;//push�� ���� �������� ���� pushnum�� �����Ѵ�
	int choice=0;//����ڰ� ������ ���� �������� ���� choice�� �����Ѵ�

	printf("1.push 2.pop 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
	scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
	while (1)//while��
	{
		switch (choice) {//choice ���� ���� ����ġ��
		case 1://���� choice�� ���� 1�̸�
			printf("Write number want push : ");// Write number want push :�� ����Ѵ�
			scanf("%d", &pushnum);//pushnum�� ���� �޾ƿ´�
			push(pushnum);//pushnum�� ���� ���� push �Լ��� �����Ѵ�
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 2://���� choice�� ���� 2�̸�
			if (top->next == end) {//���� top�� ���� ��尡 end�� ���ٸ�(=���ÿ� �ƹ��͵� ���ٸ�)
				is_empty(); //is_empty �Լ��� �����Ѵ�
			}
			else//�ƴ϶��
				pop();//pop�Լ��� �����Ѵ�
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 3://���� choice�� ���� 3�̸�
			node* printdata;//struct Node�� ������ ���� printdata�� �����Ѵ�
			printdata = top->next;//printdata�� top�� ��������� ���� �����Ѵ�
			is_empty();//is_empty�Լ��� �����Ѵ�
			while (printdata != end)//printdata�� end�� �ƴҶ����� �ݺ��ϴ� while��
			{
				printf("%6d\n", printdata->key);//printdata�� key�� ���� �����Ͽ� ���
				printdata = printdata->next;//printdata�� printdata�� ���� ����� ���� ����
			}
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 4://choice�� 4�̸�
			exit(1);//���α׷��� �����Ѵ�
		default://���� choice�� ���� �� �ܶ��
			printf("1.push 2.pop 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
			scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
		}
	}
}




int is_empty()//������ ��������� �˷��� is_empty �Լ�

{
	if (top->next == end)//���� top�� ���� ��尡 end�� ���ٸ�(=���ÿ� �ƹ��͵� ���ٸ�)
		printf("Stack is empty\n");//Stack is empty�� ����Ѵ�
	return 0;//�� 0�� �����Ѵ�
}

int is_full()//������ ���������� �˷��� empty �Լ�

{
	printf("Stack is full\n");//Stack is full�� ����Ѵ�
	return 0;//�� 0�� �����Ѵ�
}

int push(int pushdata)//push�� �� push �Լ�

{
	node* newdata;//struct Node ������ ���� newdata ����

	newdata = (node*)malloc(sizeof(node));//malloc ��ɾ ����Ͽ� �޸𸮸� �Ҵ��Ͽ� �ش�

	if (newdata == NULL)//���� newdata�� ���� NULL�̶��
	{
		is_full();//is_full �Լ��� �����Ѵ�
	}

	newdata->key = pushdata;//newdata�� ����ü key���� pushdata�� ����
	newdata->next = top->next;//newdata�� ������忡 top�� ��������� �� ����
	top->next = newdata;// top�� ������忡 newdata�� �� ����
	return 0;
}

int pop()//pop�� �� pop �Լ�

{
	node* nextdata;//struct Node ������ ���� nextdata�� �����Ѵ�
	int popdata;//pop�� ���� ������ ���� popdata�� �����Ѵ�

	nextdata = top;//nextdata�� top�� ���� ��������
	popdata = nextdata->key;//popdata�� nextdata�� ����ü key���� �����Ѵ�

	top = top->next;//top�� top�� ���� ����� ���� �����Ѵ�
	free(nextdata);//�޸𸮸� ��ȯ�Ѵ�
	return popdata;//popdata���� �����Ѵ�
}

