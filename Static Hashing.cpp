#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Node//구조체 Node 선언
{
	char key[100];//문자열을 저장해줄 key 선언
	int value;//문자열의 아스키코드 합을 저장해줄 변수 value 선언
	Node * next;
};

Node * hash_table[33]; // 해시 테이블(해당 인덱스에 리스트로 작성)
char keys[33][100]; // 문자열 key들
int values[33]; // key에 대응하는 값들

int current = 0;//삽입할 현재 인덱스의 값을 저장해줄 변수 current 선언 후 0으로 초기화

int hash(const char * key, int value)//해쉬를 해줄 hash 함수
{
	int hash = 0;
	int sum = 0;

	int str_length = strlen(key);//key의 문자열의 길이를 str_length에 저장

	for (int j = 0; j < str_length; j++)//str_length의 길이만큼 반복하는 for문
	{
		sum = sum + key[j];//sum에 sum + key[j]의 값을 저장(아스키 코드의 합을 구하는 과정)
	}
	value = sum;//value에 sum의 값을 저장

	hash = (value % 33);//hash에 value % 33의 값을 저장

	return hash;//hash의 값을 리턴한다.
}
void insert(const char * key, int value)//값 삽입을 실행해 줄 함수 insert
{
	Node * new_node = (Node *)malloc(sizeof(Node));//Node 포인터 new_node 선언 후 malloc으로 Node의 사이즈만큼 메모리 할당
	strcpy(new_node->key, key);//new_node->key에 key의 문자열을 복사한다.
	new_node->value = value;//new_node->value에 value의 값을 대입한다.
	new_node->next = NULL;//new_node->next는 NULL이다.

	int index = hash(key, value);//key와 value 값에 관한 hash 함수 실행 후 hash 함수의 리턴 값을 index에 저장

	if (hash_table[index] == NULL) //만약 hash_table[index]가 NULL이라면
	{
		hash_table[index] = new_node;//hash_table[index]에 new_node를 저장
		printf("[%s] is inserted.\n", key);
	}

	else//아니라면
	{
		Node * cur = hash_table[index];//Node 포인트변수 cur을 선언하고 hash_table[index]를 가리키게 한다.

		while (cur != NULL)//cur가 NULL일때 까지 반복
		{
			if (strcmp(cur->key, key) == 0)//만약 cur->key 문자열이 key 문자열과 같다면
			{
				cur->value = value;//cur->value에 value의 값을 대입
				printf("[%s] is exists.\n", key);
				return;//리턴
			}

			cur = cur->next;//cur에 cur->next의 값을 대입(다음으로 넘어간다)
		}

		//cur->key 문자열이 key 문자열과 같지 않을 때
		new_node->next = hash_table[index];//new_node->next에 hash_table[index]를 저장
		hash_table[index] = new_node;//hash_table[index]에 new_node를 저장
		printf("[%s] is inserted.\n", key);
	}
}


int search(const char * key, int value)//key 값 검색을 해줄 함수 search
{
	int index = hash(key, value);//key와 value 값에 관한 hash 함수 실행 후 hash 함수의 리턴 값을 index에 저장

	Node * cur = hash_table[index];//Node 포인트변수 cur을 선언하고 hash_table[index]를 가리키게 한다.

	while (cur != NULL)//cur이 NULL일 때까지 반복
	{
		if (strcmp(cur->key, key) == 0)//만약 cur->key 문자열이 key 문자열과 같다면
		{
			value = cur->value;//value에 cur->value의 값을 대입
			return 1;//1(true)를 리턴한다
		}
		cur = cur->next;//cur에 cur->next의 값을 대입(다음으로 넘어간다)
	}

	return 0;//0(false)를 리턴한다

}


int del(const char * key, int value) 
{
	int index = hash(key, value);//key와 value 값에 관한 hash 함수 실행 후 hash 함수의 리턴 값을 index에 저장

	if (hash_table[index] == NULL)//만약 hash_table[index]가 NULL이라면
	{
		return 0;//0(false)를 리턴한다
	}

	if (strcmp(hash_table[index]->key, key) == 0)//만약 hash_table[index]->key 문자열이 key 문자열과 같다면
	{
		Node * start = hash_table[index];//Node 포인트변수 start을 선언하고 hash_table[index]를 가리키게 한다.
		hash_table[index] = hash_table[index]->next;//hash_table[index]에 hash_table[index]->next의 값을 대입(다음 값을 덮어씌워버린다)
		free(start);//start에 할당 된 메모리를 해제한다.
		return 1;//1(true)를 리턴한다
	}

	else//아니라면(처음부터 key를 찾은 경우가 아니라면)
	{
		Node * cur = hash_table[index];//Node 포인트변수 cur을 선언하고 hash_table[index]를 가리키게 한다.
		Node * nex = hash_table[index]->next;//Node 포인트변수 nex를 선언하고 hash_table[index]->next를 가리키게 한다.

		while (nex != NULL && strcmp(nex->key, key) != 0)//nex가 NULL이고 nex->key 문자열이 key와 같을 때까지 반복
		{
			cur = nex;//cur에 nex의 값을 대입
			nex = nex->next;//nex에 nex->next의 값을 대입
			//(하나씩 이동)
		}

		if (nex == NULL)//만약 nex가 NULL이면(마지막까지 탐색했으면)
			return 0;//0(false)를 리턴한다

		cur->next = nex->next;//cur->next에 nex->next의 값을 대입
		free(nex);//nex에 할당 된 메모리를 해제한다.
		return 1;//1(true)를 리턴한다
	}
}


void print()//테이블을 출력해줄 print 함수
{
	for (int i = 0; i < 33; ++i)//테이블 크기만큼 반복하는 for문
	{
		if (hash_table[i] != NULL)//만약 hash_table[i]가 NULL이 아니면
		{
			printf("index : %d\n", i);
		}
		else//아니라면
		{
			printf("index : %d (EMPTY)", i);
		}

			Node * cur = hash_table[i];//Node 포인트변수 cur을 선언하고 hash_table[index]를 가리키게 한다.

			while (cur != NULL)//cur이 NULL일 때까지 반복
			{
				printf("( %s , ASCII sum : %d ) ", cur->key, cur->value);
				cur = cur->next;//cur에 cur->next의 값을 대입(다음으로 넘어간다)
			}
			printf("\n");
	}
}
void read_file_data()//keyinput.txt 파일에 있는 문자열들을 읽어와 테이블에 삽입해줄 함수 read_file_data
{
	for (int i = 0; i < 33; ++i)//테이블 크기만큼 반복하는 for문
	{
		Node * cur = hash_table[i];//Node 포인트변수 cur을 선언하고 hash_table[index]를 가리키게 한다.
		Node * temp;//임시 값을 저장해줄 Node 포인트변수 temp

		while (cur != NULL)//cur이 NULL일때까지 반복
		{
			temp = cur;//temp에 cur의 값을 대입
			cur = cur->next;//cur에 cur->next의 값을 대입(다음으로 넘어간다)
			free(temp);//temp에 할당 된 메모리를 해제한다.
		}
		hash_table[i] = NULL;//hash_table[i]에 NULL 값을 삽입한다(초기화)
	}

	FILE *fp = fopen("keyinput.txt", "r");//keyinput.txt를 읽기 전용으로 연다

	if (fp == NULL)//만약 fp가 NULL이면(파일 열기에 실패했으면)
		printf("keyinput.txt file open fail\n\n");
	else//아니라면
		printf("keyinput.txt file open\n\n");

	char ch[100];//keyinput.txt에서 읽어 온 문자열을 저장해줄 ch[100] 선언
	int sum = 0;//문자열의 아스키코드 합을 저장해줄 변소 sum을 선언 후 0으로 초기화

	while (fgets(ch, sizeof(ch), fp) == ch)//fgets 함수가 실행되면 계속 반복
	{
		ch[strlen(ch) - 1] = '\0';//ch의 마지막 인덱스는 NULL값으로 한다(fgets 함수는 마지막 인덱스가 \n일 때 \n도 읽어오기 때문에)

		strcpy(keys[current], ch);//keys[current]에 ch의 문자열을 복사하여 저장한다.

		int str_length = strlen(keys[current]);//keys[current]의 문자열의 길이를 str_length에 저장

		for (int j = 0; j < str_length; j++)//str_length의 길이만큼 반복하는 for문
		{
			sum = sum + keys[current][j];//sum에 sum + keys[current][j]의 값을 저장(아스키 코드의 합을 구하는 과정)
		}
		values[current] = sum;//values[current]에 sum의 값을 저장
		insert(keys[current], values[current]);//keys[current], values[current] 값에 대한 insert 함수 실행

		current++;//current에 1을 더한다.
		sum = 0;//sum을 0으로 초기화한다.
	}
}
int main()//메인 함수
{
	read_file_data();

	print();

	int choice;//사용자의 선택 값을 저장해줄 변수 choice 선언
	printf("1.insert 2.delete 3.search 4.print 5.quit\n");//메뉴 출력
	scanf("%d", &choice);//사용자가 입력한 값을 choice에 저장

	int sum = 0;//새로 삽입할 문자열의 아스키코드 합을 저장해줄 변수 sum를 선언
	int str_length;//새로 삽입할 문자열의 길이의 값을 저장해줄 변수 str_length를 선언

	while (choice != 5)//choice가 5가 되기 전까지 반복하는 while문
	{
		switch (choice)//choice의 값에 대한 switch문
		{
		case 1://choice가 1이면
			printf("What want insert key?\n");
			scanf("%s",&keys[current]);//사용자가 입력한 문자열을 스캔하여 keys[current]에 저장
			str_length = strlen(keys[current]);//keys[current]의 문자열의 길이를 str_length에 저장

			for (int j = 0; j < str_length; j++)//str_length의 길이만큼 반복하는 for문
			{
				sum = sum + keys[current][j];//sum에 sum + keys[current][j]의 값을 저장(아스키 코드의 합을 구하는 과정)
			}
			values[current] = sum;//values[current]에 sum의 값을 저장
			insert(keys[current], values[current]);//keys[current], values[current] 값에 대한 insert 함수 실행


			current++;//current에 1을 더한다.
			sum = 0;//sum을 0으로 초기화한다.

			choice = 0;
			break;
			//choice의 값을 초기화하고 switch문을 빠져나옴
		case 2://choice가 2이면
			char delkey[100];//사용자가 삭제하기 원하는 문자열을 저장할 delkey 선언
			printf("What want delete key?\n");
			scanf("%s", &delkey);//사용자가 입력한 문자열을 스캔하여 delkey에 저장
			if (del(delkey,0))//만약 del(delkey,0)가 true이면
			{
				printf("Delete [%s] in hash table.\n", delkey);
			}
			else//아니라면
			{
				printf("Can't delete [%s] in hash table...\n", delkey);
			}

			choice = 0;
			break;
			//choice의 값을 초기화하고 switch문을 빠져나옴
		case 3://choice가 3이면
			char sh[100];//사용자가 검색하기 원하는 문자열을 저장할 sh 선언
			printf("What want search key?\n");
			scanf("%s", &sh);//사용자가 입력한 문자열을 스캔하여 sh에 저장

			if (search(sh, 0))//만약 search(sh,0)가 true이면
			{
				printf("Found [%s] in hash table.\n", sh);
			}
			else
			{
				printf("Can't found [%s] in hash table...\n", sh);
			}
			choice = 0;
			break;
			//choice의 값을 초기화하고 switch문을 빠져나옴
		case 4://choice가 4이면
			print();

			choice = 0;
			break;
			//print함수 실행 후 choice의 값을 초기화하고 switch문을 빠져나옴
		default:
			printf("1.insert 2.delete 3.search 4.print 5.quit\n");
			scanf("%d", &choice);
		}
	}

	return 0;
}