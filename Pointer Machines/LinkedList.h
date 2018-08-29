#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
#include <iostream>

template <class K, class D>
class LinkedList
{
public:
	Node<K,D>* raiz;

public:
	LinkedList();
	~LinkedList();

	bool InsertFront(K p_key, D p_dato);
	bool InsertBack(K p_key, D p_dato);
	bool RemoveFront();
	bool RemoveBack();
	//bool RemoveNode(Node<K,D>* n);
	void Show();
	Node<K,D>* GetRaiz();
};

#include "LinkedList.inl"

#endif

