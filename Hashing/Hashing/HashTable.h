#pragma once
#include <vector>
#include "HashFunction.h"

// Pair structure. Stores key and value
template<typename A, typename B>
struct Pair {
	A First;
	B Second;
};
// ----------------------------------------------------------------------

// List for each hash table index. Solution for collisions
template<typename KeyType, typename T>
struct HashTableIndex {
	~HashTableIndex() {
		list.clear();
	}

	Pair<KeyType, T> FindPair(KeyType key) {
		for (auto iter : list) {
			if (iter->First == key) {
				return *iter;
			}
		}
	}

	void AddPair(KeyType key, T value) {
		list.push_back(new Pair<KeyType, T>({ key, value }) );
	}

private:
	std::vector<Pair<KeyType, T>*> list = std::vector<Pair<KeyType, T>*>();
};
// ----------------------------------------------------------------------

// Hash table
template<typename T>
class HashTable
{
public:
	// Constructor
	HashTable(unsigned int size) {
		m_size = size;
		m_data = new HashTableIndex<unsigned int, T>[size];
	}
	// Destructor
	~HashTable() { delete[] m_data; }

	// Access operators
	T operator [] (const char* key) {
		auto hashedKey = HashFunction::hash(key, strlen(key));
		return (T)m_data[hashedKey % m_size].FindPair(hashedKey).Second;
	}
	const T operator [] (const char* key) const {
		auto hashedKey = HashFunction::hash(key, strlen(key));
		return (const T)m_data[hashedKey % m_size].FindPair(hashedKey).Second;
	}

	// Add value to hash table
	unsigned int Add(const char* key, T value);


private:
	HashTableIndex<unsigned int, T>* m_data;
	unsigned int m_size;
};


template<typename T>
inline unsigned int HashTable<T>::Add(const char* key, T value)
{
	// Get the hash key
	auto hashedKey = HashFunction::hash(key, strlen(key));
	// Use modulos to fit hash to array and add the key and value to that index
	m_data[hashedKey % m_size].AddPair(hashedKey, value);

	// For display purposes*
	return hashedKey;
}

// ----------------------------------------------------------------------