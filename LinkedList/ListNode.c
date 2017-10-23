/*
 * ListNode.c
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdlib.h>
#include "ListNode.h"

/**
 * Allocates the node in memory
 */
Node *allocNode(){
	Node *node = malloc(sizeof(Node));
	node->data = NULL;
	return node;
}
