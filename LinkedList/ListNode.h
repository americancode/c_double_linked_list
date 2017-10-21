/*
 * ListNode.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

typedef struct _node {
	void *data;
	struct _node *next;
	struct _node *previous;
} Node;

Node *allocNode();

#endif /* LISTNODE_H_ */
