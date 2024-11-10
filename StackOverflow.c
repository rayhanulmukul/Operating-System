#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

int stack[STACK_SIZE];
int stackPointer = 0;

void push(int value) {
    if (stackPointer < STACK_SIZE) {
        stack[stackPointer++] = value;
    } else {
        printf("Stack overflow detected!\n");
        exit(EXIT_FAILURE);
    }
}

int pop() {
    if (stackPointer > 0) {
        return stack[--stackPointer];
    } else {
        printf("Stack underflow detected!\n");
        exit(EXIT_FAILURE);
    }
}

void recursiveFunction(int depth) {
    push(depth); // Push current depth onto the stack
    if (depth < 10) {
        recursiveFunction(depth + 1); // Call recursively
    }
    pop(); // Pop the depth value when returning from recursion
}

int main() {
    recursiveFunction(0); // Start recursion with depth 0
    printf("No stack overflow detected.\n");
    return 0;
}
