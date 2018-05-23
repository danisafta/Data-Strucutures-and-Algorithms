#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <stdio.h>                                          // needed for printf
#include <stdlib.h>                           // needed for alloc, realloc, free

/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------

/*
  OrderedSet represents a set with elements of type T stored in memory
  in an ordered fashion.
*/

typedef struct OrderedSet {
  T* elements;                    // pointer to where the elements are in memory
  long size;                                // the number of elements in the set
  long capacity;                      // the current capacity (allocated memory)
} OrderedSet;

// -----------------------------------------------------------------------------

/*
  Function that creates an OrderedSet with elements of type T with a given
  initial capacity.
*/

OrderedSet* createOrderedSet(long initialCapacity) {

  OrderedSet* newSet = (OrderedSet*) malloc(sizeof(OrderedSet));

  newSet->size = 0;                        // initially, the set is empty
  newSet->capacity = initialCapacity;
  newSet->elements = (T*) malloc(initialCapacity * sizeof(T));

  return newSet;
}

// -----------------------------------------------------------------------------

/*
  Function that checks if an element exists in a given set. As the
  elements of the set are ordered in memory, this function uses binary
  search.

  Function returns 1 if the given element exists in the set, and 0
  otherwise.
*/

int contains(OrderedSet* set, const T element) {
  // TODO : Cerința 2

int i;

for(i = 0; i < s -> size; i++){

	if(s -> elements[i] == element)
		return 1;
}

return 0;
}

// -----------------------------------------------------------------------------

/*
  Function that adds a new element to a set. If the element was
  already in the set, nothing changes. Otherwise, the element is added
  to the set. In the end, the elements must be in ascending order.
*/

void add(OrderedSet* set, const T newElement)	{
  // TODO : Cerința 2

if(contains(set,newElement))
	return;

if(set -> size == set -> capacity)	{
	set -> capacity << = 1;
	set -> elements = (T*)realloc(set -> elements,set -> capacity * sizeof(T));
}

set -> elements[set -> size] = newElement;
set -> size ++;
long idx = set -> size-1;

while( idx > 0 && set -> elements[idx-1] > newElement )	{
	set -> elements[idx] = set -> elements[idx - 1];
	idx--;
}
set -> elements[idx] = newElement;

}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the union of
  the two
*/

OrderedSet* unionOrderedSets(OrderedSet* s1, OrderedSet* s2) {
  // TODO : Cerința 3
				//interclasare
OrderSet* s = createOrderedSet(s1 -> size + s2 -> size);
long idx = 0, idx1 = 0, idx2 = 0;

while(idx1 < s1 -> size && idx2 < s2 -> size)
if(s1 -> elements[idx1] < s2 -> elements[idx2])
	s -> elements[idx++] = s1 -> elements[idx1++];

else if(s1 -> elements[idx1] > s2 -> elements[idx2])
	s -> elements[idx++] = s2 -> elements[idx2++];

else
	idx2++;
while(idx1 < s1 -> size)
s -> elements[idx++]=s1 ->  elements[idx1++];

while(idx2 < s2 -> size)
s -> elements[idx++]=s2 ->  elements[idx2++];

s -> size = idx;

return s;

  return createOrderedSet(1);
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the
  intersection of the two
*/

OrderedSet* intersectOrderedSets(OrderedSet* s1, OrderedSet* s2) {
  // TODO : Cerința 3
long idx = 0; idx1 = 0; idx2 = 0;

OrderSet* s = createOrderedSet(s1 -> size);

while(idx1 < s1 -> size && idx2 < s2 -> size)
	if(s1 -> elements[idx1] == s2 -> elements[idx2]
		s -> elements[idx] = s1 -> elements[idx1];
		idx++;
		idx1++;
		idx2++;
}
else if ( s1 -> elements[idx1] < s2 -> elements[idx2])
idx1++;

else(s1 -> elements[idx1] > s2 -> elements[idx2])
idx2++;


  return createOrderedSet(1);
}


// -----------------------------------------------------------------------------

#endif
