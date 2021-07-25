#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *head;
    struct Node *previous;
    struct Node *next;
};

struct Node *init_node(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    
    node->head = NULL;
    node->previous = NULL;
    node->next = NULL;
    return node;
}

void iter_nodes(struct Node *node) {
    node = node->head;
    printf("Head: %d\n", node->data);
    while(node->next != NULL) {
        node = node->next;
        printf("Next: %d\n", node->data);
    }
}

int main() {
    struct Node *first = init_node(100);
    struct Node *second = init_node(200);
    struct Node *third = init_node(300);

    first->next = second;
    first->head = first;

    second->next = third;
    second->previous = first;
    second->head = first;

    third->previous = second;
    third->head = first;

    iter_nodes(first);

    free(first);
    free(second);
    free(third);
}