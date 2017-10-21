/*
 * LinkedList.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#ifndef LINKEDLIST_LINKEDLIST_H_
#define LINKEDLIST_LINKEDLIST_H_

#include "ListNode.h"

typedef struct _list{
	Node *head;
	int size;
} LST;

//Make a list
LST *mkList();

//append to the end of the list
void listAppend(LST *list, void *data);

//insert to the front of the list
void listInsert(LST *list, void *data);

//get the nth value
void *listGet(LST *list, int index);

//remove the nth item
void *listRemove(LST *list, int index);

//gets the size of the list
int listSize(LST *size);

#endif /* LINKEDLIST_LINKEDLIST_H_ */
