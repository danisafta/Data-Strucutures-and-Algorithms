#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>
#include <math.h>

typedef struct MinHeapNode
{
    int  v;
    int d;
} MinHeapNode;


typedef struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    MinHeapNode **elem;
} MinHeap;


MinHeapNode* newNode(int v, int d)
{
	MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));

	node -> v = v;
	node -> d = d;

	return node;
}

MinHeap* newQueue(int capacity)
{
  	MinHeap* H = (MinHeap*) malloc(sizeof(MinHeap));
  	H -> size = 0;
  	H -> capacity = capacity;
  	H -> pos = (int*) calloc(capacity, sizeof(int));
  	H -> elem = (MinHeapNode**) malloc(capacity * sizeof(MinHeapNode*));

  	int i;
  	for(i = 0; i < capacity ; i ++)
  		H -> pos[i] = -1;

  	return H;
}

void swap(MinHeapNode* a, MinHeapNode* b)
{
   
	MinHeapNode aux;
	aux = *a;
	*a = *b;
	*b = aux;

}

void SiftDown(MinHeap* h, int idx)
{
    if(isEmpty(h))
    	return;

    int c = 2 * idx + 1;

    while(c < h -> size ){

    	if(c + 1 < h -> size && h -> elem[c + 1] -> d < h -> elem[c] -> d)
    		c ++;

    	if(h -> elem[idx] -> d > h -> elem[c] -> d){

    		swap(h -> elem[idx], h -> elem[c]);

    		int aux = h -> pos[idx];
			h -> pos[idx] = h -> pos[c];
			h -> pos[c] = aux;


    		idx = c;
    		c = 2 * idx + 1;

    	}else
    		break;

    }
}

int isEmpty(MinHeap* h)
{
    if(h == NULL)
    	return 1;

    if(h -> size == 0)
    	return 1;

    return 0;
}

MinHeapNode* removeMin(MinHeap* h)
{
	h -> pos[h -> elem[0] -> v] = -1;
    swap(h -> elem[0], h -> elem[h -> size - 1]);
    h -> size --;
    SiftDown(h, 0);

    return h -> elem[h -> size];
}

void SiftUp(MinHeap* h, int idx)
{

	int c = idx;
	int p = (c - 1) / 2;

	while(p >= 0 && h -> elem[p] > h -> elem[c]){
		swap(h -> elem[p], h -> elem[c]);

		int aux = h -> pos[p];
		h -> pos[p] = h -> pos[c];
		h -> pos[c] = aux;

		c = p;
		p = (c - 1) / 2;
	}


}

void insert(MinHeap* h, int v, int d){

	MinHeapNode* node = newNode(v, d);
	h -> elem[h -> size] = node;
	h -> pos[v] = h -> size;

	SiftUp(h, h -> size ++);

}

int isInMinHeap(MinHeap *h, int v)
{
	return h -> pos[v] != -1;
  
}

void destroyHeap(MinHeap* h){

	free(h -> pos);
	free(h -> elem);
	free(h);

}

#endif
