#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include <iostream>

template<class K, class D>
class LinkedList;

template <class K, class D>
class Node
{
public: 
	K key;
private:
	D dato;
	Node<K,D>* siguiente;
	Node<K,D>* anterior;
public:
	Node(){}

	Node(const K & p_key, const D & p_dato, Node<K,D> *sig = NULL );

	K GetKey();
	D GetDato();
	void  SetSiguiente(Node* p_node);
	Node* GetAnterior()
	{
		return anterior;
	}
	Node* GetSiguiente()
	{
		return siguiente;
	}
	~Node();
	void print();

friend class LinkedList<K,D>;
};

template <class K, class D>
class LinkedList
{
public:
	Node<K,D>* p_head;
private:
	Node<K,D>* p_last;
	Node<K,D>* sn;
	Node<K,D>* p_free;
	int idxfree = 0;

public:	
	LinkedList();

	LinkedList(const LinkedList<K,D>& List);

	LinkedList & operator = (const LinkedList & List);

	virtual ~LinkedList();

	void InsertFront(const K & p_key, const D & p_dato);
	void InsertBack(const K & p_key, const D & p_dato);

	//void Insert(const K & p_key, const D & p_dato);

	void RemoveFront();
	void RemoveBack();

	//void remove(const K & p_key, const D & p_dato);

	void Show();
	Node<K,D>* GetHead();
	
};

#include "LinkedList.inl"

#endif

