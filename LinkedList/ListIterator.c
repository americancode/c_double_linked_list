/*
 * ListIterator.c
 *
 * Implements the list Iterator
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdlib.h>
#include "LinkedList.h"
#include "ListIterator.h"

/**
 * This function makes an iterator from a list
 * list : the list to make the iterator from
 */
ITR *mkIter(LST *list) {
	ITR *itr = malloc(sizeof(ITR));
	itr->list = list;
	itr->leftNode = list->head;
	itr->rightNode = list->head->next;
	itr->lastReturned = NULL;
	return itr;
}

/**
 * This function advances the iterator ahead one position and returns the "skipped" over node data
 */
void *iterNext(ITR *itr) {
	if ((itr->rightNode->data == NULL) || (itr->list->size == 0)) {
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
void *iterPrevious(ITR *itr) {
	if (itr->leftNode->data == NULL || (itr->list->size == 0)) {
			return NULL;
	}
	itr->rightNode = itr->leftNode;
	itr->leftNode = itr->leftNode->previous;
	itr->lastReturned = itr->rightNode;
	return itr->rightNode->data;
}

/**
 * Inserts a node before the current position
 */
void iterAppend(ITR *itr, void *data) {
	if (itr->list->size == 0){ // if the list is empty
		Node *newNode = allocNode();
		newNode->next = itr->list->head;
		newNode->previous = itr->list->head;
		itr->list->head->next = newNode;
		itr->list->head->previous = newNode;
		itr->leftNode = itr->list->head;
		itr->rightNode = itr->list->head->next;
	} else {
		Node *lNode = itr->leftNode;
		Node *rNode = itr->rightNode;
		Node *newNode = allocNode();
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
void iterInsert(ITR *itr, void *data) {
	if (!(itr->leftNode->data == NULL)) { //cannot insert
		Node *lNode = itr->leftNode->previous;
		Node *rNode = itr->leftNode;
		Node *newNode = allocNode();
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
void iterRewind(ITR *itr) {
	itr->leftNode = itr->list->head;
		itr->rightNode = itr->list->head->next;
		itr->lastReturned = NULL;
}

/**
 * Removes a node
 */
void *iterRemove(ITR *itr) {
	if (itr->lastReturned == NULL){
		return NULL;
	}
	Node *lNode = itr->lastReturned->previous;
	Node *rNode = itr->lastReturned->next;
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
