// ConsoleApplication85.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include<stdio.h>
#include  <stdlib.h>
#include  <time.h>
#define RMAX 100

typedef struct node
{
	int data;
	struct node *left, *right;
	int ht;
}node;

node *insert(node *, int);
node *Delete(node *, int);
void preorder(node *);
void inorder(node *);
int height(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);

node * avl_search(node *, int);
void range(node *, int, int);
node* findmax(node*);

int main()
{
	node *root = NULL;
	int x, n, i, op;
	int maximunkey;

	do
	{
		printf("\n1)Start insert random value(First try it!!)");
		printf("\n2)Range Search");
		printf("\n3)Find maximun value in AVL tree");
		printf("\n4)Single Search");
		printf("\n5)Print AVL tree inorder traversal");
		printf("\n6)Quit");

		printf("\n\nEnter Your Choice :");
		scanf("%d", &op);

		switch (op)
		{
		case 1: 
			root = NULL;

			srand(time(NULL));
			int randomarr[200];
			randomarr[1] = 15;
			randomarr[2] = 50;

			for (int i = 3; i <= 200; i++)
			{
				randomarr[i] = 1 + (int)rand() % RMAX;
			}

			for (int j = 1; j <= 200; j++)
			{
				root = insert(root, randomarr[j]);
			}
			printf("\nComplete insert random value to AVL!!\n");
			break;

		case 2: 
			int min, max ;
			printf("\nEnter a minimun : ");
			scanf("%d", &min);
			printf("\nEnter a maximun : ");
			scanf("%d", &max);
			printf("\n");
			range(root, min,max);
			printf("\n");
			break;

		case 3: 
			maximunkey = findmax(root)->data;
			printf("\n");
			printf("Maximun value is %d", maximunkey);
			printf("\n");
			break;

		case 4:
			printf("\n Enter find key : ");
			scanf("%d", &x);	
			if (avl_search(root, x) == NULL)
			{
				printf("[%d] This value is not in the avl tree.\n", x);
			}
			else
			{
				int search = avl_search(root, x)->data;
				printf("[%d] This value is in the avl tree.\n", search);
			}
			break;
		case 5:
			printf("\n ====== Inorder traversal ====== \n ");
			inorder(root);
			printf("\n");
			break;
		}
	} while (op != 6);

	return 0;
}

node * avl_search(node *T, int x)
{
	if (T == NULL)
		return NULL;
	if (x == T->data) 
		return (T);
	else if (x < T->data)
		return avl_search(T->left, x);
	else
		return avl_search(T->right, x);
}

node * insert(node *T, int x)
{
	if (T == NULL)
	{
		T = (node*)malloc(sizeof(node));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	}
	else
		if (x > T->data)		// insert in right subtree
		{
			T->right = insert(T->right, x);
			if (BF(T) == -2)
				if (x>T->right->data)
					T = RR(T);
				else
					T = RL(T);
		}
		else
			if (x<T->data)
			{
				T->left = insert(T->left, x);
				if (BF(T) == 2)
					if (x < T->left->data)
						T = LL(T);
					else
						T = LR(T);
			}

	T->ht = height(T);

	return(T);
}

node * Delete(node *T, int x)
{
	node *p;

	if (T == NULL)
	{
		return NULL;
	}
	else
		if (x > T->data)		// insert in right subtree
		{
			T->right = Delete(T->right, x);
			if (BF(T) == 2)
				if (BF(T->left) >= 0)
					T = LL(T);
				else
					T = LR(T);
		}
		else
			if (x<T->data)
			{
				T->left = Delete(T->left, x);
				if (BF(T) == -2)	//Rebalance during windup
					if (BF(T->right) <= 0)
						T = RR(T);
					else
						T = RL(T);
			}
			else
			{
				//data to be deleted is found
				if (T->right != NULL)
				{	//delete its inorder succesor
					p = T->right;

					while (p->left != NULL)
						p = p->left;

					T->data = p->data;
					T->right = Delete(T->right, p->data);

					if (BF(T) == 2)//Rebalance during windup
						if (BF(T->left) >= 0)
							T = LL(T);
						else
							T = LR(T); \
				}
				else
					return(T->left);
			}
	T->ht = height(T);
	return(T);
}

int height(node *T)
{
	int lh, rh;
	if (T == NULL)
		return(0);

	if (T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;

	if (T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;

	if (lh>rh)
		return(lh);

	return(rh);
}

node * rotateright(node *x)
{
	node *y;
	y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return(y);
}

node * rotateleft(node *x)
{
	node *y;
	y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height(x);
	y->ht = height(y);

	return(y);
}

node * RR(node *T)
{
	T = rotateleft(T);
	return(T);
}

node * LL(node *T)
{
	T = rotateright(T);
	return(T);
}

node * LR(node *T)
{
	T->left = rotateleft(T->left);
	T = rotateright(T);

	return(T);
}

node * RL(node *T)
{
	T->right = rotateright(T->right);
	T = rotateleft(T);
	return(T);
}

int BF(node *T)
{
	int lh, rh;
	if (T == NULL)
		return(0);

	if (T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;

	if (T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;

	return(lh - rh);
}


void inorder(node *T)
{
	if (T != NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d)", T->data, BF(T));
		inorder(T->right);
	}
}

void range(node *T, int min, int max)
{
	if (NULL == T)
		return;

	if (min < T->data)
	{
		range(T->left, min, max);
	}

	if (min < T->data && max > T->data)
		printf("%d ", T->data);

	if (max > T->data)
		range(T->right, min, max);
}

node* findmax(node* T) 
{
	if (T->right == NULL) 
	{
		return (T);
	}
	else 
	{
		return findmax(T->right);
	}
}