/*******************************************************************************
**
**  File: linked_list.h
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


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct list_item_t list_item;

struct list_item_t {

	list_item *previous;
	void *data;
	list_item *next;

};

typedef struct linked_list_t linked_list;

struct linked_list_t {

	unsigned int num_of_items;
	list_item *start_of_list;
	list_item *end_of_list;

};

extern linked_list* new_linked_list();
extern void destroy_linked_list(linked_list *l);
extern void add_item_to_start_of_list (linked_list *l, void *data);
extern void add_item_to_end_of_list (linked_list *l, void *data);
extern void insert_item_into_list (linked_list *l, void *data, unsigned int record);
extern void* remove_first_item_from_list (linked_list *l);
extern void* remove_last_item_from_list (linked_list *l);
extern void* get_item_from_list (linked_list *l, unsigned int record);
extern void* get_next_item (linked_list *l, list_item **item);
extern void* remove_item_from_list (linked_list *l, unsigned int record);
extern void* remove_given_item_from_list (linked_list *l, list_item *item);


#endif
