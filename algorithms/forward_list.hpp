#pragma once

#include <memory>
#include <stdexcept>



namespace cnt
{

template <typename T>
struct Node
{
	T	_data;
	Node<T> *next;
	Node(T &new_data): _data(new_data), next(nullptr) {}
};

template <typename T>
class Forward_list
{
	size_t _size;
	static const int _max_size = 100;
	std::unique_ptr<Node<T>> _head;
	auto _reverse(std::unique_ptr<Node<T>> head);
public:
	Forward_list();
	Forward_list(const T &data);
	~Forward_list();
	Forward_list(const Forward_list &list) = delete;
	Forward_list &operator=(Forward_list &list) = delete;
	Forward_list(Forward_list &&list);
	T &front(void) const;
	size_t max_size(void) const;
	bool empty(void) const;
	void clear(void);
	void push_front(T &data);
	void pop_front(void);
	void reverse(void);
	void unique(void);
	void sort(void);
};

#include "forward_list.tpp"
}