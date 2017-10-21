/*
 * ListNode.c
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdlib.h>
#include "ListNode.h"

Node *allocNode(){
	Node *node = malloc(sizeof(Node));
	node->data = NULL;
	return node;
}
