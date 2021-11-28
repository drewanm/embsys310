#ifndef __STACK_H__
#define __STACK_H__

void stack_init(void);
int stack_push(int data);
int stack_pop(int* retData);
int stack_is_empty(void);
int stack_is_full(void);

#endif