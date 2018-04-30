/*
 * ListLinkedListNode.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

typedef struct _node {
								void *data;
								struct _node *next;
								struct _node *previous;
} LinkedListNode;

LinkedListNode *newLinkedListNode();

#endif /* LINKEDLISTNODE_H_ */
