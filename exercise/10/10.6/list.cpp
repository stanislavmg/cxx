#include "list.h"

List::List(int s)
{
	list_size = s;
	new_list = new list[list_size];
	num = 0;
}

List::~List(void)
{
	delete[] new_list;
}

void List::add(void *node)
{
	new_list[num].data = node;
	num++;
}

int List::isempty(void)
{
	if (!num)
	{
		std::cout << "list is empty" << std::endl;
		return (1);
	}
	else
		return (0);	

}

int List::isfull(void)
{
	if (num >= list_size)
	{
		std::cout << "list is full" << std::endl;
		return (1);
	}
	else
		return (0);
}

void *List::get_node(int index)
{
	int i;
	
	i = 0;
	while (++i < index)
		i++;
	return (new_list[i].data);
}
