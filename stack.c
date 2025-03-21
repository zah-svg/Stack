#include "stack.h"
#include <stdio.h>
#include "boolean.h"

void initStack(Stack *s){
    createList(&s->list);
}

void push(Stack *s, int newValue){
    insertAtFirst(&s->list, newValue);
}

int pop(Stack *s){
    if(is_Empty(s)){
        printf("Stack Kosong\n");
        return -1;
    }
    int newValue = s->list.first->info;
    deleteAtFirst(&s->list);
    return newValue;
}

int top(Stack *s){  
    if (!is_Empty(s)){
        return s->list.first->info;
    }
    printf("Stack Kosong\n");
    return -1;
}

boolean is_Empty(Stack *s){ 
    return (s->list.first == NULL);
}

int peek(Stack *s){
    if(is_Empty(s)){
        printf("Stack Kosong :)\n");
        return -1;
    }
    return s->list.first->info;
}

void deleteAll(Stack *s){
    while(!is_Empty(s)){
        deleteAtFirst(&s->list);
    }
    printf("Stack telah dikosongkan -_-\n");
}

// Decimal To Biner
void decTobin(int decimal){
    Stack s;
    initStack(&s);

    if (decimal == 0) {
        printf("0\n");
        return;
    }

    // Proses konversi
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&s, remainder);
        decimal /= 2;
    }

    // Cetak hasil konversi biner
    printf("Biner: ");
    while (!is_Empty(&s)) {
        printf("%d", pop(&s)); 
    }
    printf("\n");
}

