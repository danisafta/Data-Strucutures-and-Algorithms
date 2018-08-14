
#ifndef AVLTREE_H_
#define AVLTREE_H_

#include<stdlib.h>

// An AVL tree node
typedef struct AVLNode{
	Item elem;
	int height;
	struct AVLNode *l;
	struct AVLNode *r;
	struct AVLNode *p;

}AVLNode;

typedef struct AVLTree{
	long size;
	AVLNode* root;
	AVLNode* nil;
	int (*comp)(Item a, Item b);
}AVLTree;

AVLTree* avlCreateTree(int (*comp) (Item1,Item1))
{
	AVLTree* newTree = (AVLTree*) malloc(sizeof(AVLTree));
	newTree->comp = comp;
	newTree->nil = (AVLNode*) malloc(sizeof(AVLNode));
	newTree->nil->p = newTree->nil->l = newTree->nil->r = newTree->nil;
	newTree->nil->height = 0;
	newTree->root = (AVLNode*) malloc(sizeof(AVLNode));
	newTree->root->p = newTree->root->l = newTree->root->r = newTree->nil;
	newTree->root->height = 0;
	newTree->size = 0;

	return newTree;
}

int avlIsEmpty(AVLTree* tree){
	return (tree->root->l == tree->nil);
}

AVLNode* avlNewNode(AVLTree* tree){
	AVLNode* newNode = (AVLNode*) malloc(sizeof(AVLNode));
	// Initialize the new node to be used in the tree
	newNode->p = newNode->r = newNode->l = tree->nil;
	newNode->height = 1;

	return newNode;
}



// A utility function to get maximum of two integers
int max(int a, int b){
	return (a > b)? a : b;
}

// A utility function to right rotate subtree rooted with y
void avlRightRotate(AVLTree *tree,  AVLNode *y){
	
    AVLNode *root=y;
    AVLNode *p=y->l;
    AVLNode *pr=p->r;
    
    p->r=root;
    root->l=pr;
     p->p=y->p;

    if(y->p->l==y)
        y->p->l=p;
    else
        y->p->r=p;

    y->p=p;
    
    root->height=max(root->l->height,root->r->height)+1;
    p->height=max(p->l->height,p->r->height)+1;

    if(y==tree->root->l)
        tree->root->l=p;
	//TO DO HERE
}



void fixA(AVLTree *tree, AVLNode *y,Item elem)
{
	while(y!=tree->root)
	{
		y->height=max(y->l->height,y->r->height)+1;
		int b = avlGetBalance(y);
		if(b>1 && elem < y->l->elem)
			avlRightRotate(tree,y);
		if(b>1 && elem > y->l->elem)
			{
				avlLeftRotate(tree,y);
				avlRightRotate(tree,y);

			}
		if(b<-1 && elem > y->r->elem)
			avlLeftRotate(tree,y);
		if(b<-1 && elem > y->r->elem)
			{
				avlRightRotate(tree,y);
				avlLeftRotate(tree,y);			
			}
		y=y->p;
	}	
}


// A utility function to left rotate subtree rooted with x
void avlLeftRotate(AVLTree *tree, AVLNode *x){
	
    AVLNode *root=x;
    AVLNode *p=x->r;
    AVLNode *pl=p->l;

    p->l=root;
    root->r=pl;
    p->p=x->p;

    if(x->p->l==x)
        x->p->l=p;
    else
        x->p->r=p;

    x->p=p;

    root->height=max(root->l->height,root->r->height)+1;
    p->height=max(p->l->height,p->r->height)+1;

    if(x==tree->root->l)
        tree->root->l=p;
	//TO DO HERE
}

// Get Balance factor of node x
int avlGetBalance(AVLNode *x){
	if (x == NULL)
		return 0;
	return x->l->height - x->r->height;
}

AVLNode * avlMinimum(AVLTree* tree, AVLNode* x){
	while (x->l != tree->nil)
		x = x->l;
	return x;
}

AVLNode* avlMaximum(AVLTree* tree, AVLNode* x){
	while(x->r != tree->nil){
		x = x->r;
	}
	return x;
}



void avlInsert(struct AVLTree* tree, Item elem){
	
	//TO DO HERE
    if(tree==NULL)
        return;

    AVLNode *q=avlNewNode(tree);
    q->elem=elem;
    
    if(avlIsEmpty(tree)){
        q->p=tree->root;
        tree->root->l=q;
        tree->size=1;
    }
    else{
            AVLNode *t=tree->root->l;
            AVLNode *prev;
            prev=t;

            while(t!=tree->nil){
                prev=t;
                if(*t->elem > *elem)
                    t=t->l;
                else
                    t=t->r;
            }

            if(*prev->elem != *elem){
                q->p=prev;

                if(*prev->elem >*elem)
                    prev->l=q;
                else
                    prev->r=q;
    
                tree->size++;
                prev->height=max(prev->l->height,prev->r->height)+1;
                t=prev->p;

                while(t!=tree->root){
                    t->height=max(t->l->height,t->r->height)+1;
                    t=t->p;
                }
            }

            int balance;
            t=prev;
            balance=avlGetBalance(prev);
            
            while(t->p!=tree->root && abs(balance) <=1){
                t=t->p;
                balance=avlGetBalance(t);
             
            
            if(balance>1 && *elem<*t->l->elem)
                avlRightRotate(tree,t);

            else if(balance<-1 && *elem>*t->r->elem)
                avlLeftRotate(tree,t);

            else if(balance>1 && *elem>*t->l->elem){
                avlRightRotate(tree,t->l);
                avlLeftRotate(tree,t);
            }
            
            else if(balance<-1 && *elem<*t->r->elem){
                avlRightRotate(tree,t->r);
                avlLeftRotate(tree,t);
            }
	
		t=t->p;
	}
            
           // PrintPostorder(tree,tree->root->l);
            //printf("\n");
            
    }           

}




void avlDeleteNode(AVLTree *tree, AVLNode* node){
	destroyElem(node->elem);
	free(node);
}


void avlDestroyTreeHelper(AVLTree* tree, AVLNode* x) {
	if (x != tree->nil) {
		avlDestroyTreeHelper(tree,x->l);
		avlDestroyTreeHelper(tree,x->r);
		avlDeleteNode(tree,x);
	}
}

void avlDestroyTree(AVLTree* tree){
	avlDestroyTreeHelper(tree, tree->root->l);
	free(tree->root);
	free(tree->nil);
	free(tree);
}

#endif /* AVLTREE_H_ */
