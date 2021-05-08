#pragma once
#include <iostream>

using namespace std;

template <typename K>
class Item
{
private:
	K key;
public:
	
	Item()
	{};

	Item(K key) :
		key{ key } {};

	bool operator< (const Item<K>& other);
	bool operator== (const Item<K>& other);
};

template<typename K>
bool Item<K> :: operator<(const Item& other)
{
	return this->key < other.key;
}

template<typename K>
bool Item<K> :: operator==(const Item& other)
{
	return this->key == other.key;
}

template <typename K>
ostream& operator<<(ostream& os, Item<K>& o)
{
	os << o.key;

	return os;
}
