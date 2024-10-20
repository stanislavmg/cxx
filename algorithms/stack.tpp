#include "stack.hpp"

namespace cnt
{
template <typename T>
Stack<T>::Stack(): _size(0), head(nullptr){}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
Stack<T>::Stack(Stack<T> &&_stack) noexcept: _size(_stack._size), head(std::move(_stack.head)){}

template <typename T>
Stack<T> &Stack<T>::operator=(Stack<T> &&_stack)
{
	if(this != &_stack){
		_size = _stack._size;
		head = std::move(_stack.head);
		_stack._size = 0;
	}
	return *this;
}

template <typename T>
void Stack<T>::push(T data)
{
	T new_max = data;
	T new_min = data;

	if (head){
		new_min = std::min(data, head->min);
		new_max = std::max(data, head->max);
	}
	auto new_node = std::make_unique<Node<T>>(data, new_min, new_max);
	new_node->next = std::move(head);
	head = std::move(new_node);
	++_size;
}

template <typename T>
T Stack<T>::pop()
{
	T data;

	if (!_size)
		throw std::runtime_error("Stack is empty");
	else{
		data = head->data;
		head = std::move(head->next);
		--_size;
	}
	return data;
}

template <typename T>
T Stack<T>::findmin() const
{
	if (!_size)
		throw std::runtime_error("Stack is empty");
	return head->min;
}

template <typename T>
T Stack<T>::findmax() const
{
	if (!_size)
		throw std::runtime_error("Stack is empty");
	return head->max;
}

template <typename T>
bool Stack<T>::is_empty() const
{
	return !_size;
}

template <typename T>
size_t Stack<T>::size() const
{
	return _size;
}

}
