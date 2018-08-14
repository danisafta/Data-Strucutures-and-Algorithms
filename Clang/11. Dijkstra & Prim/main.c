
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

typedef int TCost;

typedef struct node
{
	int v;
	TCost c;
	struct node *next;
} TNode, *ATNode;


typedef struct
{
	int nn;
	ATNode *adl;
}	TGraphL;


void alloc_list(TGraphL * G, int n)
{
    int i;
    G->nn = n;
	G->adl = (ATNode*) malloc((n+1)*sizeof(ATNode));
	for(i = 0; i < n; i++)
		G->adl[i] = NULL;

}

void free_list(TGraphL *G)
{
    int i;
    ATNode it;
    for(i = 1; i < G->nn; i++){
		it = G->adl[i];
		while(it != NULL){
			ATNode aux = it;
			it = it->next;
			free(aux);
		}
		G->adl[i] = NULL;
	}
	G->nn = 0;
}

void insert_edge_list(TGraphL *G, int v1, int v2, int c)
{
 TNode *t;
 t=(ATNode)malloc(sizeof(TNode));
 t->v = v2; t->c=c; t->next = G->adl[v1]; G->adl[v1]=t;
 t=(ATNode)malloc(sizeof(TNode));
 t->v = v1;  t->c=c; t->next = G->adl[v2]; G->adl[v2]=t;
}


void dijkstra(TGraphL *G, int s)
{

	int *D = (int*) calloc(G -> nn, sizeof(int));
	MinHeap* H = newQueue(G -> nn);
	insert(H, s, 0);

	int i;

	for(i = 0; i < G -> nn ; i ++)
		D[i] = 10000000;

	D[s] = 0;


	while(!isEmpty(H)){

		MinHeapNode* node = removeMin(H);

		ATNode it = G -> adl[node -> v];

		while(it != NULL){
			if(D[it -> v] > node -> d + it -> c){
				D[it -> v] = node -> d + it -> c;
				if(isInMinHeap(H, it -> v)){
					H -> elem[H -> pos[it -> v]] -> d = D[it -> v];
					SiftUp(H, H -> pos[it -> v]);
				}else
					insert(H, it -> v, D[it -> v]);
			}

			it = it -> next;
		}

	}

	for(i = 0; i < G -> nn; i ++)
		printf("%d\n", D[i]);

    free(D);
    destroyHeap(H);

}

void PrimHelper(TGraphL *G, MinHeap* H, int **D, int **P, int x){

	TNode* it = G -> adl[x];

	while(it != NULL){

		if((*D)[it -> v] > it -> c){
			(*D)[it -> v] = it -> c;
			(*P)[it -> v] = x;
		}

		it = it -> next;

	}

}

void swapint(int *a, int *b){

	int aux = *a;
	*a = *b;
	*b = aux;

}

void Prim(TGraphL *G)
{
	int *D = (int*) calloc(G -> nn, sizeof(int));
	int *P = (int*) calloc(G -> nn, sizeof(int));
	
	MinHeap* H = newQueue(G -> nn);

	int i, cost = 0;

	for(i = 1; i < G -> nn ; i ++)
		D[i] = 10000000;

	PrimHelper(G, H,  &D, &P, 0);

	for(i = 1 ;i < G -> nn; i ++)
		insert(H, i, D[i]);

	while(!isEmpty(H)){

		MinHeapNode* node = removeMin(H);
		cost += D[node -> v];
		PrimHelper(G, H,  &D, &P, node -> v);

		TNode* it = G -> adl[node -> v];

		while(it != NULL){

			if(isInMinHeap(H, it -> v)){
				H -> elem[H -> pos[it -> v]] -> d = D[it -> v];
				SiftUp(H, H -> pos[it -> v]);
			}

			it = it -> next;

		} 

	}


	for(i = 1; i < G -> nn; i ++)
		printf("%d %d \n", P[i], i);

	printf("%d\n", cost);

	destroyHeap(H);
	free(D);
	free(P);

}


int main()
{
    int i,v1,v2,c;
	int V,E;
	TGraphL G;
	ATNode t;
	freopen ("graph.in", "r", stdin);
	scanf ("%d %d", &V, &E);
	alloc_list(&G, V);

	for (i=1; i<=E; i++)
	{
		scanf("%d %d %d", &v1, &v2, &c);
	    insert_edge_list(&G, v1,v2, c);
	}

	for(i=0;i<G.nn;i++)
	{
    printf("%d : ", i);
    for(t = G.adl[i]; t != NULL; t = t->next)
    printf("%d ",t->v);
    printf("\n");
	}
	//dijkstra(&G,0);
	Prim(&G);

	return 0;
}
