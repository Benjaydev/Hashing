#pragma once
#include <vector>
#include "HashFunction.h"

// Pair structure
template<typename A, typename B>
struct Pair {
	A First;
	B Second;
};

// List for each hash table index
template<typename KeyType, typename T>
struct HashTableIndex {
	std::vector<Pair<KeyType, T*>> list = std::vector<Pair<KeyType, T*>>();

	Pair<KeyType, T*> FindPair(KeyType key) {
		for (auto& iter : list) {
			if (iter->First == key) {
				return iter;
			}
		}
	}

	void AddPair(KeyType key, T value) {
		list.push_back({ key, value });
	}

};


// Hash table
template<typename T>
class HashTable
{
public:
	HashTable(unsigned int size) : m_size(size), m_data(new HashTableIndex<unsigned int, T>[size]) {}
	~HashTable() { delete[] m_data; }

	T& operator [] (const unsigned int& key) {
		//auto hashedKey = HashFunction::defaultHash(key) % m_size;
		return m_data->FindPair(key)->Second;
	}

	const T& operator [] (const unsigned int& key) const {
		//auto hashedKey = HashFunction::defaultHash(key) % m_size;
		return m_data->FindPair(key)->Second;
	}

	void Add(const char* key, T value);


private:
	HashTableIndex<unsigned int, T>* m_data;
	unsigned int m_size;
};


template<typename T>
inline void HashTable<T>::Add(const char* key, T value)
{
	auto hashedKey = HashFunction::defaultHash(key, sizeof(key)/sizeof(char));
	m_data[hashedKey % m_size].AddPair(hashedKey, value);
}

// ----------------------------------------------------------------------