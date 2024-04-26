#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cann't be NULL");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct Node **head_ref, int new_data)
{
    struct Node *new_Node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    // for head node only
    new_Node->data = new_data;
    new_Node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_Node;
        return;
    }

    // Traverse the node
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_Node;
    return;
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);

    *head_ref = new_node;
}

bool search(struct Node *head_ref, int data)
{
    struct Node *current = head_ref;
    while (current != NULL)
    {
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}

int getCount(struct Node *head)
{
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    append(&head, 7);
    append(&head, 0);
    // Push at the first of the linked list
    push(&head, 25);
    push(&head, 14);
    append(&head, 86);
    append(&head, 62);
    append(&head, 106);
    insertAfter(head->next, 8);

    printList(head);
    search(head, 99) ? printf("yes") : printf("No");
    printf("\n%d Nodes is present in Linked list", getCount(head));

    return 0;
}
