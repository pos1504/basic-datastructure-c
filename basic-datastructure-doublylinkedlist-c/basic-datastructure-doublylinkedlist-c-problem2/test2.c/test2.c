//���� ���� ���Ḯ��Ʈ ���� �����
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
// ���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct node {
    int num;
    int message;
    char check;
    struct node* prev; // ����(����) ��忡 ���� ��ũ
    struct node* next; // ������(����) ��忡 ���� ��ũ
} Node;
// ����Ʈ ��ġ�� ��Ÿ���� tail ��带 ����ü�� ����
typedef struct {
    int countIndex;
    Node* tail;
} List;
//---------------------------------------------------


//��带 �����ϰ� �����ϱ�(1/2)
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

    //��带 �����ϰ� �����ϱ�(2/2)
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

//���� ����Ʈ �����
List* createList()
{
    List* list;
    // ���� ��� �Ҵ�
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

//������� ����ϱ�
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

//�������� ����ϱ�
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

//�������ڸ� ���� ������ ���
void findTreasure(List* list)
{
    int step = 0; // �̵��� �Ÿ��� ������ ����
    Node* node = list->tail;
    node = node->next;
    int i = 0;
    printf("�������ڸ� �� ����: \n");
    while (list->countIndex > 0) { // ����Ʈ�� �� ������ �ݺ�

        if (node->message > 0) { // ���� ��ġ�� �޽����� ����� ���
            step = node->message % list->countIndex; // �̵� �Ÿ� ���

            if (step == 0) {
                step = list->countIndex;
            }


        }

        else { // ���� ��ġ�� �޽����� ������ ���
            step = ((node->message) % list->countIndex); // �̵� �Ÿ� ���
            if (step == 0) {
                step = (-1) * list->countIndex;
            }



        }
        printf("%d ", node->num); // �������ڸ� ���� ���� ���
        
        int TempNode[10]; // ��� �ӽ�����

       
        TempNode[i] = node->num;
        i++;
        /*for (int i = 0; i < 10; i++) {
            printf("TempNode[%d]=%d\n", i, TempNode[i]);
        }*/
        list->countIndex--; // ��� ���� ����


        if (list->countIndex == 0) { // ����Ʈ�� ����ִ� ���
            break;
        }
        if (step > 0) { // ���������� �̵��ϴ� ���
            
            for (int i = 0; i < step ; i++) { // ���������� �̵�
                node = node->next;

            }
            for (int i = 0; i < 10; i++) {
                if (TempNode[i] == node->num) {
                    node = node->next;
               }
            }
        }
        else { // ���������� �̵��ϴ� ���
           
            for (int i = 0; i < -step ; i++) { // ���������� �̵�
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








//���������� ��ġ�� ��Ÿ���� ���ڸ� �ְ� �������ڸ� ����.
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
    printf("(1) ���������� ��ġ�� ��Ÿ���� ���� ���");
    
    printList(list);
    printf("\n(2) �������� ���� ������ ���");
   
    findTreasure(list);
    return 0;
}