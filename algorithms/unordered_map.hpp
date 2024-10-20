#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <cstddef>
#include <memory>
#include <map>

namespace cnt
{

template <typename T>
struct Bucket
{
	T	data;
	std::unique_ptr<Bucket<T>> next;
	Bucket(T _data): data(_data), next(nullptr) {}
};

template <typename T>
class UnorderedMap
{
	size_t _size;
	static const size_t _max_size = 100;
	std::unique_ptr<Bucket<T>> *_table;
public:
	UnorderedMap();
	~UnorderedMap();
	UnorderedMap(const UnorderedMap &_map) = delete;
	UnorderedMap(const UnorderedMap &&_map) noexcept;
	UnorderedMap &operator=(const UnorderedMap &_map) = delete;
	UnorderedMap &operator=(UnorderedMap &&_map) noexcept;
	T &find(const T &node) const;
	size_t max_size() const;
	size_t size() const;
	void insert();
	void erase();
	void clear();
};

}

#include "unordered_map.tpp"

#endif