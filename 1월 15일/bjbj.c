#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;

	printf("N을 입력하세요.\n");
	scanf("%d", &N);

	printf("N! = %d\n", facto(N));
	return 0;
}

// 몇 번 반복할지 모를 때는 while문

int facto(int N)
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		result *= N;
		N--;
	}
	return result;
}