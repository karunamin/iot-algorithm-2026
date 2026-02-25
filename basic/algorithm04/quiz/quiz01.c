// quiz

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


typedef struct {
	int max;
	int ptr;
	int* stk;
}IntStack;

int Push(IntStack* st, int x) {
	if (st->ptr>=st->max) {
		return -1;
	}
	st->stk[st->ptr] = x;
	st->ptr++;

	return 0;
}
int Pop(IntStack* st, int* x) {
	if (st->ptr <= 0) {
		return -1;
	}
	st->ptr--;
	*x = st->stk[st->ptr];
	return 0;
}


void main(void) {
	char str [100];
	char stack[100];
	
	int i;
	while (1) {
		printf("문자을 입력하세요 : "); scanf("%s", str);

		for (i = 0; i < strlen(str); i++) {
			stack[i] = str[i];
			i;
		}
		while (i >= 0) {
			printf("%c", str[i]);
			i--;
		}
		printf("\n");
	}
	return 0;
}
