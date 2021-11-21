#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
};

struct StackPointer {
    struct Node *location;
};

struct Stack {
    int maxHeight;
    int height;
    int size;
    struct StackPointer *pointer;
    struct Node *nodes[];
};

struct Stack* init_stack(struct StackPointer *pointer, int maxHeight) {
    struct Stack *stack = malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Failed to allocate memory for stack!");
        exit(0);
    }
    
    stack->maxHeight = maxHeight;
    stack->size = sizeof(stack);
    stack->height = 0;
    stack->pointer = pointer;
    stack->nodes[stack->maxHeight];
    
    return stack;
}

struct Node* init_node(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    if(!node) {
        printf("Failed to allocate memory for node!");
        exit(0);
    }

    node->data = data;

    return node;
}

struct StackPointer* init_stack_pointer() {
    struct StackPointer *pointer = malloc(sizeof(struct StackPointer));
    if(!pointer) {
        printf("Failed to allocate memory for stack pointer!");
        exit(0);
    }
    
    pointer->location = NULL;
    
    return pointer;
}

int push(struct Stack *stack, int data) {
    struct Node *node = init_node(data);

    stack->pointer->location = node;
    stack->height = stack->height + 1;

    for(int i = 0; i < stack->height; i++) {
        stack->nodes[i + 1] = node;
    }
    return 0;
}

int pop(struct Stack *stack) {
    return 0;
}

void iter_nodes(struct Stack *stack) {
    if(stack->height == 0) {
        printf("Stack has no height!\n");
    } else {
        for(int i = 0; i < stack->height; i++) {
            if(i == stack->maxHeight) {
                break;
            } else {             
                printf("%d\n", stack->nodes[i]->data);
            }
        }
    }
}

int main() {
    printf("== Stack Manager ==\n");
    struct StackPointer *pointer = init_stack_pointer();
    struct Stack *stack = init_stack(pointer, 5);

    printf("Height: %d\n", stack->height); 

    iter_nodes(stack);
    
    int p = push(stack, 20);
    printf("Height: %d\n", stack->height);

    int x = push(stack, 40);
    printf("Height: %d\n", stack->height);

    int z = push(stack, 60);
    printf("Height: %d\n", stack->height);

    iter_nodes(stack);

    free(stack);
    free(pointer);

}