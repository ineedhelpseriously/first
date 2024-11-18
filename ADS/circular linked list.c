#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode;
        *head = newNode;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        *head = newNode;
    } else {
        newNode->next = newNode;
        *head = newNode;
    }
}

void insertAtMiddle(struct Node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;

    for (int i = 0; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } else {
        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        free(*head);
        *head = NULL;
    } else {
        prev->next = *head;
        free(temp);
    }
}

void deleteAtMiddle(struct Node** head, int position) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    for (int i = 0; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head) {
        deleteAtEnd(head);
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

int peek(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    return head->data;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Circular Linked List: ");
    display(head);

    insertAtBeginning(&head, 5);
    printf("After inserting 5 at the beginning: ");
    display(head);

    insertAtMiddle(&head, 25, 3);
    printf("After inserting 25 at position 3: ");
    display(head);

    deleteAtBeginning(&head);
    printf("After deleting at the beginning: ");
    display(head);

    deleteAtEnd(&head);
    printf("After deleting at the end: ");
    display(head);

    deleteAtMiddle(&head, 2);
    printf("After deleting at position 2: ");
    display(head);

    printf("Peek: %d\n", peek(head));

    return 0;
}