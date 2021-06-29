// ConsoleApplication77.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h> 
#include <stdlib.h> 

struct LCRSnode//LCRS Ʈ�� ������ ���� ����ü�� �����Ѵ�

{
		struct LCRSnode* leftchild;//���� ��带 �������� ������ ������ �����Ѵ�
		struct LCRSnode* rightsibling;//������ ��带 �������� ������ ������ �����Ѵ�
		int key;//LCRS �� ��忡 �� �������� ���� �������� ������ �����Ѵ�
};

LCRSnode * createnode(int newdata)//newdata�� ���� ���� ���ο� ��带 �������� createnode �Լ��� �����Ѵ�.
{
	LCRSnode * newnode = (LCRSnode *)malloc(sizeof(LCRSnode));//malloc ��ɾ ����Ͽ� �޸𸮸� �Ҵ��Ͽ� �ش�
	newnode->leftchild = NULL;//newnode�� ���� ��带 �ʱ�ȭ�Ѵ�(���� �����Ͱ� �����Ƿ�)
	newnode->rightsibling = NULL;//newnode�� ������ ��带 �ʱ�ȭ�Ѵ�(���� �����Ͱ� �����Ƿ�)

	newnode->key = newdata;////newnode�� ����ü key���� newdata�� ���� �����Ѵ�

	return newnode;//newnode ���� �����Ѵ�
}

void LCRS(LCRSnode*, LCRSnode*);//LCRS �Լ� ������Ÿ��
void print(LCRSnode*, int);//print �Լ� ������Ÿ��
void preorder(LCRSnode*);//LCRS �Լ� ������Ÿ��

void LCRS(LCRSnode * parent, LCRSnode * child)//LCRS�� ���� �Լ� LCRS�� �����Ѵ�
{
	if (parent->leftchild == NULL)//���� parent�� ���� ��尡 NULL�̶��
	{
		parent->leftchild = child;//parent�� ���� ��忡 child�� ���� �����Ѵ�
	}
	else//�ƴ϶��
	{
		LCRSnode * current = parent->leftchild;//���� ���� ��Ÿ���� ����ü current ���� �� parent�� ���� ����� ���� �����Ѵ�

		while (current->rightsibling != NULL)//current�� ������ ��尡 NULL�� �ƴҶ����� �ݺ��ϴ� while��
		{
			current = current->rightsibling;//current�� current�� ������ ����� ���� �����Ѵ�
		}
		current->rightsibling = child;//current�� ������ ��忡 child�� ���� �����Ѵ�
	}
}

void print(LCRSnode * node, int treelevel)//LCRS Ʈ���� ������� print �Լ��� �����Ѵ�
{
	for (int i = 0; i < treelevel; i++)//0���� treelevel�� ������ 1�� ���ϸ鼭 �ݺ��ϴ� for�� ����
		printf(" |_ ");// |_ �� ����Ѵ�(Ʈ���� ������ �����ϱ� ���� �ϴ� �뵵)

	printf("[%d]\n", node->key);//[node�� ����ü key ��]�� ����Ѵ�

	if (node->leftchild != NULL)//���� node�� ���� ��尡 NULL�� �ƴҰ��
		print(node->leftchild, treelevel + 1);//node�� ���� ����� ���� treelevel+1�� ���� ���� print �Լ��� �����Ѵ�
	//(LCRS �Լ� ������ �׷����� ������ 45���� ������ ���� Ʈ���� ���� ���� ��尡 ���ö� treelevel�� 1�� �����Ѵ�. ������ ���� �������� �ʴ´�)

	if (node->rightsibling != NULL)//���� node�� ������ ��尡 NULL�� �ƴҰ��
		print(node->rightsibling, treelevel);//node�� ������ ����� ���� treelevel�� ���� ���� print �Լ��� �����Ѵ�

}

void preorder(LCRSnode  *node)//tree�� ���� ���� ������ ���� preorder �Լ��� �����Ѵ�
{
	if (node)//���� node�� ���� �ִٸ�
	{
		printf("%d\n", node->key);//����� ����ü key ���� ����Ѵ�
		preorder(node->leftchild);//����� ���� ����� ���� ���� preorder �Լ��� �����Ѵ�
		preorder(node->rightsibling);//����� ������ ����� ���� ���� preorder �Լ��� �����Ѵ�
	}
}

int main()//���� �Լ��� �����Ѵ�
{
	printf("question 1\n");//ȭ�鿡 question 1�� ����Ѵ�
	printf("- LCRS tree -\n");//ȭ�鿡 - LCSR tree -�� ����Ѵ�

	LCRSnode * root = createnode(100);//��� root ���� �� �� 100�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n2 = createnode(200);//��� n2 ���� �� �� 200�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n3 = createnode(75);//��� n3 ���� �� �� 75�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n4 = createnode(300);//��� n4 ���� �� �� 300�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n5 = createnode(25);//��� n5 ���� �� �� 25�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n6 = createnode(50);//��� n6 ���� �� �� 50�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n7 = createnode(30);//��� n7 ���� �� �� 30�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n8 = createnode(150);//��� n8 ���� �� �� 150�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n9 = createnode(120);//��� n9 ���� �� �� 120�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n10 = createnode(55);//��� n10 ���� �� �� 55�� ���� createnode �Լ��� ���� �����Ѵ�.

	LCRS(root, n2);//�θ� ��尡 root�̰� �ڽĳ�尡 n2�� LCRS �Լ��� �����Ѵ�
	LCRS(root, n3);//�θ� ��尡 root�̰� �ڽĳ�尡 n3�� LCRS �Լ��� �����Ѵ�
	LCRS(root, n4);//�θ� ��尡 root�̰� �ڽĳ�尡 n4�� LCRS �Լ��� �����Ѵ�
	LCRS(n3, n5);//�θ� ��尡 root�̰� �ڽĳ�尡 n5�� LCRS �Լ��� �����Ѵ�
	LCRS(n3, n6);//�θ� ��尡 root�̰� �ڽĳ�尡 n6�� LCRS �Լ��� �����Ѵ�
	LCRS(n4, n7);//�θ� ��尡 root�̰� �ڽĳ�尡 n7�� LCRS �Լ��� �����Ѵ�
	LCRS(n4, n8);//�θ� ��尡 root�̰� �ڽĳ�尡 n8�� LCRS �Լ��� �����Ѵ�
	LCRS(n7, n9);//�θ� ��尡 root�̰� �ڽĳ�尡 n9�� LCRS �Լ��� �����Ѵ�
	LCRS(n7, n10);//�θ� ��尡 root�̰� �ڽĳ�尡 n10�� LCRS �Լ��� �����Ѵ�
	
	print(root, 0);//root �� treelevel 0���� �����ؼ� Ʈ���� ������� print �Լ��� �����Ѵ�

	printf("\n- preorder -\n");//- preorder -�� ����Ѵ�
	preorder(root);//root���� ���� ������ ���� preorder �Լ��� �����Ѵ�

	printf("====================");//������ ���� ���� ����Ѵ�
	printf("\nquestion 2\n");//question 2�� ����Ѵ�
	printf("- LCRS tree -\n");//- LCRS tree -�� ����Ѵ�

	LCRSnode * root2 = createnode(100);//��� root2 ���� �� �� 100�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n2_2 = createnode(200);//��� n2_2 ���� �� �� 200�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n3_2 = createnode(75);//��� n3_2 ���� �� �� 75�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n4_2 = createnode(300);//��� n4_2 ���� �� �� 300�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n5_2 = createnode(95);//��� n5_2 ���� �� �� 95�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n6_2 = createnode(25);//��� n6_2 ���� �� �� 25�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n7_2 = createnode(50);//��� n7_2 ���� �� �� 50�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n8_2 = createnode(30);//��� n8_2 ���� �� �� 30�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n9_2 = createnode(150);//��� n9_2 ���� �� �� 150�� ���� createnode �Լ��� ���� �����Ѵ�.
	LCRSnode* n10_2 = createnode(120);//��� n10_2 ���� �� �� 120�� ���� createnode �Լ��� ���� �����Ѵ�.

	LCRS(root2, n2_2);//�θ� ��尡 root2�̰� �ڽĳ�尡 n2_2�� LCRS �Լ��� �����Ѵ�
	LCRS(root2, n3_2);//�θ� ��尡 root2�̰� �ڽĳ�尡 n3_2�� LCRS �Լ��� �����Ѵ�
	LCRS(root2, n4_2);//�θ� ��尡 root2�̰� �ڽĳ�尡 n4_2�� LCRS �Լ��� �����Ѵ�
	LCRS(root2, n5_2);//�θ� ��尡 root2�̰� �ڽĳ�尡 n5_2�� LCRS �Լ��� �����Ѵ�
	LCRS(n3_2, n6_2);//�θ� ��尡 n3_2�̰� �ڽĳ�尡 n6_2�� LCRS �Լ��� �����Ѵ�
	LCRS(n3_2, n7_2);//�θ� ��尡 n3_2�̰� �ڽĳ�尡 n7_2�� LCRS �Լ��� �����Ѵ�
	LCRS(n3_2, n8_2);//�θ� ��尡 n3_2�̰� �ڽĳ�尡 n8_2�� LCRS �Լ��� �����Ѵ�
	LCRS(n5_2, n9_2);//�θ� ��尡 n5_2�̰� �ڽĳ�尡 n9_2�� LCRS �Լ��� �����Ѵ�
	LCRS(n8_2, n10_2);//�θ� ��尡 n8_2�̰� �ڽĳ�尡 n10_2�� LCRS �Լ��� �����Ѵ�

	print(root2, 0);//root2 �� treelevel 0���� �����ؼ� Ʈ���� ������� print �Լ��� �����Ѵ�

	printf("\n- preorder -\n");//- preorder -�� ����Ѵ�
	preorder(root2);//root2���� ���� ������ ���� preorder �Լ��� �����Ѵ�

	system("pause");//���â�� ������ �ʰ� �����Ѵ�

	return 0;//0�� �����Ѵ�
}
