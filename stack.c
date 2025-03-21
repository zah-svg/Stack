#include "stack.h"

void initStack(Stack *s){
	createList(&s->list);
}

void push(Stack *s, int newValue){
	insertAtFirst(&s->list, newValue);
}

int pop(Stack *s){
	if(is_Empty(s)){
		printf("Stack Kosong");
		return -1;
	}
	int newValue = s->list.first->info;
	deleteAtFirst(&s->list);
	return newValue;
}

int top(Stack s){
	if(!is_Empty(s)){
		return s->list.first->info;
	}
	printf("Stack KOsong");
	return -1;
}

int is_Empty(Stack *s){
	return isEmpty(&s->list);
}

int peek(Stack *s){
	if(is_Empty(s)){
		printf("Stack Kosong :)");
		return -1;
	}
	return s->list.first->info;
}

void deleteAll(Stack *s){
	while(!is_Empty(s)){
		deleteAtFirst(&s->list);
	}
	printf("Stack telah dikosongkan -_-");
}

// Decimal To Biner
void decTobin(int decimal){
    Stack s;
    initStack(&s);

    // Proses konversi: bagi dengan 2 dan simpan sisa bagi ke stack
    while (decimal > 0) {
        push(&s, decimal % 2);
        decimal /= 2;
    }

    // Cetak hasil dengan mengambil nilai dari stack (pop)
    printf("Biner: ");
    while (!is_Empty(&s)) {
        printf("%d", top(&s));
        pop(&s);
    }
    printf("\n");
}
