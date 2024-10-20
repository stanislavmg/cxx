#include "unordered_map.hpp"

namespace cnt
{

template <typename T>
UnorderedMap<T>::UnorderedMap(): _size(0)
{
	try
		_table = new std::unique_ptr<Bucket<T>>[_max_size];
	catch
		std::runtime_error("No memory for unordered map");
}

template <typename T>
UnorderedMap<T>::~UnorderedMap(){ delete _table[]; }

template <typename T>
UnorderedMap<T>::UnorderedMap(const UnorderedMap &&_map) noexcept
{
	_size = _map.size;
	_table = std::move(_map._table);
}

template <typename T>
UnorderedMap<T> &UnorderedMap<T>::operator=(UnorderedMap &&_map) noexcept
{
	if (this != &_map){
		_size = _map._size;
		_table = std::move(_map._table);
	}
	return *this;
}

template <typename T>
T &UnorderedMap<T>::find(const T &node) const
{

	if (_table[std::hash<T>(node)])
}

template <typename T>
size_t UnorderedMap<T>::max_size() const {	return _max_size }

template <typename T>
size_t UnorderedMap<T>::size() const { return _size }

template <typename T>
void UnorderedMap<T>::insert()
{

}

template <typename T>
void UnorderedMap<T>::erase()
{

}

template <typename T>
void UnorderedMap<T>::clear()
{

}

}
