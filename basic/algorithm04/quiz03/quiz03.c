// quiz03

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Plus(int x) {
	int result = 0;
	if (x > 0) {
		result = x + Plus(x - 1);
	}
	return result;
}

void main(void) {

		int x;

		printf("정수를 입력하세요 : "); scanf("%d", &x);
		printf("%d\n", Plus(x));

		return 0;
}