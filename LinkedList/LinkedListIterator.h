/*
 * ListLinkedListIterator.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#ifndef LINKEDLISTITERATOR_H_
#define LINKEDLISTITERATOR_H_

#include "LinkedList.h"
#include "LinkedListNode.h"

typedef struct _LinkedListIterator {
	LinkedListNode *leftNode;
	LinkedListNode *rightNode;
	LinkedListNode *lastReturned;
	LinkedList *list;
} LinkedListIterator;


//Get an LinkedListIterator
LinkedListIterator *newLinkedListIterator(LinkedList *list);

//append after current position
void iteratorAdd(LinkedListIterator *iter, void *data);

//insert before position
void iteratorInsert(LinkedListIterator *iter, void *data);

//get the next element
void *iteratorNext(LinkedListIterator *iter);

//get the previous element
void *iteratorPrevious(LinkedListIterator *iter);


//Remove the last item returned
void *iteratorRemove(LinkedListIterator *iter);

//Rewind the iterator
void iteratorRewind(LinkedListIterator *iter);

void iteratorFree(LinkedListIterator *iter);


#endif /* LINKEDLISTITERATOR_H_ */
