#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE* next;
	int data;
}NODE;

void appendFirst(NODE* list, int newData) {      //지정한 노드 뒤에 새로운 노드 추가
	NODE* newNode = malloc(sizeof(NODE));
	newNode->data = newData;
	newNode->next = list->next;
	list->next = newNode;
}

void deleteList(NODE* list) {					// 지정한 노드 다음 노드 삭제
	NODE* delete = list->next;
	list->next = delete->next;
	free(delete);
}

void insertSort(NODE* list, int newData) {     //정렬된 리스트에 새로운 노드 추가
	NODE* newList = malloc(sizeof(NODE));			//이때 list는 head로 해주기
	newList->data = newData;
	NODE* cur = list;
	
	while (cur->next != NULL) {
		if (cur->next->data > newList->data)    // 내림차순  
			break;
		cur = cur->next;
	}
	newList->next = cur->next;
	cur->next = newList;
}

int main() {
	NODE* head = malloc(sizeof(NODE));
	head->next = NULL;
	appendFirst(head, 30);
	appendFirst(head, 20);
	appendFirst(head, 10);
	insertSort(head, 22);
	struct NODE* cur = head->next;    // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (cur != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
	{
		printf("%d\n", cur->data);    // 현재 노드의 데이터 출력
		cur = cur->next;             // 포인터에 다음 노드의 주소 저장
	}

	cur = head->next;      // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (cur != NULL)    // 포인터가 NULL이 아닐 때 계속 반복
	{
		struct NODE* next = cur->next;    // 현재 노드의 다음 노드 주소를 임시로 저장
		free(cur);                        // 현재 노드 메모리 해제
		cur = next;                       // 포인터에 다음 노드의 주소 저장
	}

	free(head);    // 머리 노드 메모리 해제

	return 0;
}