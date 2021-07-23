#include <stdio.h>
#include <stdlib.h>

/*
    get length of linked list   @
    append node to linked list
    insert node in linked list
    ret a node at a specific location   @
    generate nodes
*/

struct Node {
    int data;
    struct Node *next;
};

struct Node *init_node(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int get_length(struct Node *node) {
    int i = 1;
    while(node->next != NULL) {
        i++;
        node = node->next;
    }
    return i;
}

struct Node *get_node(struct Node *node, int location) {
    if(location == 1) {
        return node;
    } else {
        int i = 1;
        while(node->next != NULL) {
            i++;
            node = node->next;
            if(i == location) {
                return node;
            }
        }
    }
    return NULL;
}

struct Node *insert_node(struct Node *node, struct Node *insert, int location) {

}

/* 
    This will generate length number of nodes with simple integer values as data
*/

void iter_nodes(struct Node *node) {
    printf("Start Node: %d\n", node->data);
    while(node->next != NULL) {
        node = node->next;
        printf("Next Node: %d\n", node->data);
    }
}

int main() {
    struct Node *first = init_node(100);
    struct Node *second = init_node(200);
    struct Node *third = init_node(300);

    first->next = second;
    second->next = third;

    iter_nodes(first);

    struct Node *req = get_node(first, 2);
    if(!req) { 
        printf("Requested node does not exist at that location\n");
    } else {
        printf("Requested Node Value: %d\n", req->data);
    }

    int length = get_length(first);
    printf("Length of list: %d\n", length);

    struct Node *fourth = init_node(400);
    third->next = fourth;

    int new_length = get_lenght(first);
    printf("Length of list: %d\n", new_length);

    free(first);
    free(second);
    free(third);
    free(fourth);
}