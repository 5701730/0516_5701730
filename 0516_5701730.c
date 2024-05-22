#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void print_list(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = NULL;
    int choice, position, data;

    while (1) {
        printf("메뉴 : \n");
        printf("1. 숫자를 위치에 삽입\n");
        printf("2. 위치에서 숫자 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 숫자와 위치를 입력하세요 : ");
            scanf_s("%d %d", &data, &position);

            if (position < 0) {
                printf("유효하지 않은 위치입니다!\n");
                break;
            }

            ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->data = data;

            if (position == 0) {
                newNode->link = head;
                head = newNode;
            }
            else {
                ListNode* p = head;
                int count = 0;
                while (count < position - 1 && p != NULL) {
                    p = p->link;
                    count++;
                }
                if (p == NULL) {
                    printf("위치가 리스트의 길이보다 큽니다\n");
                    break;
                }
                newNode->link = p->link;
                p->link = newNode;
            }
            printf("링크를 따라 이동한 횟수: %d\n", position);
            break;

        case 2:
            printf("삭제할 위치를 입력하세요: ");
            scanf_s("%d", &position);

            if (position < 0) {
                printf("유효하지 않은 위치입니다!\n");
                break;
            }

            if (position == 0 && head != NULL) {
                ListNode* temp = head;
                head = head->link;
                free(temp);
            }
            else {
                ListNode* p = head;
                int count = 0;
                while (count < position - 1 && p != NULL) {
                    p = p->link;
                    count++;
                }
                if (p == NULL || p->link == NULL) {
                    printf("위치가 리스트의 길이보다 큽니다\n");
                    break;
                }
                ListNode* temp = p->link;
                p->link = temp->link;
                free(temp);
            }
            printf("링크를 따라 이동한 횟수: %d\n", position);
            break;

        case 3:
            printf("리스트 출력: ");
            print_list(head);
            break;

        case 0:
            printf("프로그램을 종료합니다.\n");
            exit(0);

        default:
            printf("유효하지 않는 선택입니다!\n");
        }
    }
    return 0;
}
