#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
	int N, v;
	int times = 0;

	scanf("%d", &N);

	printf("\n");

	int* arr = malloc(sizeof(int) * N); // ���� �޸� �Ҵ� �Է¹��� ������ * int ũ�⸸ŭ 
	// �� �Ҵ���� �޸� ���� �ּҸ� �����Ϳ� ����

	for (int i = 0; i < N; i++)
	{
		*(arr + i) = i;  // intũ�⸸ŭ �ּ� ������ �ϸ� �����޸𸮿� intũ�⸸ŭ�� �� �ֱ�
	}

	printf("\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d ", *(arr + i));  // ���� �޸𸮿� ����� �� ���
	}

	free(arr);



	// N, v�� -100�� 100�� ������ ���´�

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