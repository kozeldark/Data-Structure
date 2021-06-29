#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Node//����ü Node ����
{
	char key[100];//���ڿ��� �������� key ����
	int value;//���ڿ��� �ƽ�Ű�ڵ� ���� �������� ���� value ����
	Node * next;
};

Node * hash_table[33]; // �ؽ� ���̺�(�ش� �ε����� ����Ʈ�� �ۼ�)
char keys[33][100]; // ���ڿ� key��
int values[33]; // key�� �����ϴ� ����

int current = 0;//������ ���� �ε����� ���� �������� ���� current ���� �� 0���� �ʱ�ȭ

int hash(const char * key, int value)//�ؽ��� ���� hash �Լ�
{
	int hash = 0;
	int sum = 0;

	int str_length = strlen(key);//key�� ���ڿ��� ���̸� str_length�� ����

	for (int j = 0; j < str_length; j++)//str_length�� ���̸�ŭ �ݺ��ϴ� for��
	{
		sum = sum + key[j];//sum�� sum + key[j]�� ���� ����(�ƽ�Ű �ڵ��� ���� ���ϴ� ����)
	}
	value = sum;//value�� sum�� ���� ����

	hash = (value % 33);//hash�� value % 33�� ���� ����

	return hash;//hash�� ���� �����Ѵ�.
}
void insert(const char * key, int value)//�� ������ ������ �� �Լ� insert
{
	Node * new_node = (Node *)malloc(sizeof(Node));//Node ������ new_node ���� �� malloc���� Node�� �����ŭ �޸� �Ҵ�
	strcpy(new_node->key, key);//new_node->key�� key�� ���ڿ��� �����Ѵ�.
	new_node->value = value;//new_node->value�� value�� ���� �����Ѵ�.
	new_node->next = NULL;//new_node->next�� NULL�̴�.

	int index = hash(key, value);//key�� value ���� ���� hash �Լ� ���� �� hash �Լ��� ���� ���� index�� ����

	if (hash_table[index] == NULL) //���� hash_table[index]�� NULL�̶��
	{
		hash_table[index] = new_node;//hash_table[index]�� new_node�� ����
		printf("[%s] is inserted.\n", key);
	}

	else//�ƴ϶��
	{
		Node * cur = hash_table[index];//Node ����Ʈ���� cur�� �����ϰ� hash_table[index]�� ����Ű�� �Ѵ�.

		while (cur != NULL)//cur�� NULL�϶� ���� �ݺ�
		{
			if (strcmp(cur->key, key) == 0)//���� cur->key ���ڿ��� key ���ڿ��� ���ٸ�
			{
				cur->value = value;//cur->value�� value�� ���� ����
				printf("[%s] is exists.\n", key);
				return;//����
			}

			cur = cur->next;//cur�� cur->next�� ���� ����(�������� �Ѿ��)
		}

		//cur->key ���ڿ��� key ���ڿ��� ���� ���� ��
		new_node->next = hash_table[index];//new_node->next�� hash_table[index]�� ����
		hash_table[index] = new_node;//hash_table[index]�� new_node�� ����
		printf("[%s] is inserted.\n", key);
	}
}


int search(const char * key, int value)//key �� �˻��� ���� �Լ� search
{
	int index = hash(key, value);//key�� value ���� ���� hash �Լ� ���� �� hash �Լ��� ���� ���� index�� ����

	Node * cur = hash_table[index];//Node ����Ʈ���� cur�� �����ϰ� hash_table[index]�� ����Ű�� �Ѵ�.

	while (cur != NULL)//cur�� NULL�� ������ �ݺ�
	{
		if (strcmp(cur->key, key) == 0)//���� cur->key ���ڿ��� key ���ڿ��� ���ٸ�
		{
			value = cur->value;//value�� cur->value�� ���� ����
			return 1;//1(true)�� �����Ѵ�
		}
		cur = cur->next;//cur�� cur->next�� ���� ����(�������� �Ѿ��)
	}

	return 0;//0(false)�� �����Ѵ�

}


int del(const char * key, int value) 
{
	int index = hash(key, value);//key�� value ���� ���� hash �Լ� ���� �� hash �Լ��� ���� ���� index�� ����

	if (hash_table[index] == NULL)//���� hash_table[index]�� NULL�̶��
	{
		return 0;//0(false)�� �����Ѵ�
	}

	if (strcmp(hash_table[index]->key, key) == 0)//���� hash_table[index]->key ���ڿ��� key ���ڿ��� ���ٸ�
	{
		Node * start = hash_table[index];//Node ����Ʈ���� start�� �����ϰ� hash_table[index]�� ����Ű�� �Ѵ�.
		hash_table[index] = hash_table[index]->next;//hash_table[index]�� hash_table[index]->next�� ���� ����(���� ���� �����������)
		free(start);//start�� �Ҵ� �� �޸𸮸� �����Ѵ�.
		return 1;//1(true)�� �����Ѵ�
	}

	else//�ƴ϶��(ó������ key�� ã�� ��찡 �ƴ϶��)
	{
		Node * cur = hash_table[index];//Node ����Ʈ���� cur�� �����ϰ� hash_table[index]�� ����Ű�� �Ѵ�.
		Node * nex = hash_table[index]->next;//Node ����Ʈ���� nex�� �����ϰ� hash_table[index]->next�� ����Ű�� �Ѵ�.

		while (nex != NULL && strcmp(nex->key, key) != 0)//nex�� NULL�̰� nex->key ���ڿ��� key�� ���� ������ �ݺ�
		{
			cur = nex;//cur�� nex�� ���� ����
			nex = nex->next;//nex�� nex->next�� ���� ����
			//(�ϳ��� �̵�)
		}

		if (nex == NULL)//���� nex�� NULL�̸�(���������� Ž��������)
			return 0;//0(false)�� �����Ѵ�

		cur->next = nex->next;//cur->next�� nex->next�� ���� ����
		free(nex);//nex�� �Ҵ� �� �޸𸮸� �����Ѵ�.
		return 1;//1(true)�� �����Ѵ�
	}
}


void print()//���̺��� ������� print �Լ�
{
	for (int i = 0; i < 33; ++i)//���̺� ũ�⸸ŭ �ݺ��ϴ� for��
	{
		if (hash_table[i] != NULL)//���� hash_table[i]�� NULL�� �ƴϸ�
		{
			printf("index : %d\n", i);
		}
		else//�ƴ϶��
		{
			printf("index : %d (EMPTY)", i);
		}

			Node * cur = hash_table[i];//Node ����Ʈ���� cur�� �����ϰ� hash_table[index]�� ����Ű�� �Ѵ�.

			while (cur != NULL)//cur�� NULL�� ������ �ݺ�
			{
				printf("( %s , ASCII sum : %d ) ", cur->key, cur->value);
				cur = cur->next;//cur�� cur->next�� ���� ����(�������� �Ѿ��)
			}
			printf("\n");
	}
}
void read_file_data()//keyinput.txt ���Ͽ� �ִ� ���ڿ����� �о�� ���̺� �������� �Լ� read_file_data
{
	for (int i = 0; i < 33; ++i)//���̺� ũ�⸸ŭ �ݺ��ϴ� for��
	{
		Node * cur = hash_table[i];//Node ����Ʈ���� cur�� �����ϰ� hash_table[index]�� ����Ű�� �Ѵ�.
		Node * temp;//�ӽ� ���� �������� Node ����Ʈ���� temp

		while (cur != NULL)//cur�� NULL�϶����� �ݺ�
		{
			temp = cur;//temp�� cur�� ���� ����
			cur = cur->next;//cur�� cur->next�� ���� ����(�������� �Ѿ��)
			free(temp);//temp�� �Ҵ� �� �޸𸮸� �����Ѵ�.
		}
		hash_table[i] = NULL;//hash_table[i]�� NULL ���� �����Ѵ�(�ʱ�ȭ)
	}

	FILE *fp = fopen("keyinput.txt", "r");//keyinput.txt�� �б� �������� ����

	if (fp == NULL)//���� fp�� NULL�̸�(���� ���⿡ ����������)
		printf("keyinput.txt file open fail\n\n");
	else//�ƴ϶��
		printf("keyinput.txt file open\n\n");

	char ch[100];//keyinput.txt���� �о� �� ���ڿ��� �������� ch[100] ����
	int sum = 0;//���ڿ��� �ƽ�Ű�ڵ� ���� �������� ���� sum�� ���� �� 0���� �ʱ�ȭ

	while (fgets(ch, sizeof(ch), fp) == ch)//fgets �Լ��� ����Ǹ� ��� �ݺ�
	{
		ch[strlen(ch) - 1] = '\0';//ch�� ������ �ε����� NULL������ �Ѵ�(fgets �Լ��� ������ �ε����� \n�� �� \n�� �о���� ������)

		strcpy(keys[current], ch);//keys[current]�� ch�� ���ڿ��� �����Ͽ� �����Ѵ�.

		int str_length = strlen(keys[current]);//keys[current]�� ���ڿ��� ���̸� str_length�� ����

		for (int j = 0; j < str_length; j++)//str_length�� ���̸�ŭ �ݺ��ϴ� for��
		{
			sum = sum + keys[current][j];//sum�� sum + keys[current][j]�� ���� ����(�ƽ�Ű �ڵ��� ���� ���ϴ� ����)
		}
		values[current] = sum;//values[current]�� sum�� ���� ����
		insert(keys[current], values[current]);//keys[current], values[current] ���� ���� insert �Լ� ����

		current++;//current�� 1�� ���Ѵ�.
		sum = 0;//sum�� 0���� �ʱ�ȭ�Ѵ�.
	}
}
int main()//���� �Լ�
{
	read_file_data();

	print();

	int choice;//������� ���� ���� �������� ���� choice ����
	printf("1.insert 2.delete 3.search 4.print 5.quit\n");//�޴� ���
	scanf("%d", &choice);//����ڰ� �Է��� ���� choice�� ����

	int sum = 0;//���� ������ ���ڿ��� �ƽ�Ű�ڵ� ���� �������� ���� sum�� ����
	int str_length;//���� ������ ���ڿ��� ������ ���� �������� ���� str_length�� ����

	while (choice != 5)//choice�� 5�� �Ǳ� ������ �ݺ��ϴ� while��
	{
		switch (choice)//choice�� ���� ���� switch��
		{
		case 1://choice�� 1�̸�
			printf("What want insert key?\n");
			scanf("%s",&keys[current]);//����ڰ� �Է��� ���ڿ��� ��ĵ�Ͽ� keys[current]�� ����
			str_length = strlen(keys[current]);//keys[current]�� ���ڿ��� ���̸� str_length�� ����

			for (int j = 0; j < str_length; j++)//str_length�� ���̸�ŭ �ݺ��ϴ� for��
			{
				sum = sum + keys[current][j];//sum�� sum + keys[current][j]�� ���� ����(�ƽ�Ű �ڵ��� ���� ���ϴ� ����)
			}
			values[current] = sum;//values[current]�� sum�� ���� ����
			insert(keys[current], values[current]);//keys[current], values[current] ���� ���� insert �Լ� ����


			current++;//current�� 1�� ���Ѵ�.
			sum = 0;//sum�� 0���� �ʱ�ȭ�Ѵ�.

			choice = 0;
			break;
			//choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		case 2://choice�� 2�̸�
			char delkey[100];//����ڰ� �����ϱ� ���ϴ� ���ڿ��� ������ delkey ����
			printf("What want delete key?\n");
			scanf("%s", &delkey);//����ڰ� �Է��� ���ڿ��� ��ĵ�Ͽ� delkey�� ����
			if (del(delkey,0))//���� del(delkey,0)�� true�̸�
			{
				printf("Delete [%s] in hash table.\n", delkey);
			}
			else//�ƴ϶��
			{
				printf("Can't delete [%s] in hash table...\n", delkey);
			}

			choice = 0;
			break;
			//choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		case 3://choice�� 3�̸�
			char sh[100];//����ڰ� �˻��ϱ� ���ϴ� ���ڿ��� ������ sh ����
			printf("What want search key?\n");
			scanf("%s", &sh);//����ڰ� �Է��� ���ڿ��� ��ĵ�Ͽ� sh�� ����

			if (search(sh, 0))//���� search(sh,0)�� true�̸�
			{
				printf("Found [%s] in hash table.\n", sh);
			}
			else
			{
				printf("Can't found [%s] in hash table...\n", sh);
			}
			choice = 0;
			break;
			//choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		case 4://choice�� 4�̸�
			print();

			choice = 0;
			break;
			//print�Լ� ���� �� choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		default:
			printf("1.insert 2.delete 3.search 4.print 5.quit\n");
			scanf("%d", &choice);
		}
	}

	return 0;
}