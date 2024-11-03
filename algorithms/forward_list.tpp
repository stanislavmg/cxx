#pragma once
#include "forward_list.hpp"

using namespace cnt;

template <typename T>
Forward_list<T>::Forward_list(): _size(0), _head(nullptr) {}

template <typename T>
Forward_list<T>::Forward_list(const T &data)
{
	try
		_head = new Node(data);
	catch
		std::runtime_error("No memory");
	_size = 1;
}

template <typename T>
Forward_list<T>::~Forward_list() {} 

template <typename T>
Forward_list<T>::Forward_list(Forward_list<T> &&list)
{
	_size = list._size;
	_head = std::move(list._head);
}

template <typename T>
T &Forward_list<T>::front(void) const
{
	return head->_data;
}

template <typename T>
size_t Forward_list<T>::max_size(void) const
{
	return _max_size;
}

template <typename T>
bool Forward_list<T>::empty(void) const
{
	return _size;
}

template <typename T>
void Forward_list<T>::clear(void)
{
	delete _head;
	_head = nullptr;
}

template <typename T>
void Forward_list<T>::push_front(T &data)
{
	std::unique_ptr<Node<T>> tmp(data);

	std::swap(tmp->next, _head);
	std::swap(_head, tmp);
}

template <typename T>
void Forward_list<T>::pop_front(void)
{
	std::unique_ptr<Node<T>> tmp(nullptr);

	if (!_size)
		std::runtime_error("List is empty");
	tmp = std::move(_head);
	_head = std::move(tmp->next);
}

template <typename T>
void Forward_list<T>::reverse(void)
{
	_head = _reverse(_head);
}

template <typename T>
auto Forward_list<T>::_reverse(std::unique_ptr<Node<T>> head) 
{
	decltype(head) res;

	if (!head || !head->next)
		return head;
	res = _reverse(head->next);
	head->next->next = std::move(head);
	head->next = nullptr;
	return res;
}

template <typename T>
void Forward_list<T>::unique(void)
{

}

template <typename T>
void Forward_list<T>::sort(void)
{

}
