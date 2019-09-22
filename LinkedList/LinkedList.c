/*
 * LinkedList.c
 *
 *    Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdlib.h>
#include "LinkedList.h"

#include "LinkedListIterator.h"
#include "LinkedListNode.h"

/**
 * Makes the list in memory and sets the initial pointers
 */
LinkedList *newLinkedList()
{
	LinkedList *list = malloc(sizeof(LinkedList));
	list->size = 0;
	list->head = newLinkedListNode();
	list->head->next = NULL;
	list->head->previous = NULL;
	return list;
}

/**
 * Returns a node for a given integer index
 */
static LinkedListNode *getNode(LinkedList *list, int index)
{
	LinkedListNode *node = list->head;
	if (index > (list->size / 2))
	{
		int i = 0;
		int j = list->size - index;
		for (i = 0; i < j; i++)
		{
			node = node->previous;
		}
	}
	else
	{
		int i = 0;
		for (i = 0; i <= index; i++)
		{
			node = node->next;
		}
	}

	return node;
}

/**
 * Appends a node to the end of the list
 */
void listAdd(LinkedList *list, void *data)
{
	LinkedListNode *node = newLinkedListNode();
	node->data = data;
	//Check for empty list
	if (list->head->next == NULL && list->head->previous == NULL)
	{
		node->next = list->head;
		node->previous = list->head;
		list->head->next = node;
		list->head->previous = node;
	}
	else
	{
		LinkedListNode *lNode = list->head;
		LinkedListNode *rNode = list->head->previous;

		node->next = lNode;
		node->previous = rNode;
		lNode->previous = node;
		rNode->next = node;
	}
	list->size++;
}

/**
 * Inserts a node a the beginning of the list
 */
void listAddFirst(LinkedList *list, void *data)
{
	LinkedListNode *node = newLinkedListNode();
	node->data = data;
	//Check for empty list
	if (list->head->next == NULL && list->head->previous == NULL)
	{
		node->next = list->head;
		node->previous = list->head;
		list->head->next = node;
		list->head->previous = node;
	}
	else
	{
		LinkedListNode *oldFront = list->head->next;
		list->head->next = node;
		node->next = oldFront;
		node->previous = list->head;
		oldFront->previous = node;
	}
	list->size++;
}

/**
 * Gets the data from a node at a given index;  optimized to travel from either end
 * depending on which is closer
 */
void *listGet(LinkedList *list, int index)
{
	if (index >= list->size || index < 0)
	{
		return NULL;
	}

	LinkedListNode *node = list->head;
	if (index > (list->size / 2))
	{
		int i = 0;
		int j = list->size - index;
		for (i = 0; i < j; i++)
		{
			node = node->previous;
		}
	}
	else
	{
		int i = 0;
		for (i = 0; i <= index; i++)
		{
			node = node->next;
		}
	}

	return node->data;
}

/**
 * Returns the size of a given list
 */
int listSize(LinkedList *list)
{
	return list->size;
}

/**
 * Removes a node with the given index;
 */
void *listRemove(LinkedList *list, int index)
{
	if (index >= list->size || index < 0)
	{
		return NULL;
	}

	LinkedListNode *rmNode = getNode(list, index);
	rmNode->previous->next = rmNode->next;
	rmNode->next->previous = rmNode->previous;
	void *ptr = rmNode->data;
	free(rmNode);
	list->size--;
	return ptr;
}

/**
 * Frees the entire list
 */
void listFree(LinkedList *list)
{
	int i = 0;
	LinkedListNode *rmNode = NULL;
	rmNode = list->head;

	for (i = 0; i < list->size; i++)
	{
		rmNode = rmNode->next;
		free(rmNode);
	}
	free(list->head);
	free(&list->size);
}
