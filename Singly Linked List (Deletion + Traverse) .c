#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void delete_from_beginning() {
    if (head == NULL) return;

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void delete_from_end() {
    if (head == NULL) return;

    struct Node* temp = head;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete node with given data
void delete_node(int data) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}