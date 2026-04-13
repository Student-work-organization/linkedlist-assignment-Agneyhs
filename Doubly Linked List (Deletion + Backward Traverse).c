#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
};
  
void delete_dll(int data) {
    struct DoublyNode* temp = head2;

    while (temp != NULL && temp->data != data)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head2 = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Traverse backward
void traverse_backward() {
    struct DoublyNode* temp = head2;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}