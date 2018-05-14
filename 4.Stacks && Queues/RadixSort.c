#include <stdio.h>
#include <stdlib.h>
#define MAX_DIM 100
typedef int Item;
#include "queue.h"
//#include <math.h>


void ReadArray(int a[MAX_DIM], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }

}


void PrintArray(int a[MAX_DIM], int n)
{
    int i;
    for(i=0;i<n;i++)
      printf("%d ", a[i]);
    printf("\n");
}

int powTen(int exp)
{
    if( !exp ) return 1;
    int nr = 10;
    int index = 0;
    for(index=1; index<exp; index++)
        nr *= 10;
    return nr;
}

int nrDigits(int a[MAX_DIM], int n)
{
    int sacrifice = 0;
    int index = 0;
    for(index=0; index<n; index++)
        if( a[index] > sacrifice ) sacrifice = a[index];

    index = 0;
    while( sacrifice )
    {
        index++;
        sacrifice /= 10;
    }

    return index;
}

void RadixSort(int a[MAX_DIM], int n)
{
    AQ *radix[10];
    int index = 0;
    for(index=0; index<10; index++)
        radix[index] = InitQueue();

    int digits = nrDigits(a, n);

    for(index=1; index<=digits; index++)
    {
        int index2=0, index3=0;

        for(index2=0; index2<n; index2++)
        {
            int pos = ( a[index2] % powTen(index) ) / powTen(index-1); 
            Enqueue(radix[pos], a[index2]);
        }

        for(index2=0; index2<10; index2++)
        {
            while( !IsEmptyQueue(radix[index2]) )
            {
                a[index3++] = Dequeue(radix[index2]);
            }
        }
    }

    return;
}

int main()
{
    int a[MAX_DIM], n;
    printf("n="); scanf("%d", &n);
    ReadArray(a, n);
    RadixSort(a,n);
    PrintArray(a, n);

    return 0;
}
