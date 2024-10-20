#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdlib.h>

struct list
{
	void *data;
	list *next;
};

class List
{
private:
	list *new_list;
	int list_size;
	int num;
public:
	List(int s = 0);
	~List(void);
	void add(void *node);
	int isempty(void);
	int isfull(void);
	void *get_node(int index);
};
#endif