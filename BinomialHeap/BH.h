#ifndef BH_H
#define BH_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <string>

using namespace std;


template <typename T>
class BN;

template <typename T>
class BH
{

public:
	friend class BN<T>;
	
	BH();
	BH(const BH& other);
	BH(BH&& other);
	BH& operator=(const BH& other);
	~BH();

	void insert(T dato);
	T getMin();
	T extractMin();
	void deleteKey(T dato);
	void decreaseKey(T dato, T newDato);
	int size();
	bool isEmpty();
	void clear();
protected:
	BN<T>* findKey(T v);
	static BN<T>* unionH(BN<T>* heapA, BN<T>* heapB);
	static BN<T>* merge(BN<T>* heapA, BN<T>* heapB);
	static int order(BN<T>* heap);

private:
	BN<T> * head;
};

template <typename T>
class BN
{
public:
	friend class BH<T>;
	BN(T v, BN<T> * parent = nullptr);
	~BN();

	void addChild(BN<T>* child);
	BN<T>* find(T v);
	int size(int& i);
	
	void addTo(BH<T>* other);
private:
	T dato;
	BN<T> *bro, *child, * parent;
	int order;
};


#include "BH.inl"
#endif