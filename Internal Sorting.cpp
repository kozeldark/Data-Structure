// ConsoleApplication96.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RMAX 100 //난수의 최댓값을 100으로 설정한다.

struct array//구조체 array 선언
{
	int data;//데이터 값을 저장해줄 int형 변수 data 선언
};

struct array table1[15][3];//table1을 행15 열3의 크기로 선언한다.
struct array table2[10][3];//table1을 행10 열3의 크기로 선언한다.

void make_table_rand()//테이블에 값에 1~100사이의 랜덤한 값을 넣어줄 함수 make_table_rand
{
	int i, j = 0;

	for (i = 0; i < 15; i++)//table1의 행의 크기만큼 반복
	{
		for (j = 0; j < 3; j++)//table1의 열의 크기만큼 반복
		{
			table1[i][j].data = 1 + (int)rand() % RMAX;//table1[i][j].data에 1~100사이의 랜덤한 값을 넣는다.
		}
	}

	i, j = 0;

	for (i = 0; i < 10; i++)//table2의 행의 크기만큼 반복
	{
		for (j = 0; j < 3; j++)//table2의 열의 크기만큼 반복
		{
			table2[i][j].data = 1 + (int)rand() % RMAX;//table2[i][j].data에 1~100사이의 랜덤한 값을 넣는다.
		}
	}

}

void print1()//table1을 출력해줄 함수 print1
{
	printf("\n\n\n");
	printf("        \nTABLE 1\n        ");
	int i, j = 0;
	for (i = 0; i < 15; i++)//table1의 행의 크기만큼 반복
	{
		printf("|");
		printf("\nㅡㅡㅡㅡㅡㅡㅡㅡ\n");	
		for (j = 0; j < 3; j++)//table1의 열의 크기만큼 반복
		{
			printf("| %d ", table1[i][j].data);//table1[i][j].data 출력
		}
	}
	printf("|");
	printf("\nㅡㅡㅡㅡㅡㅡㅡㅡ\n\n\n");

}



void print2()//table2를 출력해줄 함수 print1
{
	printf("\n\n\n");
	printf("        \nTABLE 2\n        ");
	int i, j = 0;
	for (i = 0; i < 10; i++)//table2의 행의 크기만큼 반복
	{
		printf("|");
		printf("\nㅡㅡㅡㅡㅡㅡㅡㅡ\n");//table2의 열의 크기만큼 반복
		for (j = 0; j < 3; j++)
		{
			printf("| %d ", table2[i][j].data);//table2[i][j].data 출력
		}
	}
	printf("|");
	printf("\nㅡㅡㅡㅡㅡㅡㅡㅡ\n\n\n");
}

void duplex_selection_sort(struct array num[][3], int col, int end)//이중 선택 배열을 해줄 함수 duplex_selection_sort
{
	int left = 0;//좌측 실행 인덱스를 0으로 설정
	int right = end - 1;//우측 실행 인덱스를 n -1로 설정(배열의 크기 - 1이 최대 인덱스 이므로)

	int minimum_index = -1;//최소값 인덱스를 저장해줄 변수 minimum_index를 선언하고 -1로 초기화
	int maximum_index = -1;//최댓값 인덱스를 저장해줄 변수 maximum_index를 선언하고 -1로 초기화

	int min = 101;//최소값을 저장해줄 변수 min을 선언하고 101로 초기화(1~100까지의 랜덤 변수들 이므로 101보다 작은건 없다)
	int max = -1;//최소값을 저장해줄 변수 max를 선언하고 -1로 초기화(1~100까지의 랜덤 변수들 이므로 -1보다 작은건 없다)

	int temp = -1;//임시값을 저장해줄 temp

	while (left < right)//right가 left보다 클 때까지 반복
	{
		for (int i = left; i <= right; i++)//left ~ right번 반복하는 for문
		{
			if (max < num[i][col].data)//만약 num[i][col].data가 max보다 크면
			{
				maximum_index = i;//maximum_index에 i를 저장한다
				max = num[i][col].data;//max에 값에 num[i][col].data를 저장한다.
			}

			if (min > num[i][col].data)//만약 num[i][col].data가 min보다 작으면
			{
				minimum_index = i;//minimum_index에 i를 저장한다
				min = num[i][col].data;//min에 값에 num[i][col].data를 저장한다.
			}

		}

		if (maximum_index == left && minimum_index == right)//만약 maximum_index가 left와 같고 minimum_index가 right와 같으면
		{
			temp = num[right][col].data;
			num[right][col].data = num[maximum_index][col].data;
			num[maximum_index][col].data = temp;
			//num[right][col].data와 num[maximum_index][col].data의 값을 서로 바꿉니다.
		}

		else//아니라면
		{
			temp = num[right][col].data;
			num[right][col].data = num[maximum_index][col].data;
			num[maximum_index][col].data = temp;
			//num[right][col].data와 num[maximum_index][col].data의 값을 서로 바꿉니다.

			temp = num[left][col].data;
			num[left][col].data = num[minimum_index][col].data;
			num[minimum_index][col].data = temp;
			//num[left][col].data와 num[minimum_index][col].data의 값을 서로 바꿉니다.
		}

		min = 101;//최솟값 다시 초기화
		max = -1;//최댓값 다시 초기화

		left++;//좌측 실행 인덱스를 1 더합니다.
		right--;//우측 실행 인덱스를 1 뺍니다.

	}
}
void quick_sort(struct array data[][3], int col, int start, int end)//퀵 배열을 해줄 함수 quick_sort
{
	if (start >= end)//start가 end 이상일 때(부분 리스트들이 더 이상 분할이 불가능할 때) 리턴한다.
		return;

	int pivot = start;//피벗을 start로 설정한다.
	int i = pivot + 1;//좌측 실행 인덱스를 pivot + 1로 설정한다.
	int j = end - 1;//우측 실행 인덱스를 end -1로 설정(배열의 크기 - 1이 최대 인덱스 이므로)
	int temp;//임시값을 저장해줄 temp

	while (i <= j)//j가 i 이상일때까지 반복
	{
		while (i <= end && data[i][col].data <= data[pivot][col].data)
		//좌측 실행 인덱스가 우측 실행 인덱스 이하이며 좌측 실행 인덱스 행의 col 열의 값이 피벗 행의 col 열의 값 이하가 아닐때까지 반복
		{
			i++;//i에 1을 더한다
		}
		while (j > start && data[j][col].data >= data[pivot][col].data)
		//우측 실행 인덱스가 피벗 인덱스 이하이며 우측 실행 인덱스 행의 col 열의 값이 피벗 행의 col 열의 값 이상이 아닐때까지 반복
		{
			j--;//j에 1을 뺀다
		}

		if (i > j)//만약 좌측 실행 인덱스가 우측 실행 인덱스 보다 크면
		{
			temp = data[j][col].data;
			data[j][col].data = data[pivot][col].data;
			data[pivot][col].data = temp;
			//data[j][col].data의 값과 data[pivot][col].data의 깂을 서로 바꾼다.
		}
		else//아니라면
		{
			temp = data[i][col].data;
			data[i][col].data = data[j][col].data;
			data[j][col].data = temp;
			//data[i][col].data의 값과 data[j][col].data의 값을 서로 바꾼다.
		}
	}
	quick_sort(data, col, start, j - 1);//첫 우측 실행 인덱스의 값을 1 줄인 quick_sort 함수 실행
	quick_sort(data, col, j + 1, end);//첫 좌측 실행 인덱스의 값을 1 더한 quick_sort 함수 실행

}
void join(struct array t1[][3], struct array t2[][3], int t1c, int t2c, int val)//두 테이블을 merge join을 해줄 함수 join
{
	struct array merge_table[15][10];//두 테이블을 merge join한 테이블을 저장해줄 merge_table

	int i, j = 0;

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 10; j++)
		{
			merge_table[i][j].data = NULL;//먼저 merge_table을 초기화한다
		}
	}

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 3; j++)
		{
			merge_table[i][j].data = table1[i][j].data;//merge_table에 table1의 값을 복사한다
		}
	}
	int curt2c = t2c;//현재 t2c의 값을 저장해줄 curt2c 선언
	int curcol = 3;//merge 시작 후 mergetable이 저장할 행의 값을 저장해줄 curcol

	i, j = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 10; j++)
		{
			t2c = curt2c;//t2c를 curt2c로 초기화
			curcol = 3;//curcol을 3으로 초기화
			if (t1[i][t1c].data == t2[j][t2c].data && t1[i][t1c].data == val)
			//만약 t1[i][t1c].data의 값과 t2[j][t2c].data의 값과 val의 값이 모두 같다면
			{
				while (t2c != 2)//t2c가 2일때까지 반복
				{ 
					merge_table[i][curcol].data = t2[j][t2c+1].data;//merge_table[i][curcol].data에 t2[j][t2c+1].data의 값을 삽입한다.
					t2c++;//t2c에 1을 더한다.
					curcol++;//curcol에 1을 더한다
				}
			}
		}
	}
	printf("\n\n\n");
	printf("        \nMERGE JOIN TABLE\n        ");

	for (i = 0; i < 15; i++)
	{
		printf("|");
		printf("\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
		for (j = 0; j < 10; j++)
		{
			if(merge_table[i][j].data != NULL)//만약 merge_table[i][j].data가 NULL이 아니면
				printf("| %d ", merge_table[i][j].data);//merge_table[i][j].data 출력
		}
	}
	printf("|");
	printf("\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n\n");
}

int main()//메인 함수
{
	srand(time(NULL));//srand 함수 초기화

	make_table_rand();//make_table_rand 함수 실행

	print1();
	print2();

	printf("Table 1, row 10 & 14 column 3 (change the value to 55) Table 2, row 5, column 1 (change the value to 55)\n");

	
	table1[9][2].data = 55;
	table1[13][2].data = 55;
	table2[4][0].data = 55;
	//문제가 요구한 Table 1, row 10 & 14 column 3 change the value to 55 and Table 2, row 5, column 1 change the value to 55

	print1();
	print2();

	int choice;//사용자의 선택 값을 저장해줄 변수 choice 선언
	printf("1.Dulplex Seletion Sort 2.Quick sort 3.Merge join 4.Remake Random Table 5.quit\n");//메뉴 출력
	scanf("%d", &choice);//사용자가 입력한 값을 choice에 저장

	while (choice != 5)//choice가 5가 되기 전까지 반복하는 while문
	{
		switch (choice)//choice의 값에 대한 switch문
		{
		case 1://choice가 1이면
			printf("\nDulplex Seletion Sort in Table1(on column 3) and Table2(on column 1)\n");

			for (int i = 0; i < 3; i++)
				duplex_selection_sort(table1, 2, 15);

			for (int i = 0; i < 3; i++)
				duplex_selection_sort(table2, 0, 10);

			print1();
			print2();
			choice = 0;
			break;
			//이중 선택 배열을 실행하고 두 테이블을 출력 후 choice의 값을 초기화하고 switch문을 빠져나옴
		case 2://choice가 2이면
			printf("\nQuick sort in Table1(on column 3) and Table2(on column 1)\n");

			for (int i = 0; i < 3; i++)
				quick_sort(table1, 2, 0, 15);

			for (int i = 0; i < 3; i++)
				quick_sort(table2, 0, 0, 10);

			print1();
			print2();
			choice = 0;
			break;
			//퀵 배열을 실행하고 두 테이블을 출력 후 choice의 값을 초기화하고 switch문을 빠져나옴
		case 3://choice가 3이면
			printf("\nMerge join in Table1(on column 3) and Table2(on column 1)\n");
			join(table1, table2, 2, 0, 55);

			choice = 0;
			break;
			//merge join을 실행하고 두 테이블을 출력 후 choice의 값을 초기화하고 switch문을 빠져나옴
		case 4://choice가 4이면
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
			//각 테이블에 다시 1~100까지의 랜덤한 값을 할당하여주고 문제가 요구한 부분의 값을 55로 설정하고 두 테이블을 출력 후 choice의 값을 초기화하고 switch문을 빠져나옴
		default://그 외의 값이라면
			printf("1.Dulplex Seletion Sort 2.Quick sort 3.Merge join 4.Remake Random Table 5.quit\n");//다시 메뉴 출력
			scanf("%d", &choice);
		}
	}
	
    return 0;
}
