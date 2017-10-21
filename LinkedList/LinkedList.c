/*
 * LinkedList.c
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdlib.h>
#include "LinkedList.h"
#include "ListNode.h"
#include "ListIterator.h"

LST *mkList() {
	LST *list = malloc(sizeof(LST));
	list->size = 0;
	list->head = allocNode();
	list->head->next = NULL;
	list->head->previous = NULL;
	return list;
}

static Node *getNode(LST *list, int index) {
	if (index == 0) {
		return list->head->next;
	}
	if (index == (list->size - 1)) {
		return list->head->previous;
	}

	Node *node = list->head;
	int i = 0;
	for (i = 0; i <= index; i++) {
		node = node->next;
	}

	return node;
}

void listAppend(LST *list, void *data) {
	Node *node = allocNode();
	node->data = data;
	//Check for empty list
	if (list->head->next == NULL && list->head->previous == NULL) {
		node->next = list->head;
		node->previous = list->head;
		list->head->next = node;
		list->head->previous = node;
	} else {
		Node *lNode = list->head;
		Node *rNode = list->head->previous;

		node->next = lNode;
		node->previous = rNode;
		lNode->previous = node;
		rNode->next = node;
	}
	list->size++;
}

void listInsert(LST *list, void *data) {
	Node *node = allocNode();
	node->data = data;
	//Check for empty list
	if (list->head->next == NULL && list->head->previous == NULL) {
		node->next = list->head;
		node->previous = list->head;
		list->head->next = node;
		list->head->previous = node;
	} else {
		Node *oldFront = list->head->next;
		list->head->next = node;
		node->next = oldFront;
		node->previous = list->head;
		oldFront->previous = node;
	}
	list->size++;
}

void *listGet(LST *list, int index) {
	if (index >= list->size || index < 0) {
		return NULL;
	}
	if (index == 0) {
		return list->head->next->data;
	}
	if (index == (list->size - 1)) {
		return list->head->previous->data;
	}

	Node *node = list->head;
	int i = 0;
	for (i = 0; i <= index; i++) {
		node = node->next;
	}

	return node->data;
}

int listSize(LST *list) {
	return list->size;
}

void *listRemove(LST *list, int index) {
	if (index >= list->size || index < 0) {
		return NULL;
	}

	Node *rmNode = getNode(list, index);
	rmNode->previous->next = rmNode->next;
	rmNode->next->previous = rmNode->previous;
	void *ptr = rmNode->data;
	free(rmNode);
	list->size--;
	return ptr;
}

