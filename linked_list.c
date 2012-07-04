/*******************************************************************************
**
**  File: linked_list.c
**
**  Info: 
**     Linked List Library
**     
**
**  Copyright 2009
**
**  Authors:
**     Matthew Hahn <mattshahn@gmail.com>
**     Casey Knolla <cknolla@gmail.com>
** 
**  This program is distributed in the hope that it will be useful, but
**  WITHOUT ANY WARRANTY; without even the implied warranties of
**  MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
**  PURPOSE.  
**
**  Date: Monday, June 29, 2009
**
*******************************************************************************/

#include <stdlib.h>
#include "linked_list.h"
 

linked_list* new_linked_list() {

	linked_list *l;
	l = (linked_list *) malloc(sizeof(linked_list));
	l->num_of_items = 0;
	l->start_of_list = NULL;
	l->end_of_list = NULL;
	
	return l;
	
}

void destroy_linked_list(linked_list *l) {


	while (l->num_of_items > 0) {
	
		free(remove_last_item_from_list (l));
		
	}
	
	free (l);

}

void add_item_to_start_of_list (linked_list *l, void *data) {

	list_item *new_item;
	list_item *tmp;
	
	/* allocate memory for new item */
	new_item = (list_item *) malloc(sizeof(list_item));
	
	new_item->data = data;
	new_item->previous = NULL;
	
	/* is this the first item? */
	if (l->start_of_list == NULL) {
		l->start_of_list = new_item;
		l->end_of_list = new_item;
		new_item->next = NULL;
	}
	else {
		tmp = l->start_of_list;
		tmp->previous = new_item;
		new_item->next = tmp;
		l->start_of_list = new_item;
	}
	
	l->num_of_items++;
	
}

void add_item_to_end_of_list (linked_list *l, void *data) {

	list_item *new_item;
	list_item *tmp;
	
	/* allocate memory for new item */
	new_item = (list_item *) malloc(sizeof(list_item));
	
	new_item->data = data;
	new_item->next = NULL;
	
	/* is this the first item? */
	if (l->end_of_list == NULL) {
		l->start_of_list = new_item;
		l->end_of_list = new_item;
		new_item->previous = NULL;
	}
	else {
		tmp = l->end_of_list;
		tmp->next = new_item;
		new_item->previous = tmp;
		l->end_of_list = new_item;
	}
	
	l->num_of_items++;
	
}

void insert_item_into_list (linked_list *l, void *data, unsigned int record) {
	
	list_item *new_item;
	list_item *tmp;
	unsigned int i;
	
	/* allocate memory for new item */
	new_item = (list_item *) malloc(sizeof(list_item));
	new_item->data = data;
	
	tmp = l->start_of_list;
	
	/* retrieve the record in the current record where the new_item will go */
	i = 0;
	while (tmp != NULL) {
		if (i == record) {
			new_item->next = tmp;
			break;
		}
		else {
			tmp = tmp->next;
			i++;
		}
	}
	
	if(record == 0) {
		free(new_item);
		add_item_to_start_of_list(l, data);
	}
	/* else if the record number is beyond the end of the list, add new_item to the end */
	else if(tmp == NULL) {
		free(new_item);
		add_item_to_end_of_list(l, data);
	}
	/* otherwise, this record is neither at the beginning or end and needs to be inserted between 2 items: pushes the current item to the right 1 spot */
	else {
		new_item->previous = new_item->next->previous;
		new_item->next->previous = new_item;
		new_item->previous->next = new_item;
		l->num_of_items++;
	}
}

void* remove_first_item_from_list (linked_list *l) {
	return remove_given_item_from_list (l, l->start_of_list);
}

void* remove_last_item_from_list (linked_list *l) {
	return remove_given_item_from_list (l, l->end_of_list);
}

void* remove_item_from_list (linked_list *l, unsigned int record) {

	list_item *tmp;
	unsigned int i;
	
	tmp = l->start_of_list;
	
	i = 0;
	while (tmp != NULL) {
	
		if (i == record) {
			return remove_given_item_from_list (l, tmp);
		}
		
		tmp = tmp->next;
		i++;
		
	}
	
	return NULL;
	
}

void* remove_given_item_from_list (linked_list *l, list_item *item) {
	
	list_item *next;
	list_item *previous;
	void* data;
	
	/* make sure that arguments are not NULL */
	if (l == NULL || item == NULL) return NULL;
	
	next = item->next;
	previous = item->previous;
	
	/* only one node in the list */
	if (l->start_of_list == item && l->end_of_list == item) {	
		l->start_of_list = NULL;
		l->end_of_list = NULL;	
	}
	/* node is at the start of the list */
	else if (l->start_of_list == item) {
		l->start_of_list = next;
		next->previous = NULL;
	}
	/* node is at the end of the list */
	else if (l->end_of_list == item) {
		l->end_of_list = previous;
		previous->next = NULL;
	}
	/* node is somewhere in the middle */
	else {
		previous->next = next;
		next->previous = previous;
	}
	
	data = item->data;
	free(item);
	l->num_of_items--;
	
	return data;
	
}

void* get_item_from_list (linked_list *l, unsigned int record) {

	list_item *tmp;
	unsigned int i;
	
	tmp = l->start_of_list;
	
	i = 0;
	while (tmp != NULL) {
		if (i == record) return tmp->data;
		tmp = tmp->next;
		i++;
	}
	
	return NULL;
	
}

void* get_next_item (linked_list *l, list_item **item) {
	
	void *data;
	
	/* return null if item is null */
	if (item == NULL) return NULL;
	if (*item == NULL) return NULL;
	
	/* save data pointer */
	data = (void *) (*item)->data;
	
	/* move item pointer to next item */
	*item = (*item)->next;
	
	return data;
	
}
