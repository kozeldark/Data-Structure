// ConsoleApplication75.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {//����ü ����(typedef�� ������ ������ 7��° �� �ּ��� ÷��)
	int key;//���ÿ� ������ ���� ������ ������ �����Ѵ�
	struct Node* next;;//���� ��带 �������� ������ ������ �����Ѵ�
}node;//struct Node�� node�� �θ��� ���� typedef�� �����Ѵ�

node* top;//struct Node ������ ���� top�� �����Ѵ�
node* end;//struct Node ������ ���� end�� �����Ѵ�

int is_empty();//is_empty �Լ� ������Ÿ��
int is_full();//is_full �Լ� ������Ÿ��
int push(int pushdata);//push �Լ� ������Ÿ��

int divideby2(int);//divideby2�Լ� ������Ÿ��
void clear();//clear�Լ� ������Ÿ��



void main()//���� �Լ�	
{
	top = (node*)malloc(sizeof(node));//malloc ��ɾ ����Ͽ� �޸𸮸� �Ҵ��Ͽ� �ش�
	end = (node*)malloc(sizeof(node));//malloc ��ɾ ����Ͽ� �޸𸮸� �Ҵ��Ͽ� �ش�
	top->next = end;//top�� �������� end
	end->next = end;//end�� �������� end

	int decimal;
	int pushnum;//push�� ���� �������� ���� pushnum�� �����Ѵ�
	int choice = 0;//����ڰ� ������ ���� �������� ���� choice�� �����Ѵ�

	printf("1.decimal to binary 2.clear stack 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
	scanf("%d", &choice);//����ڰ� ������ ���� �޾ƿ´�
	while (1)//while��
	{
		switch (choice) {//choice ���� ���� ����ġ��
		case 1://���� choice�� ���� 1�̸�
			printf("Write decimal number : ");// Write number want push :�� ����Ѵ�
			scanf("%d", &decimal);//decimal�� ���� �޾ƿ´�
			while (decimal >= 1)
			{
				push(divideby2(decimal));
				decimal = decimal / 2;
			}
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 2://���� choice�� ���� 2�̸�
			if (top->next == end) {//���� top�� ���� ��尡 end�� ���ٸ�(=���ÿ� �ƹ��͵� ���ٸ�)
				is_empty(); //is_empty �Լ��� �����Ѵ�
			}
			else//�ƴ϶��
			{
				clear();//pop�Լ��� �����Ѵ�
				printf("Stack is clear\n");
			}
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 3://���� choice�� ���� 3�̸�
			node* printdata;//struct Node�� ������ ���� printdata�� �����Ѵ�
			printdata = top->next;//printdata�� top�� ��������� ���� �����Ѵ�
			is_empty();//is_empty�Լ��� �����Ѵ�
			while (printdata != end)//printdata�� end�� �ƴҶ����� �ݺ��ϴ� while��
			{
				printf("%6d", printdata->key);//printdata�� key�� ���� �����Ͽ� ���
				printdata = printdata->next;//printdata�� printdata�� ���� ����� ���� ����
			}
			printf("\n");
			choice = 0;//choice�� ���� 0���� �ʱ�ȭ�Ѵ�
			break;//����ġ���� �������´�
		case 4://choice�� 4�̸�
			exit(1);//���α׷��� �����Ѵ�
		default://���� choice�� ���� �� �ܶ��
			printf("1.decimal to binary 2.clear stack 3.print 4.exit\nSelect : ");//����ڰ� �� �޴��� ����Ѵ�
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

int is_full()//������ ���������� �˷��� empty �Լ�(���� ����Ʈ�� �޸� �Ҵ� �������� ������ �����ʴ� �� �޸� ��ȭ ���´� ���ٰ� ���������� ������ ��츦 ���� ������ ���߾���)

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

int divideby2(int decimal)//10������ 2�� ���� ���������� �������� �Լ� devideby2 ����
{
	int mod;//������ ���� �������� ���� mod ����
	mod = decimal % 2;//mod�� decimal % 2�� ���� ����
	return mod;//mod���� �����Ѵ�
}

void clear(void)//������ ����� �Լ� clear ����
{
	node *newdata, *nextdata;//struct Node ������ ���� newdata�� nextdata ����
	newdata = top->next;//newdata�� top�� ��������� ���� ����
	while (newdata != end)//newdata�� end�϶����� ��ȯ�ϴ� while��
	{
		nextdata = newdata;//nextdata�� newdata�� ���� ����
		newdata = newdata->next;//newdata�� newdata�� ��������� �� ����
		free(nextdata);//nextdata�� �޸𸮸� �����
	}
	top->next = end;//top�� ������忡 end�� ���� ����
}
