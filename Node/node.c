#include <stdio.h>
#include <stdlib.h>

// ��������� ��� �������� ������
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ������� ��� ���������� �������� � ����� ������
void append(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

// ������� ��� �������� �������� �� ������
void delete(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// ������� ��� ������ ������
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// ������� ��� ���������� �������� � ����� ����� � ������
void insertNode( Node** head, int newData, int position) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = newData;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
         Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// ����� �������� ������ �� ��� �������� 
int searchElement(Node* head, int value) {
    Node* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

// ������ �������������
int main() {
    Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 7);
    append(&head, 5);
    insertNode(&head, 6, 6);
    


    printf("Initial list: \n");
    printList(head);
    printf("%d\n", searchElement(head, 7));

    delete(&head, 1);

    printList(head);

    return 0;
}
