#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

struct DoublyNode* head2 = NULL;

void insert_begin_dll(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head2;

    if (head2 != NULL)
        head2->prev = newNode;

    head2 = newNode;
}

void insert_end_dll(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->next = NULL;

    if (head2 == NULL) {
        newNode->prev = NULL;
        head2 = newNode;
        return;
    }

    struct DoublyNode* temp = head2;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insert_after_key_dll(int key, int data) {
    struct DoublyNode* temp = head2;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) return;

    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void traverse_forward() {
    struct DoublyNode* temp = head2;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}