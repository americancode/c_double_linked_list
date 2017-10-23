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

	printf("list testing... integer values of 0 means NULL \n");
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

	printf("Removing a node at index 0 with listRemove()\n");
	listRemove(list, 0);
	//test forward traversal with listGet
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	printf("Iterater Testing------------------------------------\n");
	//Make an iterator
	ITR *itr = mkIter(list);

	printf(
			"Iterating back and forth with next and previous------------------------------------\n");
	printf("%d | ", (int) iterNext(itr));
	printf("%d | ", (int) iterPrevious(itr));
	printf("%d | ", (int) iterNext(itr));
	printf("%d | ", (int) iterPrevious(itr));
	printf("%d | ", (int) iterNext(itr));
	printf("%d | ", (int) iterPrevious(itr));
	printf("%d | ", (int) iterNext(itr));
	printf("%d | ", (int) iterPrevious(itr));
	printf("%d | ", (int) iterNext(itr));
	printf("%d | ", (int) iterPrevious(itr));
	printf("\n\n\n");

	printf("Rewinding itr\n");
	iterRewind(itr);
	printf("calling iterNext() 4x\n");
	iterNext(itr);
	iterNext(itr);
	iterNext(itr);
	iterNext(itr);
	printf("Calling iterRemove() %d\n", (int) iterRemove(itr));
	printf("Calling iterPrevious():  %d\n", (int) iterPrevious(itr));
	printf("calling iterNext() 2x\n");
	iterNext(itr);
	iterNext(itr);

	printf("Printing the list forwards with the ITR\n");
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) iterNext(itr));
	}
	printf("\n");
	printf("\n\n\n");

	printf("Printing the list backwards with the ITR\n");
	for (i = 0; i < list->size; i++) {
		printf("%d | ", (int) iterPrevious(itr));
	}
	printf("\n");
	printf("\n\n\n");

	printf(
			"Removing a node with iterRemove should remove 1. iterRemove() removes the last returned item\n");
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

	printf("Rewinding itr\n");
	iterRewind(itr);


	printf("Intentionally trying to break stuff\n");


	printf("Freeing the entire list.\n");
	freeList(list);
	list = mkList();
		printf("Making new list with 1 to 25 \n");
		//Add to the list integers in order and testing add functionality
		for (i = 1; i < 26; i++) {
			listAppend(list, (void*) i);
		}
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


	printf("iter testing ------------------------\n");



	ITR *itr2 = mkIter(list);


	for (i = 0; i < list->size; i++) {
			printf("%d | ", (int) listGet(list, i));
		}
		printf("\n");

	printf("making a new iterator.\n");
	printf("calling remove. should give 0 for null:  %d\n", (int) iterRemove(itr2));
	printf("calling remove. should give 0 for null:  %d\n", (int) iterRemove(itr2));

	for (i = 0; i < list->size; i++) {
			printf("%d | ", (int) listGet(list, i));
		}
		printf("\n");


	printf("calling iterNext() 4x\n");
	iterNext(itr2);
	iterNext(itr2);
	iterNext(itr2);
	iterNext(itr2);


	printf("calling remove. should remove 4:  %d\n", (int) iterRemove(itr2));
		printf("calling remove. should give 0 for null:  %d\n", (int) iterRemove(itr2));


		for (i = 0; i < list->size; i++) {
				printf("%d | ", (int) listGet(list, i));
			}
			printf("\n");

			printf("Appending 4\n");
	iterAppend(itr2, (void *)4);

	for (i = 0; i < list->size; i++) {
					printf("%d | ", (int) listGet(list, i));
				}
				printf("\n");


	printf("Calling iterPrevious(): %d\n", iterPrevious(itr2));




	return EXIT_SUCCESS;
}

