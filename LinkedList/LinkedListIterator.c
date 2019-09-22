/*
 * ListListIterator.c
 *
 * Implements the list LinkedListIterator
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include "LinkedListIterator.h"

#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

/**
 * This function makes an iterator from a list
 * list : the list to make the iterator from
 */
LinkedListIterator *newLinkedListIterator(LinkedList *list)
{
	LinkedListIterator *itr = malloc(sizeof(LinkedListIterator));
	itr->list = list;
	itr->leftNode = list->head;
	itr->rightNode = list->head->next;
	itr->lastReturned = NULL;
	return itr;
}

/**
 * This function advances the iterator ahead one position and returns the "skipped" over node data
 */
void *iteratorNext(LinkedListIterator *itr)
{
	if ((itr->rightNode->data == NULL) || (itr->list->size == 0))
	{
		return NULL;
	}
	itr->leftNode = itr->rightNode;
	itr->rightNode = itr->rightNode->next;
	itr->lastReturned = itr->leftNode;
	return itr->leftNode->data;
}

/**
 * This function advances the iterator backward one position and returns the "skipped" over node data
 */
void *iteratorPrevious(LinkedListIterator *itr)
{
	if (itr->leftNode->data == NULL || (itr->list->size == 0))
	{
		return NULL;
	}
	itr->rightNode = itr->leftNode;
	itr->leftNode = itr->leftNode->previous;
	itr->lastReturned = itr->rightNode;
	return itr->rightNode->data;
}

/**
 * Imitates the JAVA iterator add method
 * Adds a node;  iterNext() will be unaffected
 */
void iteratorAdd(LinkedListIterator *itr, void *data)
{
	if (itr->list->size == 0)
	{ // if the list is empty
		LinkedListNode *newNode = newLinkedListNode();
		newNode->next = itr->list->head;
		newNode->previous = itr->list->head;
		itr->list->head->next = newNode;
		itr->list->head->previous = newNode;
		itr->leftNode = itr->list->head;
		itr->rightNode = itr->list->head->next;
	}
	else
	{
		LinkedListNode *lNode = itr->leftNode;
		LinkedListNode *rNode = itr->rightNode;
		LinkedListNode *newNode = newLinkedListNode();
		newNode->data = data;

		newNode->next = rNode;
		newNode->previous = lNode;
		rNode->previous = newNode;
		lNode->next = newNode;

		itr->leftNode = newNode;
		itr->lastReturned = NULL;
	}

	itr->list->size++;
}

/**
 * This function inserts a node before the given iterator position
 */
void iteratorInsert(LinkedListIterator *itr, void *data)
{
	if (!(itr->leftNode->data == NULL))
	{ //cannot insert
		LinkedListNode *lNode = itr->leftNode->previous;
		LinkedListNode *rNode = itr->leftNode;
		LinkedListNode *newNode = newLinkedListNode();
		newNode->data = data;

		newNode->next = rNode;
		newNode->previous = lNode;
		lNode->next = newNode;
		rNode->previous = newNode;

		itr->rightNode = rNode;
		itr->leftNode = newNode;
		itr->lastReturned = NULL;
		itr->list->size++;
	}
}

/**
 * Rewinds the iterator to the starting position;
 */
void iteratorRewind(LinkedListIterator *itr)
{
	itr->leftNode = itr->list->head;
	itr->rightNode = itr->list->head->next;
	itr->lastReturned = NULL;
}

/**
 * Removes a node
 */
void *iteratorRemove(LinkedListIterator *itr)
{
	if (itr->lastReturned == NULL)
	{
		return NULL;
	}
	LinkedListNode *lNode = itr->lastReturned->previous;
	LinkedListNode *rNode = itr->lastReturned->next;
	void *data = itr->lastReturned->data;

	lNode->next = rNode;
	rNode->previous = lNode;
	itr->leftNode = lNode;
	itr->rightNode = rNode;

	itr->lastReturned = NULL;
	free(itr->lastReturned);
	itr->list->size--;
	return data;
}

void iteratorFree(LinkedListIterator *itr)
{
	free(itr);
}
