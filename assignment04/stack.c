#include "stack.h"
#define STACK_SIZE 3

int stack[STACK_SIZE];

// pointers to stack elements for pushing/popping
int* topPtr;
int* botPtr;

// stack is empty if topPtr == botPtr
// stack is full if topPtr >= botPtr + STACK_SIZE

// stack initializing function
void stack_init(void)
{
    // init Ptrs
    topPtr = stack;
    botPtr = stack;
    
    // fill with 0s
    for (int i = 0; i < STACK_SIZE; i++)
    {
        *topPtr = 0;
        *topPtr++;
    }
    
    // reset topPtr
    topPtr = botPtr;
}

// stack pushing element function
// returns 0 on success, -1 on error
int stack_push(int data)
{
    // if full, return error
    if (stack_is_full() == 1)
    {
        return -1;
    }
    
    // push element onto the stack
    *topPtr = data;
    topPtr++;
    return 0;
}

// stack popping element function
// returns 0 on success, -1 on error
int stack_pop(int* retData)
{
    // if empty, return error
    if (stack_is_empty() == 1)
    {
        return -1;
    }

    // pop element from stack
    topPtr--;
    *retData = *topPtr;
    return 0;
}

// stack check if empty function
int stack_is_empty(void)
{
    if (topPtr == botPtr)
    {
        return 1;
    }
    return 0;
}

// stack check if full function
int stack_is_full(void)
{
    if (topPtr >= botPtr + STACK_SIZE)
    {
        return 1;
    }
    return 0;
}