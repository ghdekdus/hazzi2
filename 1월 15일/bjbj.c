#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;

	printf("N�� �Է��ϼ���.\n");
	scanf("%d", &N);

	printf("N! = %d\n", facto(N));
	return 0;
}

// �� �� �ݺ����� �� ���� while��

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