// ConsoleApplication77.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h> 
#include <stdlib.h> 

struct LCRSnode//LCRS 트리 구현을 위한 구조체를 정의한다

{
		struct LCRSnode* leftchild;//왼쪽 노드를 가르켜줄 포인터 변수를 선언한다
		struct LCRSnode* rightsibling;//오른쪽 노드를 가르켜줄 포인터 변수를 선언한다
		int key;//LCRS 각 노드에 들어갈 데이터의 값을 저장해줄 변수를 선언한다
};

LCRSnode * createnode(int newdata)//newdata의 값에 따른 새로운 노드를 생성해줄 createnode 함수를 정의한다.
{
	LCRSnode * newnode = (LCRSnode *)malloc(sizeof(LCRSnode));//malloc 명령어를 사용하여 메모리를 할당하여 준다
	newnode->leftchild = NULL;//newnode의 왼쪽 노드를 초기화한다(아직 데이터가 없으므로)
	newnode->rightsibling = NULL;//newnode의 오른쪽 노드를 초기화한다(아직 데이터가 없으므로)

	newnode->key = newdata;////newnode의 구조체 key값에 newdata의 값을 대입한다

	return newnode;//newnode 값을 리턴한다
}

void LCRS(LCRSnode*, LCRSnode*);//LCRS 함수 프로토타입
void print(LCRSnode*, int);//print 함수 프로토타입
void preorder(LCRSnode*);//LCRS 함수 프로토타입

void LCRS(LCRSnode * parent, LCRSnode * child)//LCRS를 해줄 함수 LCRS를 정의한다
{
	if (parent->leftchild == NULL)//만약 parent의 왼쪽 노드가 NULL이라면
	{
		parent->leftchild = child;//parent의 왼쪽 노드에 child의 값을 대입한다
	}
	else//아니라면
	{
		LCRSnode * current = parent->leftchild;//현재 값을 나타내줄 구조체 current 선언 및 parent의 왼쪽 노드의 값을 대입한다

		while (current->rightsibling != NULL)//current의 오른쪽 노드가 NULL이 아닐때까지 반복하는 while문
		{
			current = current->rightsibling;//current에 current의 오른쪽 노드의 값을 대입한다
		}
		current->rightsibling = child;//current의 오른쪽 노드에 child의 값을 대입한다
	}
}

void print(LCRSnode * node, int treelevel)//LCRS 트리를 출력해줄 print 함수를 정의한다
{
	for (int i = 0; i < treelevel; i++)//0부터 treelevel의 값까지 1씩 더하면서 반복하는 for문 실행
		printf(" |_ ");// |_ 를 출력한다(트리의 레벨을 구별하기 쉽게 하는 용도)

	printf("[%d]\n", node->key);//[node의 구조체 key 값]을 출력한다

	if (node->leftchild != NULL)//만약 node의 왼쪽 노드가 NULL이 아닐경우
		print(node->leftchild, treelevel + 1);//node의 왼쪽 노드의 값과 treelevel+1의 값에 대한 print 함수를 실행한다
	//(LCRS 함수 과정을 그려보면 마지막 45도로 돌리기 전에 트리를 보면 왼쪽 노드가 나올때 treelevel이 1이 증가한다. 오른쪽 노드는 증가하지 않는다)

	if (node->rightsibling != NULL)//만약 node의 오른쪽 노드가 NULL이 아닐경우
		print(node->rightsibling, treelevel);//node의 오른쪽 노드의 값과 treelevel의 값에 대한 print 함수를 실행한다

}

void preorder(LCRSnode  *node)//tree에 대한 전위 운행을 해줄 preorder 함수를 정의한다
{
	if (node)//만약 node에 값이 있다면
	{
		printf("%d\n", node->key);//노드의 구조체 key 값을 출력한다
		preorder(node->leftchild);//노드의 왼쪽 노드의 값에 따른 preorder 함수를 실행한다
		preorder(node->rightsibling);//노드의 오른쪽 노드의 값에 따른 preorder 함수를 실행한다
	}
}

int main()//메인 함수를 정의한다
{
	printf("question 1\n");//화면에 question 1을 출력한다
	printf("- LCRS tree -\n");//화면에 - LCSR tree -을 출력한다

	LCRSnode * root = createnode(100);//노드 root 생성 및 값 100에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n2 = createnode(200);//노드 n2 생성 및 값 200에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n3 = createnode(75);//노드 n3 생성 및 값 75에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n4 = createnode(300);//노드 n4 생성 및 값 300에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n5 = createnode(25);//노드 n5 생성 및 값 25에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n6 = createnode(50);//노드 n6 생성 및 값 50에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n7 = createnode(30);//노드 n7 생성 및 값 30에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n8 = createnode(150);//노드 n8 생성 및 값 150에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n9 = createnode(120);//노드 n9 생성 및 값 120에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n10 = createnode(55);//노드 n10 생성 및 값 55에 관한 createnode 함수의 값을 저장한다.

	LCRS(root, n2);//부모 노드가 root이고 자식노드가 n2인 LCRS 함수를 실행한다
	LCRS(root, n3);//부모 노드가 root이고 자식노드가 n3인 LCRS 함수를 실행한다
	LCRS(root, n4);//부모 노드가 root이고 자식노드가 n4인 LCRS 함수를 실행한다
	LCRS(n3, n5);//부모 노드가 root이고 자식노드가 n5인 LCRS 함수를 실행한다
	LCRS(n3, n6);//부모 노드가 root이고 자식노드가 n6인 LCRS 함수를 실행한다
	LCRS(n4, n7);//부모 노드가 root이고 자식노드가 n7인 LCRS 함수를 실행한다
	LCRS(n4, n8);//부모 노드가 root이고 자식노드가 n8인 LCRS 함수를 실행한다
	LCRS(n7, n9);//부모 노드가 root이고 자식노드가 n9인 LCRS 함수를 실행한다
	LCRS(n7, n10);//부모 노드가 root이고 자식노드가 n10인 LCRS 함수를 실행한다
	
	print(root, 0);//root 및 treelevel 0부터 시작해서 트리를 출력해줄 print 함수를 실행한다

	printf("\n- preorder -\n");//- preorder -를 출력한다
	preorder(root);//root부터 전위 운행을 해줄 preorder 함수를 실행한다

	printf("====================");//구별을 위한 줄을 출력한다
	printf("\nquestion 2\n");//question 2를 출력한다
	printf("- LCRS tree -\n");//- LCRS tree -를 출력한다

	LCRSnode * root2 = createnode(100);//노드 root2 생성 및 값 100에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n2_2 = createnode(200);//노드 n2_2 생성 및 값 200에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n3_2 = createnode(75);//노드 n3_2 생성 및 값 75에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n4_2 = createnode(300);//노드 n4_2 생성 및 값 300에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n5_2 = createnode(95);//노드 n5_2 생성 및 값 95에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n6_2 = createnode(25);//노드 n6_2 생성 및 값 25에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n7_2 = createnode(50);//노드 n7_2 생성 및 값 50에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n8_2 = createnode(30);//노드 n8_2 생성 및 값 30에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n9_2 = createnode(150);//노드 n9_2 생성 및 값 150에 관한 createnode 함수의 값을 저장한다.
	LCRSnode* n10_2 = createnode(120);//노드 n10_2 생성 및 값 120에 관한 createnode 함수의 값을 저장한다.

	LCRS(root2, n2_2);//부모 노드가 root2이고 자식노드가 n2_2인 LCRS 함수를 실행한다
	LCRS(root2, n3_2);//부모 노드가 root2이고 자식노드가 n3_2인 LCRS 함수를 실행한다
	LCRS(root2, n4_2);//부모 노드가 root2이고 자식노드가 n4_2인 LCRS 함수를 실행한다
	LCRS(root2, n5_2);//부모 노드가 root2이고 자식노드가 n5_2인 LCRS 함수를 실행한다
	LCRS(n3_2, n6_2);//부모 노드가 n3_2이고 자식노드가 n6_2인 LCRS 함수를 실행한다
	LCRS(n3_2, n7_2);//부모 노드가 n3_2이고 자식노드가 n7_2인 LCRS 함수를 실행한다
	LCRS(n3_2, n8_2);//부모 노드가 n3_2이고 자식노드가 n8_2인 LCRS 함수를 실행한다
	LCRS(n5_2, n9_2);//부모 노드가 n5_2이고 자식노드가 n9_2인 LCRS 함수를 실행한다
	LCRS(n8_2, n10_2);//부모 노드가 n8_2이고 자식노드가 n10_2인 LCRS 함수를 실행한다

	print(root2, 0);//root2 및 treelevel 0부터 시작해서 트리를 출력해줄 print 함수를 실행한다

	printf("\n- preorder -\n");//- preorder -를 출력한다
	preorder(root2);//root2부터 전위 운행을 해줄 preorder 함수를 실행한다

	system("pause");//출력창이 꺼지지 않게 유지한다

	return 0;//0을 리턴한다
}
