//이중 원형 연결리스트 구조 만들기
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
// 이중 연결 리스트의 노드 구조를 구조체로 정의
typedef struct node {
    int num;
    int message;
    char check;
    struct node* prev; // 왼쪽(선행) 노드에 대한 링크
    struct node* next; // 오른쪽(다음) 노드에 대한 링크
} Node;
// 리스트 위치를 나타내는 tail 노드를 구조체로 정의
typedef struct {
    int countIndex;
    Node* tail;
} List;
//---------------------------------------------------


//노드를 생성하고 연결하기(1/2)
void insertNode(List* list, int position, int element)
{
    Node* preNode = list->tail;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->message = element;
    newNode->check = 'C';
    if (list->countIndex == 0)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->tail = newNode;
    }
    //-----------------------------------------------------------

    //노드를 생성하고 연결하기(2/2)
    else
    {
        for (int i = 0; i < position; i++) {
            preNode = preNode->next;
        }
        newNode->next = preNode->next;
        newNode->prev = preNode;
        newNode->next->prev = newNode;
        preNode->next = newNode;
        if (position == list->countIndex) {
            list->tail = newNode;
        }
    }
    list->countIndex++;
    newNode->num = list->countIndex;
}

//-----------------------------------------------------------

//공백 리스트 만들기
List* createList()
{
    List* list;
    // 테일 노드 할당
    list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("ERROR\n");
    }
    else {
        list->tail = NULL;
        list->countIndex = 0;
    }
    return list;
}

//-----------------------------------------------------

//순서대로 출력하기
void printList(List* list)
{
    int i, n;
    Node* node;
    if (list->countIndex == 0) {
        printf("NULL LIST\n");
        return;
    }
    node = list->tail;
    node = node->next;
    n = list->countIndex;
    for (i = 0; i < n; i++)
    {
        printf(" %d, %2d, %c\n",
            node->num, node->message, node->check);
        node = node->next;
    }
}

//--------------------------------------------------------

//역순으로 출력하기
void BackprintList(List* list)
{
    int i, n;
    Node* node;
    if (list->countIndex == 0) {
        printf("NULL LIST\n");
        return;
    }
    node = list->tail;
    n = list->countIndex;
    for (i = 0; i < n; i++)
    {
        printf(" %d, %2d, %c\n", node->num, node->message, node->check);
        node = node->prev;
    }
}
//----------------------------------------------------

//보물상자를 여는 순서를 출력
void findTreasure(List* list)
{
    int step = 0; // 이동할 거리를 저장할 변수
    Node* node = list->tail;
    node = node->next;
    int i = 0;
    printf("보물상자를 연 순서: \n");
    while (list->countIndex > 0) { // 리스트가 빌 때까지 반복

        if (node->message > 0) { // 현재 위치의 메시지가 양수인 경우
            step = node->message % list->countIndex; // 이동 거리 계산

            if (step == 0) {
                step = list->countIndex;
            }


        }

        else { // 현재 위치의 메시지가 음수인 경우
            step = ((node->message) % list->countIndex); // 이동 거리 계산
            if (step == 0) {
                step = (-1) * list->countIndex;
            }



        }
        printf("%d ", node->num); // 보물상자를 여는 순서 출력
        
        int TempNode[10]; // 노드 임시저장

       
        TempNode[i] = node->num;
        i++;
        /*for (int i = 0; i < 10; i++) {
            printf("TempNode[%d]=%d\n", i, TempNode[i]);
        }*/
        list->countIndex--; // 노드 개수 감소


        if (list->countIndex == 0) { // 리스트가 비어있는 경우
            break;
        }
        if (step > 0) { // 정방향으로 이동하는 경우
            
            for (int i = 0; i < step ; i++) { // 정방향으로 이동
                node = node->next;

            }
            for (int i = 0; i < 10; i++) {
                if (TempNode[i] == node->num) {
                    node = node->next;
               }
            }
        }
        else { // 역방향으로 이동하는 경우
           
            for (int i = 0; i < -step ; i++) { // 역방향으로 이동
                node = node->prev;

            }
            for (int i = 0; i < 10; i++) {
                if (TempNode[i] == node->num) {
                    node = node->prev;
                }
            }
        }

      
    }



}








//보물상자의 위치를 나타내는 숫자를 주고 보물상자를 연다.
int main()
{
    int k;
    List* list;
    list = createList();
    k = 2; insertNode(list, 0, k);
    k = -1; insertNode(list, 1, k);
    k = 3; insertNode(list, 2, k);
    k = -2; insertNode(list, 3, k);
    k = 2; insertNode(list, 4, k);
    k = -1; insertNode(list, 5, k);
    printf("(1) 보물상자의 위치를 나타내는 숫자 출력");
    
    printList(list);
    printf("\n(2) 보물상자 여는 순서를 출력");
   
    findTreasure(list);
    return 0;
}