#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
	int N, v;
	int times = 0;

	scanf("%d", &N);

	printf("\n");

	int* arr = malloc(sizeof(int) * N); // 동적 메모리 할당 입력받은 사이즈 * int 크기만큼 
	// 이 할당받은 메모리 시작 주소를 포인터에 대입

	for (int i = 0; i < N; i++)
	{
		*(arr + i) = i;  // int크기만큼 주소 연산을 하며 동적메모리에 int크기만큼의 값 넣기
	}

	printf("\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d ", *(arr + i));  // 동적 메모리에 저장된 값 출력
	}

	free(arr);



	// N, v는 -100과 100의 범위를 갖는다

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &v);

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == v)
		{
			times++;
		}
	}

	printf("%d", times);

	return 0;
}