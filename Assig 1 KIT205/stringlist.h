#pragma once

typedef struct listNode{
	char *data;
	struct listNode *next;
} *ListNodePtr;

typedef struct list{
	ListNodePtr head;
} List;

List new_list();

void print_list(List *self);

void insert_at_front(List *self, char *data);

void insert_in_order(List *self, char *data);

void delete_list(List *self, char *data);

void destroy_list(List *self);

