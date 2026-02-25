// quiz02

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int card;

	printf("숫자를 입력하세요 : "); scanf("%d", &card);

	int first = 0, last = card;
	int* list = (int*)malloc(sizeof(int) * card * 2);

	for (int i = 0; i < card; i++) {
		list[i] = i + 1;
	}

	while (last - first > 1 ) {
		first++;
		list[last++] = list[first++];
	}
	printf("%d", list[first]);

	free(list);
	return 0;
}