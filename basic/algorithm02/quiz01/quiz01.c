#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LEN 100
#define DIRECTOR_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char director[DIRECTOR_LEN];
    int year;
} Movie;

// 함수 선언
void addMovie(Movie** list, int* count, int* capacity);
void listMovies(Movie* list, int count);
void searchMovie(Movie* list, int count);
void deleteMovie(Movie** list, int* count);
void menu();

// 화면 관련 유틸
static void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void pause_enter(void) {
    puts("\n계속하려면 Enter...");
    getchar();
}

int main() {
    Movie* movieList = NULL;
    int count = 0;
    int capacity = 0;
    int choice;

    while (1) {
        clear_screen();   // switch문 밖 → 메뉴 전 화면 초기화
        menu();
        printf("선택 > ");
        scanf("%d", &choice);
        getchar();        // 버퍼 정리

        switch (choice) {
        case 1:
            addMovie(&movieList, &count, &capacity);
            break;
        case 2:
            listMovies(movieList, count);
            break;
        case 3:
            searchMovie(movieList, count);
            break;
        case 4:
            deleteMovie(&movieList, &count);
            break;
        case 5:
            free(movieList);
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 입력입니다.\n");
        }

        pause_enter();  // switch문 바깥 → 모든 기능 후 Enter 대기
    }
}

void menu() {
    printf("==== 영화 관리 프로그램 ====\n");
    printf("1. 영화 추가\n");
    printf("2. 영화 목록 출력\n");
    printf("3. 영화 검색\n");
    printf("4. 영화 삭제\n");
    printf("5. 종료\n");
}

void addMovie(Movie** list, int* count, int* capacity) {
    if (*count >= *capacity) {
        *capacity = (*capacity == 0) ? 2 : (*capacity * 2);
        *list = realloc(*list, sizeof(Movie) * (*capacity));
        if (*list == NULL) {
            printf("메모리 할당 실패\n");
            exit(1);
        }
    }

    Movie* m = &((*list)[*count]);

    printf("영화 제목: ");
    fgets(m->title, TITLE_LEN, stdin);
    m->title[strcspn(m->title, "\n")] = 0;

    printf("감독: ");
    fgets(m->director, DIRECTOR_LEN, stdin);
    m->director[strcspn(m->director, "\n")] = 0;

    printf("개봉 연도: ");
    scanf("%d", &m->year);
    getchar();

    (*count)++;
    printf("영화가 추가되었습니다.\n");
}

void listMovies(Movie* list, int count) {
    if (count == 0) {
        printf("등록된 영화가 없습니다.\n");
        return;
    }

    printf("=== 영화 목록 ===\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] 제목: %s | 감독: %s | 연도: %d\n",
            i + 1, list[i].title, list[i].director, list[i].year);
    }
}

void searchMovie(Movie* list, int count) {
    if (count == 0) {
        printf("등록된 영화가 없습니다.\n");
        return;
    }

    char searchTitle[TITLE_LEN];
    printf("검색할 제목: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].title, searchTitle) == 0) {
            printf("찾았습니다!\n");
            printf("제목: %s | 감독: %s | 연도: %d\n",
                list[i].title, list[i].director, list[i].year);
            return;
        }
    }

    printf("해당 영화가 없습니다.\n");
}

void deleteMovie(Movie** list, int* count) {
    if (*count == 0) {
        printf("삭제할 영화가 없습니다.\n");
        return;
    }

    int index;
    printf("삭제할 영화 번호 입력(1~%d): ", *count);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *count) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    index--; // 1번 기준 → 배열 인덱스(0)로 변환

    for (int i = index; i < *count - 1; i++) {
        (*list)[i] = (*list)[i + 1];
    }

    (*count)--;
    printf("삭제되었습니다.\n");
}