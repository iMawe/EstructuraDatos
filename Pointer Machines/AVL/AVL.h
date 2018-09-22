#ifndef AVL_H
#define AVL_H

#include <iostream>
using namespace std;

template <class K,class D>
class AVL;

template<class K, class D>
class Node{
private: 
	D dato;
	K key;
	int h;
	Node<K,D>* p_child[2];
public:
	Node(const K k, const D d, Node<K,D>* children=NULL);
	virtual ~Node(){};

friend class AVL<K,D>;
};

template<class K, class D>
class AVL{
private:
	Node<K,D> *p_root;
public:
	AVL():p_root(NULL){};
	virtual ~AVL(){};

	void insert(const K &key, const D &dato);
	bool remove(K key);
	int max(int a, int b);
	int height(Node<K,D>* n);
	void turn_side(Node<K,D>** n, bool dir);
	void doble_turn_side(Node<K,D>** n, bool dir);
	void balanceo(Node<K,D>** n);
	void printARBOL();

private:
	
	bool insert(Node<K,D>** n, const K &key, const D &dato);
	void printARBOL(node<K,D> *n);

};

#include "AVL.inl"
#endif