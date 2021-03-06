/* SYSC 2006 Winter 2014 Lab 9 */

/* A bit of code to exercise the functions in the singly_linked_list.c module.
   Version 1.02 - dlb 
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

void print_boolean(_Bool a_boolean)
{
    if (a_boolean)
		printf("true");
	else
		printf("false");
}

int main(void)
{
	IntNode *head = NULL;  // An empty linked list.
    IntNode *empty = NULL; // Another empty linked list.

    printf("=== Testing insert_front ===\n\n");
	printf("Calling insert_front with list: ");
    print_linked_list(head);
    printf("\nInserting 3.\n");
	head = insert_front(head, 3);
	printf("Expected list: 3\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

	printf("Calling insert_front with list: ");
    print_linked_list(head);
    printf("\nInserting 2.\n");
	head = insert_front(head, 2);
	printf("Expected list: 2 -> 3\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

	printf("Calling insert_front with list: ");
    print_linked_list(head);
    printf("\nInserting 1.\n");
	head = insert_front(head, 1);
	printf("Expected list: 1 -> 2 -> 3\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

    printf("=== Testing contains ===\n\n");

	_Bool found;

	printf("Calling contains with list: ");
    print_linked_list(empty);
    printf("\nSearching for 1.\n");
	found = contains(empty, 1);
	printf("Expected result: false\n");
    printf("Actual result: ");
    print_boolean(found);
	printf("\n\n");

	printf("Calling contains with list: ");
    print_linked_list(head);
    printf("\nSearching for 1.\n");
	found = contains(head, 1);
	printf("Expected result: true\n");
    printf("Actual result: ");
    print_boolean(found);
	printf("\n\n");

	printf("Calling contains with list: ");
    print_linked_list(head);
    printf("\nSearching for 3.\n");
	found = contains(head, 3);
	printf("Expected result: true\n");
    printf("Actual result: ");
    print_boolean(found);
	printf("\n\n");

	printf("Calling contains with list: ");
    print_linked_list(head);
    printf("\nSearching for 6.\n");
	found = contains(head, 6);
	printf("Expected result: false\n");
    printf("Actual result: ");
    print_boolean(found);
	printf("\n\n");

    printf("=== Testing append_rear ===\n\n");

	printf("Calling append_rear with list: ");
    print_linked_list(head);
    printf("\nAppending 4.\n");
	head = append_rear(head, 4);
	printf("Expected list: 1 -> 2 -> 3 -> 4\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

    printf("=== Testing remove_first ===\n\n");

	printf("Calling remove_first with list: ");
    print_linked_list(head);
	head = remove_first(head);
	printf("\nExpected list: 2 -> 3 -> 4\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

    printf("=== Testing remove_last ===\n\n");

	printf("Calling remove_last with list: ");
    print_linked_list(head);
	head = remove_last(head);
	printf("\nExpected list: 2 -> 3\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

	printf("Calling remove_last with list: ");
    print_linked_list(head);
	head = remove_last(head);
	printf("\nExpected list: 2\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

	printf("Calling remove_last with list: ");
    print_linked_list(head);
	head = remove_last(head);
	printf("\nExpected list: empty list\n");
    printf("Actual list: ");
    print_linked_list(head);
	printf("\n\n");

    /* Tests for Exercise 1. */
    
    printf("Building linked list 1 -> 1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5\n\n");

    head = NULL;
    head = intnode_construct(5, head);
    head = intnode_construct(5, head);
    head = intnode_construct(5, head);
    head = intnode_construct(4, head);
    head = intnode_construct(3, head);
    head = intnode_construct(3, head);
    head = intnode_construct(2, head);
    head = intnode_construct(1, head);
    head = intnode_construct(1, head);
    // print_linked_list(head);

    printf("=== Testing count ===\n\n");

    int occurrences;

	printf("Calling count with list: ");
    print_linked_list(empty);
    printf("\nCounting 1's.\n");
	occurrences = count(empty, 1);
	printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", occurrences);

	printf("Calling count with list: ");
    print_linked_list(empty);
    printf("\nCounting 7's.\n");
	occurrences = count(empty, 7);
	printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", occurrences);

	printf("Calling count with list: ");
    print_linked_list(head);
    printf("\nCounting 1's.\n");
	occurrences = count(head, 1);
	printf("Expected result: 2\n");
    printf("Actual result: %d\n\n", occurrences);

	printf("Calling count with list: ");
    print_linked_list(head);
    printf("\nCounting 2's.\n");
	occurrences = count(head, 2);
	printf("Expected result: 1\n");
    printf("Actual result: %d\n\n", occurrences);

	printf("Calling count with list: ");
    print_linked_list(head);
    printf("\nCounting 3's.\n");
	occurrences = count(head, 3);
	printf("Expected result: 2\n");
    printf("Actual result: %d\n\n", occurrences);

	printf("Calling count with list: ");
    print_linked_list(head);
    printf("\nCounting 4's.\n");
	occurrences = count(head, 4);
	printf("Expected result: 1\n");
    printf("Actual result: %d\n\n", occurrences);

	printf("Calling count with list: ");
    print_linked_list(head);
    printf("\nCounting 5's.\n");
	occurrences = count(head, 5);
	printf("Expected result: 3\n");
    printf("Actual result: %d\n\n", occurrences);

	printf("Calling count with list: ");
    print_linked_list(head);
    printf("\nCounting 7's.\n");
	occurrences = count(head, 7);
	printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", occurrences);

    /* Tests for Exercise 2. */

    printf("=== Testing index ===\n\n");

    int posn;

	printf("Calling index with list: ");
    print_linked_list(empty);
    printf("\nSearching for 1.\n");
	posn = index(empty, 1);
	printf("Expected result: -1\n");
    printf("Actual result: %d\n\n", posn);

	printf("Calling index with list: ");
    print_linked_list(head);
    printf("\nSearching for 1.\n");
	posn = index(head, 1);
	printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", posn);

	printf("Calling index with list: ");
    print_linked_list(head);
    printf("\nSearching for 2.\n");
	posn = index(head, 2);
	printf("Expected result: 2\n");
    printf("Actual result: %d\n\n", posn);

	printf("Calling index with list: ");
    print_linked_list(head);
    printf("\nSearching for 3.\n");
	posn = index(head, 3);
	printf("Expected result: 3\n");
    printf("Actual result: %d\n\n", posn);

	printf("Calling index with list: ");
    print_linked_list(head);
    printf("\nSearching for 4.\n");
	posn = index(head, 4);
	printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", posn);

	printf("Calling index with list: ");
    print_linked_list(head);
    printf("\nSearching for 5.\n");
	posn = index(head, 5);
	printf("Expected result: 6\n");
    printf("Actual result: %d\n\n", posn);

	printf("Calling index with list: ");
    print_linked_list(head);
    printf("\nSearching for 7.\n");
	posn = index(head, 7);
	printf("Expected result: -1\n");
    printf("Actual result: %d\n\n", posn);

    /* Tests for Exercise 31. */

    printf("=== Testing fetch ===\n\n");

    /* We can't test these cases, because they should cause the function
     * to terminate via assert. 
     *
     * 1. The list is empty; terminate via assert.
     * 2. index < 0 or index >= # of nodes; terminate via assert.
     */

    int value;

	printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 0.\n");
	value = fetch(head, 0);
	printf("Expected result: 1\n");
    printf("Actual result: %d\n\n", value);

	printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 1.\n");
	value = fetch(head, 1);
	printf("Expected result: 1\n");
    printf("Actual result: %d\n\n", value);	
    
    printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 2.\n");
	value = fetch(head, 2);
	printf("Expected result: 2\n");
    printf("Actual result: %d\n\n", value);	
    
    printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 3.\n");
	value = fetch(head, 3);
	printf("Expected result: 3\n");
    printf("Actual result: %d\n\n", value);	
    
    printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 4.\n");
	value = fetch(head, 4);
	printf("Expected result: 3\n");
    printf("Actual result: %d\n\n", value);	
    
    printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 5.\n");
	value = fetch(head, 5);
	printf("Expected result: 4\n");
    printf("Actual result: %d\n\n", value);	
    
    printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 6.\n");
	value = fetch(head, 6);
	printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", value);	
    
    printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 7.\n");
	value = fetch(head, 7);
	printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", value);	
    
    printf("Calling fetch with list: ");
    print_linked_list(head);
    printf("\nFetching value at index 8.\n");
	value = fetch(head, 8);
	printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", value);

    /* Tests for Exercise 4. */

    printf("Building linked list 1 -> 2 -> 3 -> 4\n\n");

    IntNode *list = NULL;
    list = intnode_construct(4, list);
    list = intnode_construct(3, list);
    list = intnode_construct(2, list);
    list = intnode_construct(1, list);

    printf("=== Testing remove_last_one_pointer ===\n\n");

	printf("Calling remove_last_one_pointer with list: ");
    print_linked_list(list);
	list = remove_last_one_pointer(list);
	printf("\nExpected list: 1 -> 2 -> 3\n");
    printf("Actual list: ");
    print_linked_list(list);
	printf("\n\n");

	printf("Calling remove_last_one_pointer with list: ");
    print_linked_list(list);
	list = remove_last_one_pointer(list);
	printf("\nExpected list: 1 -> 2\n");
    printf("Actual list: ");
    print_linked_list(list);
	printf("\n\n");

	printf("Calling remove_last_one_pointer with list: ");
    print_linked_list(list);
	list = remove_last_one_pointer(list);
	printf("\nExpected list: 1\n");
    printf("Actual list: ");
    print_linked_list(list);
	printf("\n\n");

	printf("Calling remove_last_one_pointer with list: ");
    print_linked_list(list);
	list = remove_last_one_pointer(list);
	printf("\nExpected list: empty list\n");
    printf("Actual list: ");
    print_linked_list(list);
	printf("\n\n");
}
