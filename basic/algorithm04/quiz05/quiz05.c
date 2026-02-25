// quiz05 


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int num;
	int high = 0;
	printf("학생수를 입력하세요 : "); scanf("%d", &num);

	int* x = calloc(num, sizeof(int));
	char(*name)[21] = calloc(num, sizeof(*name));

	if (name == NULL || x == NULL) {
		printf("메모리 부여 실패!");
		return -1;
	}

	for (int i = 0; i < num; i++) {
		printf("학생의 이름과 점수를 입력하세요 : ");
		scanf("%20s %d", name[i], &x[i]);
	}

	for (int i = 0; i < num; i++) {
		if (x[i] > x[high]) {
			high = i;
		}
	}

	printf("최고 점수 학생 : %s 점수 : %d", name[high], x[high]);
	
	free(name);
	free(x);
	return 0;
}
