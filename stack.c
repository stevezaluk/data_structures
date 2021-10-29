#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
};

struct Stack {
    int maxHeight;
    int height;
    struct Node *stack_pointer;
    struct Node *nodes;
};

struct Node *init_node(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    
    node->data = data;
    
    return node;
}

struct Stack *init_stack() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    
    stack->maxHeight = 20; // default maxHeight
    stack->height = 0;
    stack->stack_pointer = 0;
    
    struct Node *nodes[stack->maxHeight];
    
    stack->nodes = nodes;
    
    return stack;
}

int iter(struct Stack *stack) {
    for(int i = 0; i < stack->height; i++) {
        struct Node *node = stack->nodes[i];
        printf("%d", node->data);
    }
    return 0;
}

void push(struct Stack *stack, int data) {
    for(int i = 0; i < stack->height; i++) {
        struct Node *node = stack->nodes[i];
    }
    stack->height++;
}

void push_node(struct Stack *stack, struct Node *node) {
    for(int i = 0; i < stack->height; i++) {
        struct Node *node = (stack->nodes + i);
        if(i == stack->height) {
            
        }
    }
    stack->height++;
}

void pop() {

}

int main() {
    struct Stack *stack = init_stack();

    struct Node *one = init_node(1);
    struct Node *two = init_node(2);

    push_node(stack, one);
    push_node(stack, two);

    int count = iter(stack);
    printf("%d", count);
    return 0;
}