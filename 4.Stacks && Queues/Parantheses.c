#include <stdlib.h>
#include <string.h>
typedef char Item;
#include "stack.h"

int isBalanced(char s[100])
{
    unsigned int index = 0;
   	int U_u = 0;
    
    for(index=0; index<strlen(s); index++)
    {
	    if( s[index] == 40 ) U_u++;         //char(40) = '('
        else if( s[index] == 41 ) U_u--;    //char(41) = ')'

        if( U_u < 0 ) return 0;
    }
    
    if( !U_u ) return 1;
    else return 0;
}

int isBalancedWithStack(char s[100])
{
    unsigned int index = 0;
    int U_u = 0;

    TStack inefficientStack = InitStack();
    for(index=0; index<strlen(s); index++)
    {
    	if( s[index] == 40 )		//char(40) = '('
    		inefficientStack = Push(inefficientStack, (int)(s[index]));
    	else if( s[index] == 41 )	//char(41) = ')'
    	{
    		if( IsEmptyStack(inefficientStack) == 1 ) return 0;
    		inefficientStack = Pop(inefficientStack, &U_u);
    	}
    }

    if( IsEmptyStack(inefficientStack) ) return 1;
    else return 0;

    // while( inefficientStack )
    // {
    //     int paranthese;
    //     inefficientStack = Pop(inefficientStack, &paranthese);
    //     if( paranthese == 40 ) U_u--;
    //     else if( paranthese == 41 ) U_u++;
    //     //printf("%c -> %d", s[index], U_u);
        
    //     if( U_u < 0 ) return 0;
    // }
    
    // if( !U_u ) return 1;
    // else return 0;
}

int main()
{
    char s1[100]="((())))", s2[100]="((())())";

    if(isBalancedWithStack(s1))
      printf("Balanced | ");
    else
      printf("Not balanced | ");

    if(isBalancedWithStack(s2))
      printf("Balanced | ");
    else
      printf("Not balanced | ");
    printf("\n");
    return 0;
}
