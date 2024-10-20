#ifndef STACK_H
#define STACK_H

#include <memory>
#include <stdexcept>
#include <cstddef>

namespace cnt
{

template <typename T>
struct Node
{
	T	data;
	T	min;
	T	max;
	std::unique_ptr<Node<T>> next;
	Node(T value, T _min, T _max): data(value), min(_min), max(_max), next(nullptr) {}
};


template <typename T>
class Stack
{
	size_t _size;
	std::unique_ptr<Node<T>> head;
public:
	Stack();
	~Stack();
	Stack(Stack &_stack) = delete;
	Stack(Stack &&_stack) noexcept;
	Stack &operator=(Stack &&_stack);
	void operator=(const Stack &_stack) = delete;
	void push(T data);
	T pop();
	T findmin() const;
	T findmax() const;
	bool is_empty() const;
	size_t size() const;
};

}

#include "stack.tpp"

#endif