#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *previous;
    struct Node *next;
};

struct Node *init_node(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->previous = NULL;
    node->next = NULL;
    return node;
}

void iter_nodes(struct Node *node) {
    
}

int main() {
    struct Node *first = init_node(100);
    struct Node *second = init_node(200);
    struct Node *third = init_node(300);

    first->next = second;
    second->next = third;
    second->previous = first;
    third->previous = second;

    free(first);
    free(second);
    free(third);
}