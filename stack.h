#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"

typedef struct {
	LinkedList list;
}Stack;

void initStack(Stack *s);
void push(Stack *s, int newValue);
int pop(Stack *s);
int top(Stack s);
int is_Empty(Stack *s);
int peek(Stack *s);
void deleteAll(Stack *s);

// Decimal To Biner
void decTobin(int decimal);


#endif

