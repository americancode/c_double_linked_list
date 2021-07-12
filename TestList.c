/*
 * TestList.c
 *
 *  Created on: Oct 18, 2017
 *      Author: Nathaniel Churchill
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedListIterator.h"

int main(int argc, char *argv[]) {
	LinkedList *list = newLinkedList();
	int i = 0;

	printf("list testing... integer values of 0 means NULL \n");
	printf("Adding numbers 1 through 25 to the list with listAdd() \n");
	//Add to the list integers in order and testing add functionality
	for (i = 1; i < 26; i++) {
		listAdd(list, (void*) i);
	}
	printf("Print the list from front to back 1 | 2 | ... | 25 |\n");
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	printf("Inserting 30 at the list beginning with listAddFirst()\n");
	listAddFirst(list, (void *) 30);
	printf("Print the list from front to back\n");
	//Test forward traversal with listGet
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	printf("Removing a node at index 0 with listRemove()\n");
	listRemove(list, 0);
	//test forward traversal with listGet
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	printf("Iterater Testing------------------------------------\n");
	//Make an iterator
	LinkedListIterator *itr = newLinkedListIterator(list);

	printf(
			"Iterating back and forth with next and previous------------------------------------\n");
	printf("%p | ", iteratorNext(itr));
	printf("%p | ", iteratorPrevious(itr));
	printf("%p | ", iteratorNext(itr));
	printf("%p | ", iteratorPrevious(itr));
	printf("%p | ", iteratorNext(itr));
	printf("%p | ", iteratorPrevious(itr));
	printf("%p | ", iteratorNext(itr));
	printf("%p | ", iteratorPrevious(itr));
	printf("%p | ", iteratorNext(itr));
	printf("%p | ", iteratorPrevious(itr));
	printf("\n\n\n");

	printf("Rewinding itr\n");
	iteratorRewind(itr);
	printf("calling iteratorNext() 4x\n");
	iteratorNext(itr);
	iteratorNext(itr);
	iteratorNext(itr);
	iteratorNext(itr);
	printf("Calling iteratorRemove() %p\n", iteratorRemove(itr));
	printf("Calling iteratorPrevious():  %p\n", iteratorPrevious(itr));
	printf("calling iteratorNext() 2x\n");
	iteratorNext(itr);
	iteratorNext(itr);

	printf("Printing the list forwards with the LinkedListIterator\n");
	for (i = 0; i < list->size; i++) {
		printf("%p | ", iteratorNext(itr));
	}
	printf("\n");
	printf("\n\n\n");

	printf("Printing the list backwards with the LinkedListIterator\n");
	for (i = 0; i < list->size; i++) {
		printf("%p | ", iteratorPrevious(itr));
	}
	printf("\n");
	printf("\n\n\n");

	printf(
			"Removing a node with iteratorRemove should remove 1. iteratorRemove() removes the last returned item. Print list in order\n");
	iteratorRemove(itr);
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	printf("Appending 25 BACK with iteratorAdd()\n");
	iteratorAdd(itr, (void *) 25);
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	printf("Inserting 80 with iteratorInsert()\n");
	iteratorInsert(itr, (void *) 80);
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));
	printf("\n\n\n");

	printf("Rewinding itr\n");
	iteratorRewind(itr);


	printf("Intentionally trying to break stuff\n");


	printf("Freeing the entire list.\n");
	listFree(list);
	list = newLinkedList();
		printf("Making new list with 1 to 25 \n");
		//Add to the list integers in order and testing add functionality
		for (i = 1; i < 26; i++) {
			listAdd(list, (void*) i);
		}
	printf("listGet with index 40: %p \n", listGet(list, 40));
	printf("listGet with index -8: %p \n", listGet(list, -8));

	printf("listRemove(list, -1) \n");
	listRemove(list, -1);
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));

	printf("listRemove(list, 25) \n");
	listRemove(list, -1);
	for (i = 0; i < list->size; i++) {
		printf("%p | ", listGet(list, i));
	}
	printf("\n");
	printf("The list size is: %d  \n", listSize(list));


	printf("iter testing ------------------------\n");



	LinkedListIterator *itr2 = newLinkedListIterator(list);


	for (i = 0; i < list->size; i++) {
			printf("%p | ", listGet(list, i));
		}
		printf("\n");

	printf("making a new iterator.\n");
	printf("calling remove. should give 0 for null:  %p\n", iteratorRemove(itr2));
	printf("calling remove. should give 0 for null:  %p\n", iteratorRemove(itr2));

	for (i = 0; i < list->size; i++) {
			printf("%p | ", listGet(list, i));
		}
		printf("\n");


	printf("calling iteratorNext() 4x\n");
	iteratorNext(itr2);
	iteratorNext(itr2);
	iteratorNext(itr2);
	iteratorNext(itr2);


	printf("calling remove. should remove 4:  %p\n", iteratorRemove(itr2));
		printf("calling remove. should give 0 for null:  %p\n", iteratorRemove(itr2));


		for (i = 0; i < list->size; i++) {
				printf("%p | ", listGet(list, i));
			}
			printf("\n");

			printf("Appending 4\n");
	iteratorAdd(itr2, (void *)4);

	for (i = 0; i < list->size; i++) {
					printf("%p | ", listGet(list, i));
				}
				printf("\n");




	printf("Calling iterPrevious(): %p\n", iteratorPrevious(itr2));




	return EXIT_SUCCESS;
}

