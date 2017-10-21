/*
 * TestList.c
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/LinkedList.h"
#include "LinkedList/ListIterator.h"

int main(int argc, char *argv[]) {
	LST *list = mkList();
	int i = 0;

	printf("Adding numbers 1 through 25 to the list with listAppend() \n");
	//Add to the list integers in order and testing add functionality
	for (i = 1; i < 26; i++) {
		listAppend(list, (void*) i);
	}
	printf("Print the list from front to back 1 | 2 | ... | 25 |\n");
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");


	printf("Inserting 30 at the list beginning with listInsert()\n");
	listInsert(list, (void *) 30);
	printf("Print the list from front to back\n");
	//test forward traversal with listGet
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	//Make an iterator
	ITR *itr = mkIter(list);

	printf("Printing the list forwards with the ITR\n");
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) iterNext(itr));
	}
	printf("\n");
	printf("\n\n\n");


	printf("Removing a node with iterRemove should remove 25\n");
		iterRemove(itr);
		for (i = 0; i < list->size; i++) {
			printf("%d | ", (int) listGet(list, i));
		}
		printf("\n");
		printf("The list size is: %d  \n", listSize(list));
		printf("\n\n\n");


	printf("Appending 25 BACK with iterAppend()\n");
	iterAppend(itr, (void *) 25);
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");





	printf("Inserting 80 with iterInsert()\n");
	iterInsert(itr, (void *) 80);
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");


	printf("Printing the list backwards with the ITR from current position\n");
	for (i = 0; i < list->size - 1; i++) {
		printf("%d | ", (int) iterPrevious(itr));
	}
	printf("\n");
	printf("\n\n\n");


	printf("Removing a node at index 0 with listRemove()\n");
	listRemove(list, 0);
	//test forward traversal with listGet
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");


	printf("Removing a node at index 23 listRemove()\n");
	listRemove(list, 23);
	//test forward traversal with listGet
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");


	printf("Intentionally trying to break stuff\n");
	printf("listGet with index 40: %d \n", (int) listGet(list, 40));
	printf("listGet with index -8: %d \n", (int) listGet(list, -8));


	printf("listRemove(list, -1) \n");
	listRemove(list, -1);
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));


	printf("listRemove(list, 25) \n");
	listRemove(list, -1);
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));




	return EXIT_SUCCESS;
}

