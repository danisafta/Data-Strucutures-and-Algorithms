#ifndef STACK_H_D
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    Item elem;
    struct cel* next;
}StackCel, *TStack;


TStack InitStack()
{
	TStack st = NULL;
	return st;
}

int IsEmptyStack (TStack s)
{
    if( !s ) return 1;
    else return 0;
}

TStack Push(TStack s, Item el)
{
    TStack plate = (TStack)malloc(sizeof(StackCel));
    if( !plate ) return s;
    plate->elem = el;
    if( IsEmptyStack(s) ) plate->next = NULL;
    else plate->next = s;
    
    return plate;
}


TStack Pop(TStack s,Item *el)
{
    TStack plate = s;
    *el = s->elem;
    free(s);
    return plate->next;
}

Item Top (TStack s)
{
	return s->elem;	
}

void PrintStack(TStack s)
{
   TStack plate = s;

   while( plate )
   {
   		printf("%d ", plate->elem);
   		plate = plate->next;
   }
   return;

}

#endif // LINKEDSTACK_H_INCLUDED
