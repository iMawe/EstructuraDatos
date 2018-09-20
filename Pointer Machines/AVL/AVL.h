#ifndef AVL_H
#define AVL_H

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
	Node(const K k, const D d, h=0, Node<K,D>* children=NULL);
	virtual ~Node();

friend class AVL<K,D>;
};

template<class K, class D>
class AVL{
private:
	Node<K,D> *p_root;
public:
	AVL():p_root(NULL){};
	virtual ~AVL();
	bool insert(Node<K,D>** n, K key, D dato);
	bool remove(K key);
	int height(Node<K,D>* n);
private:
	bool insert(K key, D dato);

};

#include "AVL.inl"
#endif