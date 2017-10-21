/*
 * ListIterator.c
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdlib.h>
#include "LinkedList.h"
#include "ListIterator.h"

ITR *mkIter(LST *list) {
	ITR *itr = malloc(sizeof(ITR));
	itr->list = list;
	itr->leftNode = list->head;
	itr->rightNode = list->head->next;
	itr->lastReturned = NULL;
	return itr;
}

void *iterNext(ITR *itr) {
	if ((itr->rightNode->data == NULL) || (itr->list->size == 0)) {
			return NULL;
	}
	itr->leftNode = itr->rightNode;
	itr->rightNode = itr->rightNode->next;
	itr->lastReturned = itr->leftNode;
	return itr->leftNode->data;
}

void *iterPrevious(ITR *itr) {
	if (itr->leftNode->data == NULL || (itr->list->size == 0)) {
			return NULL;
	}
	itr->leftNode = itr->leftNode->previous;
	itr->rightNode = itr->leftNode;
	itr->lastReturned = itr->rightNode;
	return itr->rightNode->data;
}

void iterAppend(ITR *itr, void *data) {
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

	itr->list->size++;
}

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
		itr->rightNode = rNode;

		itr->list->size++;
	}
}

void iterRewind(ITR *itr) {
	itr->leftNode = itr->list->head;
		itr->rightNode = itr->list->head->next;
		itr->lastReturned = NULL;
}

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

	free(itr->lastReturned);
	itr->list->size--;
	return data;
}
