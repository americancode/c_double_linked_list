/*
 * ListIterator.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#ifndef LISTITERATOR_H_
#define LISTITERATOR_H_

#include "LinkedList.h"
#include "ListNode.h"

typedef struct _itr {
	Node *leftNode;
	Node *rightNode;
	Node *lastReturned;
	struct _list *list;
} ITR;


//Get an Iterator
ITR *mkIter(LST *list);

//append after current position
void iterAppend(ITR *iter, void *data);

//insert before position
void iterInsert(ITR *iter, void *data);

//get the next element
void *iterNext(ITR *iter);

//get the previous element
void *iterPrevious(ITR *iter);

//get the next element
void *iterNext(ITR *iter);

//Remove the last item returned
void *iterRemove(ITR *iter);

//Rewind the iterator
void iterRewind(ITR *iter);

#endif /* LISTITERATOR_H_ */
