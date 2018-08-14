#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Key;
typedef int Value;
typedef long(*HashFunction)(Key, long);

typedef struct Element {
  Key key;
  Value value;
  struct Element *next;
} Element;

typedef struct HashTable {
  Element** elements;
  long size;
  HashFunction hashFunction;
} HashTable;

void initHashTable(HashTable **h, long size, HashFunction f) {
  // Cerinta 1
 	(*h)=malloc(sizeof(HashTable));
	(*h)->elements=malloc(sizeof(Element *));
	int i;
	for( i=0; i < size ; i++ ) {
		(*h)->elements[i]=malloc(sizeof(Element));
		(*h)->elements[i]->next=NULL;
	}
	(*h)->hashFunction=f;
}

int exists(HashTable *hashTable, Key key) {
	int i;
	int index=hashTable->hashFunction(key,hashTable->size);
	if( hashTable->elements[index] == NULL )  return 0;
	else{
		Element *aux=hashTable->elements[index];
		while(aux!=NULL){
			if(strcmp(aux->key,key)==0) return 1;
			aux=aux->next;		
		}	
	}	
 	
	return 0;
}

Value get(HashTable *hashTable, Key key) {
  	
	int i;
	int index=hashTable->hashFunction(key,hashTable->size);
	if( hashTable->elements[index] == NULL )  return (Value)0;
	else{
		Element *aux=hashTable->elements[index];
		while(aux!=NULL){
			if(strcmp(aux->key,key)==0) return aux->value;
			aux=aux->next;		
		}	
	}	
  return (Value)0;
}

void put(HashTable *hashTable, Key key, Value value) {
  // Cerinta 1
	int i;
	int index=hashTable->hashFunction(key,hashTable->size);
	Element *aux=hashTable->elements[index];
	Element *new=malloc(sizeof(Element));
	new->key=key;
	new->value=value;
	new->next=aux;
	aux->next=new;
	
}

void deleteKey(HashTable *hashTable, Key key) {
  // Cerinta 1
	int i;
	int index=hashTable->hashFunction(key,hashTable->size);
	if( hashTable->elements[index] == NULL )  return ;
	else{
		Element *aux=hashTable->elements[index];
		Element *auxx=aux->next;
		aux->next=aux->next->next;
		free(auxx);
		hashTable->size--;
	}	

}

void print(HashTable *hashTable) {
 	int i;
	Element *aux;
	for( i = 0; i < hashTable->size; i++){
		aux=hashTable->elements[i];
		while(aux != NULL ){
			printf("%d %s\n",aux->key,aux->value);
			aux=aux->next;		
		}
	}
}

void freeHashTable(HashTable *hashTable) {
  // Cerinta 1
	 int i;
	Element *aux;
	for( i = 0; i < hashTable->size; i++){
		aux=hashTable->elements[i];
		free(aux);
	}
	free(hashTable->elements);
	free(hashTable);
}


long hash1(Key word, long size) {
  // Cerinta 2
  return 0l;
}

int main(int argc, char* argv[]) {
  HashTable *hashTable;
  FILE *f1, *f2;
  char word[256];
  long hashSize, common;

  hashSize = atoi(argv[1]);
  f1 = fopen(argv[2], "r");
  f2 = fopen(argv[3], "r");

  initHashTable(&hashTable, hashSize, &hash1);

  // Cerinta 3

  // ...

  // Cerinta 4

  // ...

  printf("Common words: %ld\n", common);

  fclose(f1);
  fclose(f2);
  return 0;
}
