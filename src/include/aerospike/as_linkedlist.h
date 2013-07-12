/******************************************************************************
 *	Copyright 2008-2013 by Aerospike.
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy 
 *	of this software and associated documentation files (the "Software"), to 
 *	deal in the Software without restriction, including without limitation the 
 *	rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
 *	sell copies of the Software, and to permit persons to whom the Software is 
 *	furnished to do so, subject to the following conditions:
 * 
 *	The above copyright notice and this permission notice shall be included in 
 *	all copies or substantial portions of the Software.
 * 
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *	IN THE SOFTWARE.
 *****************************************************************************/

#pragma once

#include <aerospike/as_val.h>

/*****************************************************************************
 *	TYPES
 *****************************************************************************/

struct as_list_s;

/**
 *	An linked-list implementation for `as_list`.
 *
 *	To use the list, you can either initialize a stack allocated list, 
 *	using `as_linkedlist_init()`:
 *
 *	~~~~~~~~~~{.c}
 *	as_list list;
 *	as_linkedlist_init(&list, (as_val *) as_integer_new(123), NULL);
 *	~~~~~~~~~~
 *
 *	Or you can create a new heap allocated list using `as_linkedlist_new()`:
 *
 *	~~~~~~~~~~{.c}
 *	as_list * list = as_linkedlist_new( (as_val *) as_integer_new(123), NULL);
 *	~~~~~~~~~~
 *
 *	When you are finished using the list, then you should release the list and
 *	associated resources, using `as_list_destroy()`:
 *	
 *	~~~~~~~~~~{.c}
 *	as_list_destroy(list);
 *	~~~~~~~~~~
 *
 *	@see as_list
 *
 *	@implements as_list
 */
typedef struct as_linkedlist_s {
	
	/**
	 *	The first value
	 */
	as_val * head;
	
	/**
	 *	The remaining list
	 */
	struct as_list_s * tail;

} as_linkedlist;

/******************************************************************************
 *	FUNCTIONS
 ******************************************************************************/

/**
 *	Initialize a stack allocated `as_list` as an `as_linkedlist`.
 *
 *	@param list		The list to initialize.
 *	@param head		The head value of the list.
 *	@param tail 	The tail of the list.
 *
 *	@return On success, the initialized list. Otherwise NULL.
 */
struct as_list_s * as_linkedlist_init(struct as_list_s * list, as_val * head, struct as_list_s * tail);

/**
 *	Create and initialize a heap allocated `as_list` as an `as_linkedlist`.
 *
 *	@param head		The head value of the list.
 *	@param tail 	The tail of the list.
 *
 *	@return On success, the new list. Otherwise NULL.
 */
struct as_list_s * as_linkedlist_new(as_val * head, struct as_list_s * tail);

/**
 *	Destroy the `as_linkedlist` and release resources.
 *
 *	~~~~~~~~~~{.c}
 *	as_linkedlist_destroy(list);
 *	~~~~~~~~~~
 *
 *	@param list	The list to destroy.
 */
void as_linkedlist_destroy(struct as_list_s * list);
