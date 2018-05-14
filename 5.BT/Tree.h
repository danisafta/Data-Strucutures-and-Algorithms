#ifndef TREE_H_D
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct node
  {
    Item  elem;
    struct node *lt;
    struct node *rt;
  } TreeNode, *TTree;


void Init(TTree *t, Item x)
{
  *t = (TTree)malloc(sizeof(TreeNode));
  (*t)->elem = x;
  (*t)->lt = NULL;
  (*t)->rt = NULL;
}

void Insert(TTree *t, Item x)
{
  if((*t) == NULL)
  {
    Init(t,x);
  }
  else
  {
    if(x < (*t)->elem)
      Insert(&(*t)->lt, x);
    else
      Insert(&(*t)->rt, x);
  }
}

void PrintPostorder(TTree t)
{
  if(t == NULL)
    return;
  PrintPostorder(t->lt);
  PrintPostorder(t->rt);
  printf("%d  ", t->elem);


}

void PrintPreorder(TTree t)
{
   if(t == NULL)
    return;
  printf("%d  ", t->elem);
  PrintPreorder(t->lt);
  PrintPreorder(t->rt);


}

void PrintInorder(TTree t)
{
   if(t == NULL)
    return;
  PrintInorder(t->lt);
  printf("%d  ", t->elem);
  PrintInorder(t->rt);

}

void Free(TTree *t)
{
  if(*t == NULL)
    return;
  Free(&(*t)->lt);
  Free(&(*t)->rt);
  free(*t);

}

int Size(TTree t)
{
  if(t == NULL)
    return 0;
  return 1+Size(t->lt)+Size(t->rt);

}

int maxDepth(TTree t)
{
  if(t == NULL)
    return -1;
  int lDepth = maxDepth(t->lt);
  int rDepth = maxDepth(t->rt);
  if(lDepth > rDepth) // Se face maximul dintre cele doua 
    return 1+lDepth;
  else
    return 1+rDepth;
}


int NoLeaves (TTree t)
{
  if(t == NULL)
    return 0;
  if(t->lt == NULL && t->rt == NULL)
    return 1;
  return NoLeaves(t->lt)+NoLeaves(t->rt);
    
}

TTree Where (TTree t, Item x)
{
   if(t == NULL)
    return NULL;
  if(t->elem == x)
    return t;
  else 
  {
    TTree a = Where(t->lt,x);
    if(a != NULL)
      return a;
    return Where(t->rt,x);
  }

}


#endif // LINKEDSTACK_H_INCLUDED


