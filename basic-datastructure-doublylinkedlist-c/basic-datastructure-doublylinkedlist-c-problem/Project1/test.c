//���� ���� ���Ḯ��Ʈ ���� �����
#include "stdio.h"
#include "stdlib.h"
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
    List* list = (List*)malloc(sizeof(List));
    // ���� ��� �Ҵ�

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
       
        Node* prevNode = node->prev; // ������ ����� ���� ���
        Node* nextNode = node->next; // ������ ����� ���� ���
        prevNode->next = nextNode; // ��� ���� ����
        nextNode->prev = prevNode;
        free(node); // ��� ����

        list->countIndex--; // ��� ���� ����


           if (list->countIndex == 0) { // ����Ʈ�� ����ִ� ���
                break;
            }
            if (step > 0) { // ���������� �̵��ϴ� ���
                node = nextNode; // ���� ��ġ �̵�
                for (int i = 0; i < step -1 ; i++) { // ���������� �̵�
                    node = node->next;
                    
                }
            }
            else { // ���������� �̵��ϴ� ���
                node = prevNode; // ���� ��ġ �̵�
                for (int i = 0; i < -step -1 ; i++) { // ���������� �̵�
                    node = node->prev;
                   
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
    printf("(1) ���������� ��ġ�� ��Ÿ���� ���� ���\n");
  
    printList(list);
    
    printf("\n(2) �������� ���� ������ ���");
   findTreasure(list);
    
    return 0;
}