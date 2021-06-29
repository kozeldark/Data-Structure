// ConsoleApplication96.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RMAX 100 //������ �ִ��� 100���� �����Ѵ�.

struct array//����ü array ����
{
	int data;//������ ���� �������� int�� ���� data ����
};

struct array table1[15][3];//table1�� ��15 ��3�� ũ��� �����Ѵ�.
struct array table2[10][3];//table1�� ��10 ��3�� ũ��� �����Ѵ�.

void make_table_rand()//���̺� ���� 1~100������ ������ ���� �־��� �Լ� make_table_rand
{
	int i, j = 0;

	for (i = 0; i < 15; i++)//table1�� ���� ũ�⸸ŭ �ݺ�
	{
		for (j = 0; j < 3; j++)//table1�� ���� ũ�⸸ŭ �ݺ�
		{
			table1[i][j].data = 1 + (int)rand() % RMAX;//table1[i][j].data�� 1~100������ ������ ���� �ִ´�.
		}
	}

	i, j = 0;

	for (i = 0; i < 10; i++)//table2�� ���� ũ�⸸ŭ �ݺ�
	{
		for (j = 0; j < 3; j++)//table2�� ���� ũ�⸸ŭ �ݺ�
		{
			table2[i][j].data = 1 + (int)rand() % RMAX;//table2[i][j].data�� 1~100������ ������ ���� �ִ´�.
		}
	}

}

void print1()//table1�� ������� �Լ� print1
{
	printf("\n\n\n");
	printf("        \nTABLE 1\n        ");
	int i, j = 0;
	for (i = 0; i < 15; i++)//table1�� ���� ũ�⸸ŭ �ݺ�
	{
		printf("|");
		printf("\n�ѤѤѤѤѤѤѤ�\n");	
		for (j = 0; j < 3; j++)//table1�� ���� ũ�⸸ŭ �ݺ�
		{
			printf("| %d ", table1[i][j].data);//table1[i][j].data ���
		}
	}
	printf("|");
	printf("\n�ѤѤѤѤѤѤѤ�\n\n\n");

}



void print2()//table2�� ������� �Լ� print1
{
	printf("\n\n\n");
	printf("        \nTABLE 2\n        ");
	int i, j = 0;
	for (i = 0; i < 10; i++)//table2�� ���� ũ�⸸ŭ �ݺ�
	{
		printf("|");
		printf("\n�ѤѤѤѤѤѤѤ�\n");//table2�� ���� ũ�⸸ŭ �ݺ�
		for (j = 0; j < 3; j++)
		{
			printf("| %d ", table2[i][j].data);//table2[i][j].data ���
		}
	}
	printf("|");
	printf("\n�ѤѤѤѤѤѤѤ�\n\n\n");
}

void duplex_selection_sort(struct array num[][3], int col, int end)//���� ���� �迭�� ���� �Լ� duplex_selection_sort
{
	int left = 0;//���� ���� �ε����� 0���� ����
	int right = end - 1;//���� ���� �ε����� n -1�� ����(�迭�� ũ�� - 1�� �ִ� �ε��� �̹Ƿ�)

	int minimum_index = -1;//�ּҰ� �ε����� �������� ���� minimum_index�� �����ϰ� -1�� �ʱ�ȭ
	int maximum_index = -1;//�ִ� �ε����� �������� ���� maximum_index�� �����ϰ� -1�� �ʱ�ȭ

	int min = 101;//�ּҰ��� �������� ���� min�� �����ϰ� 101�� �ʱ�ȭ(1~100������ ���� ������ �̹Ƿ� 101���� ������ ����)
	int max = -1;//�ּҰ��� �������� ���� max�� �����ϰ� -1�� �ʱ�ȭ(1~100������ ���� ������ �̹Ƿ� -1���� ������ ����)

	int temp = -1;//�ӽð��� �������� temp

	while (left < right)//right�� left���� Ŭ ������ �ݺ�
	{
		for (int i = left; i <= right; i++)//left ~ right�� �ݺ��ϴ� for��
		{
			if (max < num[i][col].data)//���� num[i][col].data�� max���� ũ��
			{
				maximum_index = i;//maximum_index�� i�� �����Ѵ�
				max = num[i][col].data;//max�� ���� num[i][col].data�� �����Ѵ�.
			}

			if (min > num[i][col].data)//���� num[i][col].data�� min���� ������
			{
				minimum_index = i;//minimum_index�� i�� �����Ѵ�
				min = num[i][col].data;//min�� ���� num[i][col].data�� �����Ѵ�.
			}

		}

		if (maximum_index == left && minimum_index == right)//���� maximum_index�� left�� ���� minimum_index�� right�� ������
		{
			temp = num[right][col].data;
			num[right][col].data = num[maximum_index][col].data;
			num[maximum_index][col].data = temp;
			//num[right][col].data�� num[maximum_index][col].data�� ���� ���� �ٲߴϴ�.
		}

		else//�ƴ϶��
		{
			temp = num[right][col].data;
			num[right][col].data = num[maximum_index][col].data;
			num[maximum_index][col].data = temp;
			//num[right][col].data�� num[maximum_index][col].data�� ���� ���� �ٲߴϴ�.

			temp = num[left][col].data;
			num[left][col].data = num[minimum_index][col].data;
			num[minimum_index][col].data = temp;
			//num[left][col].data�� num[minimum_index][col].data�� ���� ���� �ٲߴϴ�.
		}

		min = 101;//�ּڰ� �ٽ� �ʱ�ȭ
		max = -1;//�ִ� �ٽ� �ʱ�ȭ

		left++;//���� ���� �ε����� 1 ���մϴ�.
		right--;//���� ���� �ε����� 1 ���ϴ�.

	}
}
void quick_sort(struct array data[][3], int col, int start, int end)//�� �迭�� ���� �Լ� quick_sort
{
	if (start >= end)//start�� end �̻��� ��(�κ� ����Ʈ���� �� �̻� ������ �Ұ����� ��) �����Ѵ�.
		return;

	int pivot = start;//�ǹ��� start�� �����Ѵ�.
	int i = pivot + 1;//���� ���� �ε����� pivot + 1�� �����Ѵ�.
	int j = end - 1;//���� ���� �ε����� end -1�� ����(�迭�� ũ�� - 1�� �ִ� �ε��� �̹Ƿ�)
	int temp;//�ӽð��� �������� temp

	while (i <= j)//j�� i �̻��϶����� �ݺ�
	{
		while (i <= end && data[i][col].data <= data[pivot][col].data)
		//���� ���� �ε����� ���� ���� �ε��� �����̸� ���� ���� �ε��� ���� col ���� ���� �ǹ� ���� col ���� �� ���ϰ� �ƴҶ����� �ݺ�
		{
			i++;//i�� 1�� ���Ѵ�
		}
		while (j > start && data[j][col].data >= data[pivot][col].data)
		//���� ���� �ε����� �ǹ� �ε��� �����̸� ���� ���� �ε��� ���� col ���� ���� �ǹ� ���� col ���� �� �̻��� �ƴҶ����� �ݺ�
		{
			j--;//j�� 1�� ����
		}

		if (i > j)//���� ���� ���� �ε����� ���� ���� �ε��� ���� ũ��
		{
			temp = data[j][col].data;
			data[j][col].data = data[pivot][col].data;
			data[pivot][col].data = temp;
			//data[j][col].data�� ���� data[pivot][col].data�� ���� ���� �ٲ۴�.
		}
		else//�ƴ϶��
		{
			temp = data[i][col].data;
			data[i][col].data = data[j][col].data;
			data[j][col].data = temp;
			//data[i][col].data�� ���� data[j][col].data�� ���� ���� �ٲ۴�.
		}
	}
	quick_sort(data, col, start, j - 1);//ù ���� ���� �ε����� ���� 1 ���� quick_sort �Լ� ����
	quick_sort(data, col, j + 1, end);//ù ���� ���� �ε����� ���� 1 ���� quick_sort �Լ� ����

}
void join(struct array t1[][3], struct array t2[][3], int t1c, int t2c, int val)//�� ���̺��� merge join�� ���� �Լ� join
{
	struct array merge_table[15][10];//�� ���̺��� merge join�� ���̺��� �������� merge_table

	int i, j = 0;

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 10; j++)
		{
			merge_table[i][j].data = NULL;//���� merge_table�� �ʱ�ȭ�Ѵ�
		}
	}

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 3; j++)
		{
			merge_table[i][j].data = table1[i][j].data;//merge_table�� table1�� ���� �����Ѵ�
		}
	}
	int curt2c = t2c;//���� t2c�� ���� �������� curt2c ����
	int curcol = 3;//merge ���� �� mergetable�� ������ ���� ���� �������� curcol

	i, j = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 10; j++)
		{
			t2c = curt2c;//t2c�� curt2c�� �ʱ�ȭ
			curcol = 3;//curcol�� 3���� �ʱ�ȭ
			if (t1[i][t1c].data == t2[j][t2c].data && t1[i][t1c].data == val)
			//���� t1[i][t1c].data�� ���� t2[j][t2c].data�� ���� val�� ���� ��� ���ٸ�
			{
				while (t2c != 2)//t2c�� 2�϶����� �ݺ�
				{ 
					merge_table[i][curcol].data = t2[j][t2c+1].data;//merge_table[i][curcol].data�� t2[j][t2c+1].data�� ���� �����Ѵ�.
					t2c++;//t2c�� 1�� ���Ѵ�.
					curcol++;//curcol�� 1�� ���Ѵ�
				}
			}
		}
	}
	printf("\n\n\n");
	printf("        \nMERGE JOIN TABLE\n        ");

	for (i = 0; i < 15; i++)
	{
		printf("|");
		printf("\n�ѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
		for (j = 0; j < 10; j++)
		{
			if(merge_table[i][j].data != NULL)//���� merge_table[i][j].data�� NULL�� �ƴϸ�
				printf("| %d ", merge_table[i][j].data);//merge_table[i][j].data ���
		}
	}
	printf("|");
	printf("\n�ѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n\n");
}

int main()//���� �Լ�
{
	srand(time(NULL));//srand �Լ� �ʱ�ȭ

	make_table_rand();//make_table_rand �Լ� ����

	print1();
	print2();

	printf("Table 1, row 10 & 14 column 3 (change the value to 55) Table 2, row 5, column 1 (change the value to 55)\n");

	
	table1[9][2].data = 55;
	table1[13][2].data = 55;
	table2[4][0].data = 55;
	//������ �䱸�� Table 1, row 10 & 14 column 3 change the value to 55 and Table 2, row 5, column 1 change the value to 55

	print1();
	print2();

	int choice;//������� ���� ���� �������� ���� choice ����
	printf("1.Dulplex Seletion Sort 2.Quick sort 3.Merge join 4.Remake Random Table 5.quit\n");//�޴� ���
	scanf("%d", &choice);//����ڰ� �Է��� ���� choice�� ����

	while (choice != 5)//choice�� 5�� �Ǳ� ������ �ݺ��ϴ� while��
	{
		switch (choice)//choice�� ���� ���� switch��
		{
		case 1://choice�� 1�̸�
			printf("\nDulplex Seletion Sort in Table1(on column 3) and Table2(on column 1)\n");

			for (int i = 0; i < 3; i++)
				duplex_selection_sort(table1, 2, 15);

			for (int i = 0; i < 3; i++)
				duplex_selection_sort(table2, 0, 10);

			print1();
			print2();
			choice = 0;
			break;
			//���� ���� �迭�� �����ϰ� �� ���̺��� ��� �� choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		case 2://choice�� 2�̸�
			printf("\nQuick sort in Table1(on column 3) and Table2(on column 1)\n");

			for (int i = 0; i < 3; i++)
				quick_sort(table1, 2, 0, 15);

			for (int i = 0; i < 3; i++)
				quick_sort(table2, 0, 0, 10);

			print1();
			print2();
			choice = 0;
			break;
			//�� �迭�� �����ϰ� �� ���̺��� ��� �� choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		case 3://choice�� 3�̸�
			printf("\nMerge join in Table1(on column 3) and Table2(on column 1)\n");
			join(table1, table2, 2, 0, 55);

			choice = 0;
			break;
			//merge join�� �����ϰ� �� ���̺��� ��� �� choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		case 4://choice�� 4�̸�
			make_table_rand();
			print1();
			print2();

			printf("Table 1, row 10 & 14 column 3 (change the value to 55) Table 2, row 5, column 1 (change the value to 55)\n");

			table1[9][2].data = 55;
			table1[13][2].data = 55;
			table2[4][0].data = 55;

			print1();
			print2();
			choice = 0;
			break;
			//�� ���̺� �ٽ� 1~100������ ������ ���� �Ҵ��Ͽ��ְ� ������ �䱸�� �κ��� ���� 55�� �����ϰ� �� ���̺��� ��� �� choice�� ���� �ʱ�ȭ�ϰ� switch���� ��������
		default://�� ���� ���̶��
			printf("1.Dulplex Seletion Sort 2.Quick sort 3.Merge join 4.Remake Random Table 5.quit\n");//�ٽ� �޴� ���
			scanf("%d", &choice);
		}
	}
	
    return 0;
}
