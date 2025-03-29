#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

typedef struct stackMachine {
    int stack[STACK_SIZE];
    int tos;
} sm;

void initStackMachine(sm* obj) {
    obj->tos = -1;
}

void push(sm* obj, int num) {
    if (obj->tos >= STACK_SIZE - 1) {
        printf("stack is full\n");
        exit(1);
    }
    obj->tos++;
    obj->stack[obj->tos] = num;
}

int pop (sm* obj) {
    if (obj->tos == -1) {
        printf("Stack is empty");
        return -1;
    }
    int val = obj->stack[obj->tos];
    obj->tos--;
    return val;
}

void add(sm* obj) {
    push(obj, pop(obj) + pop(obj));
}

int main() {
    sm stackMachine;
    initStackMachine(&stackMachine);

    push(&stackMachine, 1);
    push(&stackMachine, 2);
    add(&stackMachine);

    printf("Result: %d\n", pop(&stackMachine));
    return 0;
}