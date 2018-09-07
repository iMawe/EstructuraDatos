#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
#include <iostream>

template <class K, class D>
class LinkedList
{
public:
	Node<K,D>* p_head;
	Node<K,D>* p_last;
	Node<K,D>* sn;
	Node<K,D>* aux;

public:	
	LinkedList();
	LinkedList(const LinkedList & List);

	LinkedList & operator = (const LinkedList & List);

	~LinkedList();

	bool InsertFront(const K & p_key, const D & p_dato);

	void Insert(const K & p_key, const D & p_dato);
	
	bool InsertBack(const K & p_key, const D & p_dato);
	bool RemoveFront();
	bool RemoveBack();
	void Show();
	Node<K,D>* GetRaiz();
};

#include "LinkedList.inl"

#endif

