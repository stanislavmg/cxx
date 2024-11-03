//#include "forward_list.hpp"
#include <iostream>

//using namespace cnt;

// int tmain(void)
// {
// 	Forward_list<int> test;

// 	for (int i = 0; i < 10; ++i)
// 		test.push_front(i);
// 	test.reverse();
// 	for (int i = 0; i < 10; ++i){
// 		std::cout << test.front() << ' ';
// 		test.pop_front();
// 	}
// 	std::cout << std::endl;
// 	return 0;
// }

struct Node{
	int data;
	Node *next;
};

Node *mergelists(Node *first, Node *second)
{
	Node *head = nullptr;
	Node *i = nullptr;

	if (first->data < second->data)
		head = first;
	else
		head = second;
	i = head;
	while (first && second){
		if (first->data < second->data){
			i->next = first;
			first = first->next;
		}
		else{
			i->next = second;
			second = second->next;
		}
		i = i->next;
	}
	if (first)
		i = first;
	else 
		i = second;
	return head;
}

int main(void){

}