#include <stdio.h>
#include <stdlib.h>

struct CircularNode {
    int data;
    struct CircularNode* next;
};

struct CircularLinkedList {
    struct CircularNode* last;
};

void insert_at_end(struct CircularLinkedList* list, int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;

    if (list->last == NULL) {
        list->last = newNode;
        newNode->next = newNode;
        return;
    }

    newNode->next = list->last->next;
    list->last->next = newNode;
    list->last = newNode;
}

void delete_node(struct CircularLinkedList* list, int data) {
    if (list->last == NULL) return;

    struct CircularNode *curr = list->last->next, *prev = list->last;

    do {
        if (curr->data == data) {

            if (curr == list->last && curr->next == list->last) {
                free(curr);
                list->last = NULL;
                return;
            }

            prev->next = curr->next;

            // If deleting last node
            if (curr == list->last)
                list->last = prev;

            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != list->last->next);
}

void traverse(struct CircularLinkedList* list) {
    if (list->last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode* temp = list->last->next;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->last->next);

    printf("(back to start)\n");
}

int main() {
    struct CircularLinkedList list;
    list.last = NULL;

    insert_at_end(&list, 10);
    insert_at_end(&list, 20);
    insert_at_end(&list, 30);

    printf("Circular Linked List:\n");
    traverse(&list);

    printf("After deleting 20:\n");
    delete_node(&list, 20);
    traverse(&list);

    return 0;
}