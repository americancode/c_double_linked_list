/*
 * ListNode.c
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include "LinkedListNode.h"

#include <stdlib.h>

/**
 * Allocates the node in memory
 */
LinkedListNode *newLinkedListNode(){
	LinkedListNode *node = malloc(sizeof(LinkedListNode));
	node->data = NULL;
	return node;
}
