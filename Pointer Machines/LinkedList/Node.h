#ifndef NODE_H
#define NODE_H

template<class K, class D>
class LinkedList;

template <class K, class D>
class Node
{
private:
	K key;
	D dato;
	Node<K,D>* siguiente;
	Node<K,D>* anterior;
public:
	Node(K p_key, D p_dato, Node<K,D> *sig = NULL );
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
	friend class LinkedList<K,D>;
};

#include "Node.inl"

#endif