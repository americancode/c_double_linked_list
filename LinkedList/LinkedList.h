/*
 * LinkedList.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#ifndef LINKEDLIST_LINKEDLIST_H_
#define LINKEDLIST_LINKEDLIST_H_

#include "LinkedListNode.h"

typedef struct _list {
	LinkedListNode *head;
	int size;
} LinkedList;

//Make a list
LinkedList *newLinkedList();

//append to the end of the list
void listAdd(LinkedList *list, void *data);

//insert to the front of the list
void listAddFirst(LinkedList *list, void *data);

//get the nth value
void *listGet(LinkedList *list, int index);

//remove the nth item
void *listRemove(LinkedList *list, int index);

//gets the size of the list
int listSize(LinkedList *size);

//Free all the nodes in the list
void listFree(LinkedList *list);

#endif /* LINKEDLIST_LINKEDLIST_H_ */
