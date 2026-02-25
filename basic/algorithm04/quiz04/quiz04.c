// quiz04 이게 아닌데~

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_name(char a[], char b[]) {
	char temp[21];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void sort(char name[][21], int x[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (x[j - 1] < x[j]) {
				swap(&x[j - 1], &x[j]);
				swap_name(name[j - 1], name[j]);
			}
		}
	}

}
int main(void) {
	int num;
	printf("학생수를 입력하세요 : "); scanf("%d", &num);

	int* x = calloc(num, sizeof(int));
	char(* name)[21] = calloc(num, sizeof(*name));

	if (name == NULL || x == NULL) {
		printf("메모리 부여 실패!");
		return -1;
	}

	for (int i = 0; i < num; i++) {
		printf("학생의 이름과 점수를 입력하세요 : ");
		scanf("%20s %d", name[i],&x[i]);
	}
	
	sort(name, x, num);

	puts("정렬 완료!");
	for (int i = 0; i < num; i++) {
		printf("%d등 =%s %d\n", i+1,name[i], x[i]);
	}

	free(name);
	free(x);

	return 0;
}
